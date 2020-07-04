#ifndef UTILS_H    
#define UTILS_H

#include <iostream> 
#include <string>

using namespace std;

struct optionsToQuestion {
	string index;
	string question;
};

struct valuesToQuestion {
	string name;
	float value;
};


void AskForValues(string question, valuesToQuestion* valuesToChange, int numValuesToChange);
void AskForOptions(string question, optionsToQuestion *options, string* answer, int numOptions);
bool isNumber(const std::string& s);
void printError();

#endif