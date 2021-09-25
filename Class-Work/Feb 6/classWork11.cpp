/* 
Name:     		Logan Falkenberg
Date: 			Feb 6
Assignment #:	classWork9
Status: 		Completed
Language: 		C++
-------------------------------------------------------------------------
Comments
This program will find the perimeter of a rectangle 
Users will enter the 2 sides of a rectangle (Length and Width) - using function getData()
*/

#include <iostream>				// for cin, cout, endl
using namespace std;

// Declaration of function prototypes
int getData(int, int);

int main()
{
	// Declare the variables
	int sideOne, sideTwo;
	
	// Get the user's data
	cout << "Enter the first side of the rectangle: ";
	cin >> sideOne;
	
	cout << "Enter the second side of the rectangle: ";
	cin >> sideTwo;
	
	// Calls the getData() function
	getData(sideOne, sideTwo);
	
	system("PAUSE");
    return 0;
} // end of main()

// getData() function
int getData(int sideOne, int sideTwo)
{
	// Declare the variables
	int perimeter;
	
	// Calculations
	perimeter = sideOne * 2 + sideTwo * 2;
	
	// Displays the results of the calculation
	cout << endl << "The perimeter of the sides " << sideOne << " and " << sideTwo << " is " << perimeter << endl;
	
}

