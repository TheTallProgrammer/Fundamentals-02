/* 
Name:     		Gia Rivera
Date: 			Feb 13 2021
Assignment #:	classWork18
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
	int grade;
	
	// determine letter grade from numeric grade
	grade = getData("Enter your numeric grade: ");
	
	if (grade >= 90)
	{
		cout << "You have an A" << endl;
	}
	else if (grade >= 80)
	{
		cout << "You have a B" << endl;
	}
		else if (grade >= 70)
	{
		cout << "You have a C" << endl;
	}
		else if (grade >= 60)
	{
		cout << "You have a D" << endl;
	}
	else
	{
		cout << "You have an F" << endl;
	}
	
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
