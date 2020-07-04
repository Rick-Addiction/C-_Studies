#include <iostream> 
#include <string>

using namespace std;

void AskForOptions(string question, string* options, string* answer, int numOptions);
bool isInteger(const std::string& s);
void printError();

void AskForOptions(string question, string* options, string* answer, int numOptions) {

	*answer = "";
	do {
		cout << question;
		cout << "\n ";
		for (int i = 0; i < numOptions; ++i) {
			cout << "\n " << i + 1 << " - " << options[i] << " \n";
		}

		cout << "\n What do you want? ";
		cin >> *answer;


		if (!isInteger(*answer)) {

			printError();
			cout << "\n You didn't type a number. Try Again.\n\n";
			cout << "#############################################################################\n\n";
			*answer = "";
		}
		else if (std::stoi(*answer, 0, 10) < 1 || std::stoi(*answer, 0, 10) > numOptions) {

			printError();
			cout << "\n You've typed a number that is not one of the options. Try Again.\n\n";
			cout << "#############################################################################\n\n";
			*answer = "";
		}


	} while (*answer == "");
}

bool isInteger(const std::string& s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char* p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}

void printError() {
	cout << "\n";
	cout << "  ___ _ __ _ __ ___  _ __ \n";
	cout << " / _ \\ '__| '__/ _ \\| '__|\n";
	cout << "|  __/| | | | | (_) | | \n";
	cout << " \\___||_| |_|  \\___/|_|\n";

}