/* 
Name:     		Gia Rivera
Date: 			Feb 13 2021
Assignment #:	classWork16
Status: 		Completed
Language:		C++
-------------------------------------------------------------------------
Comments
We're learning decisions
*/

#include <iostream>				// for cin, cout, endl
using namespace std;

// declaration of function prototype
int getData(string);

int main()
{
	// declaration of variable
	int age;
	
	// initialize variable
	age = getData("Enter your age: ");
	
	if (age > 80)
	{
		cout << "You can still dance!" << endl;	
	} // end of if
	
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
