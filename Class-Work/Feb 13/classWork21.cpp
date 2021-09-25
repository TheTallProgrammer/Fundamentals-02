/* 
Name:     		Gia Rivera
Date: 			Feb 13 2021
Assignment #:	classWork21
Status: 		Completed
Language:		C++
-------------------------------------------------------------------------
Comments
Find what to do based on user's input: 
	C - ChickenBooger, B - BeefBooger, P - PorkBooger, E - Exit
*/

#include <iostream>				// for cin, cout, endl
#include <string>
using namespace std;

// declaration of function prototypes
char getData(string);

int main()
{
	// declaration of variables
	char userIn;
	
	// initialize variables
	userIn = getData("Enter C for a ChickenBooger, B for BeefBooger, P for PorkBooger, or E to Exit ");
	
	userIn = toupper(userIn); // makes user input uppercase
	
	// determine and display message based on user's choice
	if (userIn == 'C')
	{
		cout << "That's a Chickenbooger for you!\n";
	}
	else if (userIn == 'B')
	{
		cout << "That's a Beefbooger for you!\n";
	}
	else if (userIn == 'P')
	{
		cout << "That's a Porkbooger for you!\n";
	}
	else if (userIn == 'E')
	{
		cout << "Bye for now!\n";
	}
	else
	{
		cout << "Invalid entry, please run again!\n";
	}
	
    system("PAUSE");
    return 0;
} // end of main()

// getData() receives input from the user
char getData(string prompt)
{
	char value;
	
	cout << prompt;
	cin >> value;
	
	return value;	
} // end of getData()
