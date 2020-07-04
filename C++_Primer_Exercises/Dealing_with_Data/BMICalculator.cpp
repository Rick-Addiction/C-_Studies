#include "BMICalculator.h"
#include "Utils.h"




/*EXERCISE 2: Write a short program that asks for your height in feet and inches and your weight
	in pounds. (Use three variables to store the information.) Have the program report
	your body mass index(BMI).To calculate the BMI, first convert your height in feet
	and inches to your height in inches(1 foot = 12 inches).Then convert your height
	in inches to your height in meters by multiplying by 0.0254.Then convert your
	weight in pounds into your mass in kilograms by dividing by 2.2.Finally, compute
	your BMI by dividing your mass in kilograms by the square of your height in
	meters.Use symbolic constants to represent the various conversion factors.

	TEST
	Values: Option 1;
			Height -> 5 feet and 10.8661 inches;
			Weight -> 185.188 pounds
	Result: Your BMI: 25.9804
	*/
void BMICalculator()
{
	float heightInMeters;
	float weightInKg;


	cout << "\n ********************************";
	cout << "\n ***Body Mass Index Calcutator***";
	cout << "\n ******************************** \n \n";
		
	requestHeight(&heightInMeters);
	requestWeight(&weightInKg);	
	BMICalculation(&heightInMeters, &weightInKg);

}

void requestHeight(float *heightInMeters) {
	const int InchesForEachFoot = 12;
	const float MeterForEachInch = 0.0254f;

	string calcutationType;
	optionsToQuestion optionsQuestion[] = { {"1","Feet and Inches" }, {"2","Meters"} };


	AskForOptions("Enter the respective number of what kind of unit of length you prefer? ",
		optionsQuestion,
		&calcutationType,
		2);

	if (calcutationType == "1") {
		valuesToQuestion valuesToResponse[] = { { "Feet",NULL }, { "Inches",NULL } };

		AskForValues("What's your height in Feet and Inches?", valuesToResponse,2);

		*heightInMeters = (valuesToResponse[0].value * InchesForEachFoot + valuesToResponse[1].value) * MeterForEachInch;
	}
	else if (calcutationType == "2") {
		valuesToQuestion valuesToResponse[] = { {"Meters",NULL} };

		AskForValues("What's your height in meters?", valuesToResponse,1);

		*heightInMeters = valuesToResponse[0].value;
	}

}

void requestWeight(float * weightInKg) {
	const float KgForEachPound = 2.2f;
	string calcutationType;

	optionsToQuestion optionsQuestion[] = { {"1","Pounds"},{"2","Kilograms"} };

	AskForOptions("Enter the respective number of the kind of unit of weight you prefer? ",
		optionsQuestion,
		&calcutationType,
		2);

	if (calcutationType == "1") {
		valuesToQuestion valuesToResponse[] = { {"Pounds",NULL} };

		AskForValues("What is your weight in pounds?", valuesToResponse,1);

		*weightInKg = valuesToResponse[0].value / KgForEachPound;
	}
	else if (calcutationType == "2") {
		valuesToQuestion valuesToResponse[] = { {"Kilograms",NULL} };

		AskForValues("What's your weight in Kilograms", valuesToResponse,1);

		*weightInKg = valuesToResponse[0].value;
	}
}

void BMICalculation(float* heightInMeters, float* weightInKg) {
	
	float bmi = *weightInKg / (*heightInMeters * *heightInMeters);
	cout << "\n Your BMI: " << bmi << "\n\n";
	cout << "#############################################################################\n\n";

}