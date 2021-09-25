/* 
Name:     		Gia Rivera
Date: 			Feb 13 2021
Assignment #:	classWork17
Status: 		Completed
Language:		C++
-------------------------------------------------------------------------
Comments
We're learning decisions
*/

#include <iostream>				// for cin, cout, endl
using namespace std;

// declaration of function prototypes
int getData(string);

int main()
{
	// declaration of variables
	int age;
	
	// initialize variables
	age = getData("Enter your age: ");
	
	// determine if you can dance based on age
	if (age > 80)
	{
		cout << "You can still dance!" << endl;
	}
	else
	{
		cout << "You are too old to dance" << endl;
	} // end of else-if
	
	cout << "Goodbye" << endl;
	
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
