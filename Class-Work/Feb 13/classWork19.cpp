/* 
Name:     		Gia Rivera
Date: 			Feb 13 2021
Assignment #:	classWork19
Status: 		Completed
Language:		C++
-------------------------------------------------------------------------
Comments
Find whether a number is odd or even
*/

#include <iostream>				// for cin, cout, endl
#include <string>
using namespace std;

// declaration of function prototypes
int getData(string);

int main()
{
	// declaration of variables
	int number;
	
	// initialize variables
	number = getData("Enter a number to find out if it's odd or even! ");
	
	// determine if number is even or odd
	if (number % 2 == 0)
	{
		cout << "It's even!\n";
	}
	else
	{
		cout << "It's odd!\n";
	}
	
    system("PAUSE");
    return 0;
} // end of main()

// getData() receives input from the user
int getData(string prompt)
{
	int value;
	
	cout << prompt;
	cin >> value;
	
	return value;	
} // end of getData()
