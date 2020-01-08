#include "State.h"
#include <vector>
#include <string.h>
#include <iostream>

class StateMachine {
public:
	StateMachine() {};
	StateMachine(std::vector<State*>* stateArray, char* inputString, bool flag1) {
		stateArrPtr = stateArray;
		inputStr = inputString;
		vFlag = flag1;
	}
	bool run();

	std::vector<State*>* stateArrPtr;
	std::map<std::string, std::string>::iterator mapEnd;
	char* inputStr;
	char c;
	std::string str;
	int ctr = 0;
	bool incorrectTransitionFlag = false;
	bool vFlag = false;
};
