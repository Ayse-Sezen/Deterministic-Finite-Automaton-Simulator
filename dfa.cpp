#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include "StateMachine.h"
#include "MessageCenter.h"
#include <string>

int main(int argc, char** argv) {
// declare strings which we'll use for matching later
  char stateStr[] = "State";
  char alphaStr[] = "Alphabet";
  char tranStr[] = "Transition";
  char startStr[] = "Start";
  char acceptStr[] = "Accept";
  
  // get dfa string from second command line arg, the dfa file
  std::ifstream ifs(argv[2], std::ifstream::in);

  // set flags for -v and -h (help options) to false
  bool vFlag = false;
  bool hFlag = false;
  int argCtr = 0;

  // strings for -v and -h for matching against args
  char vStr[] = "-v";
  char hStr[] = "-h";
  
  // while we haven't reached the end of the command line arguments
  while(argCtr < argc){
	  // if user entered -v on command line, set vFlag to true to trigger -v help option to be displayed on screen
    if(strcmp(vStr, argv[argCtr]) == 0){
      vFlag = true;
    }
    
	// if user entered -h on command line, set hFlag to true to trigger -h help option to be displayed on screen
    if(strcmp(hStr, argv[argCtr]) == 0){
      hFlag = true;
    }

	// if no -v or -h was found, continue searching cmd line until end
    argCtr++;
  }
  
  // create MessageCenter obj initialized with vFlag and hFlag
  MessageCenter messages(vFlag, hFlag);

  // if vFlag was true, messages obj will print vFlag message (help message for the simulator)
  messages.printVFlagMsg();

  // if hFlag was true, messages obj will print hFlag message (help message for the simualtor)
  messages.printHFlagMsg();
  
  std::vector<State*> stateArr; // vector of ptrs to state objs
  std::vector<char*> alphaArr; // vector of cstrings
  
  std::string str;
  std::string input;
  char* inputStr;
  char* cstr = new char[0];
  char* tok;
  char* tok2;

  bool stateFlag = false;
  bool alphaFlag = false;
  bool startFlag = false;
  bool acceptFlag = false;
  
  // create iterator for stateArr to be used in loop
  std::vector<State*>::iterator it;

  if(vFlag){
    std::cout << "DFA Definition: " << std::endl;
  }
  
  // this while loop will iterator through the .dfa file supplied at the cmd line
  // and will parse the dfa definition, building the dfa in the stateArr and alphaArr while
  // checking for errors in the definition.
  while(!ifs.eof()){ // while we haven't reached the end of the file...
    it = stateArr.begin(); // reset the iterator for stateArr
    getline(ifs, str); // get line from definition in .dfa file
    
    if(vFlag){ // if vFlag was set to true, dfa definition will be printed to screen one line at a time
      std::cout << str << std::endl;
    }
    
    cstr = new char[str.length() + 1]; // create a cstring out of line from .dfa file
    std::strcpy(cstr, str.c_str());
    tok = strtok(cstr, " "); // tokenize the cstr using " " blankspace as the delimiter. This gets first word in str and tokenizes it.
    
	// now we start comparing the first word from str (which is now in tok) to various strings to see which part of definition we have reached.
	// Depending on what part of definition we reached, we will perform different operations.

	// if first word was 'State'...
	if (std::strcmp(tok, stateStr) == 0) {
		// get each of the states on the rest of the line and push them back into the stateArr
		if (!stateFlag) {
			tok = strtok(NULL, " ");
			while (tok != NULL) {
				stateArr.push_back(new State(tok)); // creating an array of pointers to state objs that are initialized w/their #s
				tok = strtok(NULL, " ");
			}

			// reset iterator
			it = stateArr.begin();

		}
		else {
			// error message
			std::cout << "Error: More than one set of states was defined in the .dfa file. Please change .dfa file to have all " << std::endl;
			std::cout << "states on one line, with no repeat names for states, and try running the simulator again." << std::endl;
			std::cout << "Exiting DFA simulator..." << std::endl;
			return 0;
		}

		stateFlag = true;
	}
	// if first word was 'Alphabet'...
    else if (std::strcmp(tok, alphaStr) == 0) {
		// parse rest of string to get the alphabet of the dfa and store in alphaArr
		if (!alphaFlag) {
			tok = strtok(NULL, " ");
			while (tok != NULL) {
				alphaArr.push_back(tok);
				tok = strtok(NULL, " ");
			}
		}
      else{
		// error message
		std::cout << "Error: More than one set of alphabet symbols was defined in the .dfa file. Please change the .dfa " << std::endl;
		std::cout << "file to have all symbols belonging to the alphabet on one line following the word 'Alphabet', and try " << std::endl;
		std::cout << "running the simulator again." << std::endl;
		std::cout << "Exiting DFA simulator..." << std::endl;
		return 0;
      }
      alphaFlag = true;
    }
	// if first word was 'Transition'...
    else if (std::strcmp(tok, tranStr) == 0) {
	// since each state obj has its own map to store transitions, 
	// we parse the string to get the transition, then go through stateArr
	// to find the state to whom the transition belongs
	// and store the transition in its map.
      tok = strtok(NULL, " ");
      while (tok != NULL) {
	// Push back maps into states
	// the first token is the state we're starting from, so find that state
	while (std::strcmp(tok, (*it)->stateNumber) != 0) {
	  if(it == (stateArr.end() - 1)){
	    std::cout << "Error: A state listed in one of the transition functions was not previously defined in the set " << std::endl;
	    std::cout << "of states. Please change the .dfa file to correct that transition and try running the simulator " << std::endl;
	    std::cout << "again." << std::endl;
	    std::cout << "Exiting DFA simulator..." << std::endl;
	    return 0;
	  }
	  else{
	    it++;
	  }
	}
	
	
	// once we've found that state, get the next two tokens (the input alpha symbol and next state) and put in this state's
	// map
	tok = strtok(NULL, " "); // get input alpha symbol
	std::string tokstr(tok); // convert from c string to a string
	tok2 = strtok(NULL, " "); // get next state
	std::string tokstr2(tok2); // convert from c string to a string
	
	// store transition function into state's transition map
	(*it)->transitionMap[tokstr] = tokstr2; 
	tok = strtok(NULL, " ");
      }
    }
    else if (std::strcmp(tok, startStr) == 0) {
      tok = strtok(NULL, " ");
      while (tok != NULL) {
	// Go in and turn on the start state flag in the start state 
	while (std::strcmp(tok, (*it)->stateNumber) != 0) {
	  it++;
	}
	
	// once we find our start state, set it's flag
	(*it)->setStartFlag(true);
	
	tok = strtok(NULL, " ");
      }
    }
	else if (std::strcmp(tok, acceptStr) == 0) {
		if (!acceptFlag) {
			tok = strtok(NULL, " ");
			while (tok != NULL) {
				// Go in and label the accept states
				while (std::strcmp(tok, (*it)->stateNumber) != 0) {
					it++;
				}

				// set accept flag. Start and accept flags are used to keep track of which state the transition
				// is coming from and where it's going to. 
				(*it)->setAcceptFlag(true);

				// reset iterator in case there's more than one accept state we need to find
				it = stateArr.begin();

				tok = strtok(NULL, " ");
			}
		}
		else {
			std::cout << "Error: More than one set of accept states was defined in the .dfa file. Please put all accept states " << std::endl;
			std::cout << "on one line in the .dfa file and then try running the simulator again." << std::endl;
			std::cout << "Exiting DFA simulator..." << std::endl;
			return 0;
		}
		acceptFlag = true;
	}
    else {
      // default case where the first token didn't match any of the options
      // we send an error to the user telling them that they input the values incorrectly
      std::cout << "Invalid input found in .dfa file, please change input in .dfa file and run simulator again." << std::endl;
      std::cout << "Exiting DFA simulator..." << std::endl;
      return 0;
    }
  }

  while(getline(std::cin, input)){
    inputStr = new char[input.length() + 1];
    std::strcpy(inputStr, input.c_str());
    
    if(vFlag) {
      std::cout << std::endl;
    }
    
    // Once all of the states have been initialized, we now run the State Machine
    StateMachine stateMachine(&stateArr, inputStr, vFlag);
    
	// once state machine finishes running, it will return a bool
	// which lets us know whether or not the input string of characters to
	// the dfa was accepted by the dfa or rejected.
    bool result = stateMachine.run();
    
    if (result) {
      std::cout << inputStr << " : ACCEPTED" << std::endl;
    }
    else{
		if (stateMachine.incorrectTransitionFlag) {
			std::cout << "Error: One of the transition functions defined in the .dfa file is invalid. Please check " << std::endl;
			std::cout << "that the alphabet symbols and the next states in the transition functions are previously " << std::endl;
			std::cout << "defined symbols and states in the set of alphabet symbols and set of states." << std::endl;
			std::cout << "Exiting the DFA simulator..." << std::endl;
			return 0;
		}
		else {
			std::cout << inputStr << " : REJECTED" << std::endl;
		}
    }
  }
  
  return 0;
  
}
