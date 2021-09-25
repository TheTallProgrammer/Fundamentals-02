/* 
Name:     		Gia Rivera
Date: 			Feb 13 2021
Assignment #:	classWork22
Status: 		Completed
Language:		C++
-------------------------------------------------------------------------
Comments
Find what to do based on user's input: 
	C - ChickenBooger, B - BeefBooger, P - PorkBooger, E - Exit
Check will be done in a function and the function will return the message
*/

#include <iostream>				// for cin, cout, endl
#include <string>
using namespace std;

// declaration of function prototypes
char getData(string);
string checkCommand(char);

int main()
{
	// declaration of variables
	char userIn;
	string message;
	
	// initialize variables
	userIn = getData("Enter C for a ChickenBooger, B for BeefBooger, P for PorkBooger, or E to Exit ");
	message = checkCommand(toupper(userIn));
	
	// display message based on user's choice
	cout << message << endl;

    system("PAUSE");
    return 0;
} // end of main()

string checkCommand(char userIn)
{
	if (userIn == 'C')
	{
		return "That's a Chickenbooger for you!\n";
	}
	else if (userIn == 'B')
	{
		return "That's a Beefbooger for you!\n";
	}
	else if (userIn == 'P')
	{
		return "That's a Porkbooger for you!\n";
	}
	else if (userIn == 'E')
	{
		return "Bye for now!\n";
	}
	else
	{
		return "Invalid entry, please run again!\n";
	}
}

// getData() receives input from the user
char getData(string prompt)
{
	char value;
	
	cout << prompt;
	cin >> value;
	
	return value;	
} // end of getData()
