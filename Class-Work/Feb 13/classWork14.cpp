/* 
Name:     		Gia Rivera
Date: 			Feb 13 2021
Assignment #:	classWork14
Status: 		Completed
Language:		C++
-------------------------------------------------------------------------
Comments
This program will find the perimeter of a triangle.
Users will enter the input of the three sides of the triangle.
We will use functions to get the data, calculate, and print.
*/

#include <iostream>				// for cin, cout, endl
using namespace std;

// declaration of function prototypes
int getData(string);
int findPerimeter(int, int, int);
void displayResult(int);

int main()
{
	// declaration of variables
	int sideOne;
	int sideTwo;
	int sideThree;
	int perimeter;
	
	// get the user's data
	sideOne = getData("Enter side one of the triangle: ");
	sideTwo = getData("Enter side two of the triangle: ");
	sideThree = getData("Enter side three of the triangle: "); 
	
	// find the perimeter
	perimeter = findPerimeter(sideOne, sideTwo, sideThree);
	
	// display the perimeter
	displayResult(perimeter);
	
    system("PAUSE");
    return 0;
} // end of main()

// displayResult() displays perimeter of triangle
void displayResult(int perimeter)
{
	cout << "\nResult" << endl;
	cout << "The perimeter is " << perimeter << endl;
} // end of displayResult()

// findPerimeter() calculates perimeter of triangle
int findPerimeter(int sideOne, int sideTwo, int sideThree)
{
	int perimeter;
	
	perimeter = sideOne + sideTwo + sideThree;
	
	return perimeter;
} // end of findPerimeter()

// getData() receives input from the user
int getData(string prompt)
{
	int value;
	
	cout << prompt;
	cin >> value;
	
	return value;	
} // end of getData()
