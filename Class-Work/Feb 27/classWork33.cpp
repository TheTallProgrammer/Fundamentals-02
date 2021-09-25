/* 
Name:     		Gia Rivera
Date: 			Feb 27 2021
Assignment #:	classWork33
Status: 		Completed
Language:		C++
-------------------------------------------------------------------------
Comments
ask users to enter integers until -999
-999 will terminate the users input; sentinel value
*/

#include <iostream>				// for cin, cout, endl
#include <string>
using namespace std;

// declaration of function prototypes
int getUserData(string);

int main()
{
	// initialize variables
	int number;
	
	// pre-read
	number = getUserData("Enter an integer; -999 will terminate ");
	
	while (number != -999)
	{
		// update read
		number = getUserData("Enter an integer; -999 will terminate ");
	} // end of while
	
	system("PAUSE");
    return 0;
} // end of main()

int getUserData(string prompt)
{
	int value;
	cout << prompt;
	cin >> value;
	return value;	
} // end of getUserData()
