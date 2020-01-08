#include "MessageCenter.h"

void MessageCenter::printVFlagMsg(){
  if(vFlag){
    std::cout << "Welcome to the DFA simulator. This simulator will take a dfa definition from the .dfa " << std::endl;
    std::cout << "file provided on the command line and the input string from the input file provided on the " << std::endl;
    std::cout << "command line and simulate the dfa processing the input string, printing ACCEPTED or REJECTED " << std::endl;
    std::cout << "depending on whether or not the dfa accepted the string." << std::endl;
    std::cout << std::endl;
    std::cout << "For help with the DFA simulator or to see an example of how to write the .dra file or the input " << std::endl;
    std::cout << "you provide to the simulator, please use -h at the command line when running the simulator." << std::endl;
    std::cout << std::endl;
  }
}



void MessageCenter::printHFlagMsg(){
  if(hFlag){
    std::cout << "Welcome to the help center. The following information will detail how to write the definition of the dfa " << std::endl;
    std::cout << "in the .dfa file and the input string in the input file prior to supplementing those files to the simulator." << std::endl;
    std::cout << std::endl;
    std::cout << "*** How to define the DFA in the .dfa file ***" << std::endl;
    std::cout << "The DFA simulator is case sensistive and uses the getline() function and the space delimiter \" \" to parse " << std::endl;
    std::cout << "the .dfa file. Therefore it is very important to follow the following format when writing the definition of " << std::endl;
    std::cout << "the DFA in the .dfa file to ensure that the dfa definition is read in properly by the simulator." << std::endl;
    std::cout << "The DFA should be defined as follows: " << std::endl;
    std::cout << "State (symbol) (symbol) ..." << std::endl;
    std::cout << "Alphabet (symbol) (symbol) ..." << std::endl;
    std::cout << "Transition (state symbol) (alphabet symbol) (state symbol)" << std::endl;
    std::cout << "." << std::endl;
    std::cout << "." << std::endl;
    std::cout << "." << std::endl;
    std::cout << "Start (state symbol)" << std::endl;
    std::cout << "Accept (state symbol) (state symbol) ..." << std::endl;
    std::cout << std::endl;
    std::cout << "The set of states should begin with the word 'State' as shown above, followed by the symbol(s) representing " << std::endl;
    std::cout << "the state names. You can include as many states as you'd like. You can also use any character or " << std::endl;
    std::cout << "of characters to represent the state names." << std::endl;
    std::cout << "The alphabet should begin with the word 'Alphabet' as shown above and be followed by single character " << std::endl;
    std::cout << "symbols representing the alphabet. You may have as many single character symbols representing the " << std::endl;
    std::cout << "alphabet as you'd like." << std::endl;
    std::cout << std::endl;
    std::cout << "For the transition functions, you may have as many transition functions as you'd like. Transition functions " << std::endl;
    std::cout << "should start with the word 'Transition' and should be followed by a state name that you have previously " << std::endl;
    std::cout << "defined in the set of states, then an alphabet symbol that you've previously defined in the alphabet set, " << std::endl;
    std::cout << "then the name of another previously defined state. WARNING: If you put symbols that do not match any of " << std::endl;
    std::cout << "the previously defined state names or alphabet symbols, the simulator will stop processing the input " << std::endl;
    std::cout << "and display an error message." << std::endl;
    std::cout << std::endl;
    std::cout << "The start state definition should begin with the word 'Start' and be followed by a previously defined " << std::endl;
    std::cout << "state symbol. Please only define one state as the start state." << std::endl;
    std::cout << std::endl;
    std::cout << "The accept state definition should begin with the word 'Accept' and be followed by previously defined " << std::endl;
    std::cout << "state names. You can designate as many states as you'd like to be an accept state." << std::endl;
    std::cout << std::endl;
    std::cout << "Here is an example DFA definition: " << std::endl;
    std::cout << std::endl;
    std::cout << "State 1 2" << std::endl;
    std::cout << "Alphabet 0 1" << std::endl;
    std::cout << "Transition 1 0 1" << std::endl;
    std::cout << "Transition 1 1 2" << std::endl;
    std::cout << "Transition 2 1 1" << std::endl;
    std::cout << "Transition 2 0 2" << std::endl;
    std::cout << "Start 1" << std::endl;
    std::cout << "Accept 2" << std::endl;
    std::cout << std::endl;
    std::cout << "The input file should simply be a file containing only the input string at the top, without any new lines." << std::endl;
    std::cout << std::endl;
    std::cout << "*** IMPORTANT: Do not leave a blank newline at the end of the .dfa file or the input file. This will cause a seg fault ***" << std::endl;
  }
}
