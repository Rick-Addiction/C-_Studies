#include "Utils.h"

void AskForOptions(string question, optionsToQuestion*options, string* answer, int numOptions) {

	
	bool error;
	do {
		*answer = "";
		cout << " \n" << question;
		cout << "\n ";
		for (int i = 0; i < numOptions; ++i) {
			cout << "\n " << options[i].index << " - " << options[i].question << " \n";
		}

		cout << "\n What do you want? ";
		cin >> *answer;

		error = true;
		for (int i = 0; i < numOptions; ++i) {
			if (*answer == options[i].index) {
				error = false;
				break;
			}
		}

		if (error) {
			printError();
			cout << "\n You've typed a wrong option. Try again.\n\n";
		}		
		
	} while (error);
}

void AskForValues(string question, valuesToQuestion* valuesToChange, int numValuesToChange) {
	
	cout << "\n" << question <<"\n" ;
	for (int i = 0; i < numValuesToChange; i++) {
		bool error;
		string valueTyped;
		do {
			cout << valuesToChange[i].name << ": ";
			cin >> valueTyped;
			
			if (!isNumber(valueTyped)) {
				printError();
				cout << "\n You didn't type a number. Try Again.\n\n";
				error = true;
			}
			else if (std::stof(valueTyped) <= 0) {
				printError();
				cout << "\n You've typed a number less or equals to 0. Try Again.\n\n";
				error = true;
			}
			else {
				error = false;
				valuesToChange[i].value = std::stof(valueTyped);
			}
			
		} while (error);
	}

}


bool isNumber(const std::string& s)
{
	return(strspn(s.c_str(), "-.0123456789") == s.size());
}

void printError() {
	cout << "\n";
	cout << "  ___ _ __ _ __ ___  _ __ \n";
	cout << " / _ \\ '__| '__/ _ \\| '__|\n";
	cout << "|  __/| | | | | (_) | | \n";
	cout << " \\___||_| |_|  \\___/|_|\n";

}