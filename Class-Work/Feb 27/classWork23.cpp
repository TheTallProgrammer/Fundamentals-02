/* 
Name:     		Gia Rivera
Date: 			Feb 27 2021
Assignment #:	classWork23
Status: 		Completed
Language:		C++
-------------------------------------------------------------------------
Comments
Accepts integer seconds
converts to hours, minutes, and seconds
Ex:
	sec 70
	output = 1 min 10 sec
*/

#include <iostream>				// for cin, cout, endl
#include <string>
using namespace std;

// declaration of function prototypes
int getData(string);
void convertSeconds(int, int &, int &, int &);

int main()
{
	// declaration of variables
	int userSeconds;
	int hours;
	int minutes;
	int seconds;
	
	// get integer seconds from user, then convert and display in hours, minutes, seconds
	string prompt = "Please enter an integer number of seconds: ";
	
	userSeconds = getData(prompt);
	
	convertSeconds(userSeconds, hours, minutes, seconds);
	
	cout << "hours: " << hours << " minutes: " << minutes << " seconds: " << seconds << endl;

    system("PAUSE");
    return 0;
} // end of main()

// convertSeconds() takes in a number of integer seconds and returns via pointers
// hours, minutes, seconds
void convertSeconds(int secondsIn, int &hours, int &minutes, int &seconds)
{
	int minutesIn;

	seconds = secondsIn % 60;
	minutesIn = secondsIn / 60;
	minutes = minutesIn % 60;
	hours = minutesIn / 60;
} // end of convertSeconds()

// getData() uses a prompt to provoke and return user input
int getData(string prompt)
{
	int value;
	
	cout << prompt;
	cin >> value;
	
	return value;	
} // end of getData()
