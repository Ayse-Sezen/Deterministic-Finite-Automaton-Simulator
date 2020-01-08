#include <map>
#include <string>


class State {
public:
	State() {};
	State(char* cstr) {
		// initialize the state's number
		stateNumber = cstr;
	}
	bool getStartFlag() {
		return startFlag;
	}

	bool getAcceptFlag() {
		return acceptFlag;
	}

	void setStartFlag(bool flag) {
		startFlag = flag;
	}

	void setAcceptFlag(bool flag) {
		acceptFlag = flag;
	}

	//std::map<char*, char*> transitionMap;
	std::map<std::string, std::string> transitionMap;

	bool startFlag = false;
	bool acceptFlag = false;
	char* stateNumber;

};