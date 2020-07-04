#include "SecondsToHoursMinutesAndSecondsConverter.h"


using namespace std;

/*
EXERCISE 4: Write a program that asks the user to enter the number of seconds as an integer
value (use type long, or, if available, long long) and that then displays the equivalent time in days,
hours, minutes,and seconds. Use symbolic constants to represent	the number of hours in the day, the
number of minutes in an hour,and the number	of seconds in a minute.The output should look like this:


TEST
Value: 31600000
Result: 31600000 seconds = 365 days, 17 hours, 46 minutes, 40 seconds
*/
void SecondsToHoursMinutesAndSecondsConverter()
{
	const int hoursInADay = 24;
	const int minutesInAHour = 60;
	const int secondsInAMinute = 60;

	long long numSeconds;
	long days;
	long hours;
	long minutes;
	long seconds;

	cout << "Enter the number of seconds: ";
	cin >> numSeconds;

	days = numSeconds / (hoursInADay * minutesInAHour * secondsInAMinute);
	hours = (numSeconds % (hoursInADay * minutesInAHour * secondsInAMinute)) / (minutesInAHour * secondsInAMinute);
	minutes = (numSeconds % (minutesInAHour * secondsInAMinute)) / (secondsInAMinute);
	seconds = (numSeconds % secondsInAMinute);

	cout << "\n" << numSeconds << " seconds = " << days << " days," << hours << " hours," << minutes << " minutes," << seconds << " seconds \n \n";
}
