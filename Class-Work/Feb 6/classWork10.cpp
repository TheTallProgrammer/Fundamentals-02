/* 
Name:     		Logan Falkenberg
Date: 			Feb 6
Assignment #:	classWork9
Status: 		Completed
Language: 		C++
-------------------------------------------------------------------------
Comments
This program will find the peremeter of a triangle
users will enter the 3 sides of the triangle - we will use a function to get the data
*/

#include <iostream>				// for cin, cout, endl
using namespace std;

// Declaration of function prototypes
int getData(int, int, int);

int main()
{
	// Declare variable
	int sideOne, sideTwo, sideThree;
	
	// Getting the inputs
	cout << "Enter the first side: ";
	cin >> sideOne;
	
	cout << "Enter the second side: ";
	cin >> sideTwo;
	
	cout <<"Enter the third side: ";
	cin >> sideThree;
	
	// Calls the getData() function
    getData(sideOne, sideTwo, sideThree);
    
	system("PAUSE");
    return 0;
} // end of main()

// Gets the data for the sides of the triangles
int getData(int sideOne, int sideTwo, int sideThree)
{
	// Declare variable
	int perimeter;
	
	// Calculation
	perimeter = sideOne + sideTwo + sideThree;
	
	// Displays the result of the calculation
	cout << "The perimeter of sides " << sideOne << ", " << sideTwo << " and " << sideThree << " is " << perimeter << endl;
	
} // End of getData()

