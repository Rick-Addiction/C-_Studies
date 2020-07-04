#include "Utils.h"
#include "BMICalculator.h"
#include "SecondsToHoursMinutesAndSecondsConverter.h"

using namespace std;

int main()
{
	string exerciseNumber ="";
	optionsToQuestion optionsQuestion[] = { {"1","Body Mass Index Calcutation" },
											{"2","Seconds To Hours, Minutes and Seconds"},
											{"q","Exit the program"}
											};
	while (exerciseNumber != "q") {

		AskForOptions("Enter the respective exercise option to execute it? ",
			optionsQuestion,
			&exerciseNumber,
			3);

		if (exerciseNumber == "1")
			BMICalculator();
		else if (exerciseNumber == "2")
			SecondsToHoursMinutesAndSecondsConverter();		
	}

	return 0;
	
}


