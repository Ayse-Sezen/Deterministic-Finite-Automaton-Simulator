#include "StateMachine.h"

bool StateMachine::run() {

  // declare iterator to transition maps
  std::map<std::string, std::string>::iterator mapIt;

  // declare a char to store chars taken from input string
  char* i = new char[0];
  
  // declare int iterator for getting chars from input string
  int j = 0;
  
  // declare a char* to store the cstring returned from searches through map
  char* nextState = new char[0];
  
  // Find the start state
  std::vector<State*>::iterator arrIt = (*stateArrPtr).begin();
  
  // while we haven't found the start state yet, keep looping
  while (!(*arrIt)->getStartFlag()) { 
    arrIt++;
  }
  
  // save off iterator to end of map for checking case where transition is not found in the map
  //mapEnd = (*arrIt)->transitionMap.end(); /***************** You don't need this **********/
  
  if(vFlag){
    std::cout << "Transitions: " << std::endl;
    std::cout << "State\tInput\tNextState" << std::endl;
    std::cout << (*arrIt)->stateNumber << "\t";
  }
  
  // once we find the start state, we'll start the loop to process transitions against the input string and traverse throughout
  // the DFA
  while (inputStr[ctr] != NULL) { 

    mapEnd = (*arrIt)->transitionMap.end();
    
    // get an input symbol from the input
    c = inputStr[ctr];
    ctr++;
    str.push_back(c);
    
    if(vFlag){
      // print the input symbol
      std::cout << str << "\t";
    }
    
    mapIt = (*arrIt)->transitionMap.find(str); // find pair containing next state and pass iterator to it to mapIt
    
    // if we could not find the transition in the map (possibly because the state numbers in the transitions
    // did not match with any of the state numbers of the state objects) then input transitions were wrong and
    // we return to main to print an error message
    if (mapIt == mapEnd) {
      incorrectTransitionFlag = true;
      return false;
    }
    
    std::string returnedValue = (*mapIt).second; // get the returned value
    nextState = new char[returnedValue.length() + 1];
    strcpy(nextState, returnedValue.c_str()); // convert from string to c string
    str.pop_back();
    
    if(vFlag){
      std::cout << returnedValue << std::endl;
      if(inputStr[ctr] != NULL){
	std::cout << returnedValue << "\t"; // we print this twice because this will be the first state for the next transition
      }
    }
    
    // reset the state array iterator
    arrIt = (*stateArrPtr).begin();
    
    // find the next state. We keep incrementing the array iterator until we do.
    // That way, on the next iteration of this while loop, arrIt will already be pointing to the next state
    while (strcmp(nextState, (*arrIt)->stateNumber) != 0){
      arrIt++;
    }
  }
  
  if(vFlag){
    std::cout << std::endl;
    std::cout << std::endl;
  }
  
  // Once at the end of the string, check to see if you're in an accept state, and if you are, return true
  // Otherwise, return false
  if ((*arrIt)->getAcceptFlag()) {
    return true;
  }
  else {
    return false;
  }
  
}
