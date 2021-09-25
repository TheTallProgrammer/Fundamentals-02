/* 
Name:     		Gia Rivera
Date: 			Feb 13 2021
Assignment #:	classWork15
Status: 		Completed
Language:		C++
-------------------------------------------------------------------------
Comments
This program will find the area of a triangle
Users will enter base and height
All the values will be float
*/

#include <iostream>				// for cin, cout, endl
using namespace std;

// declaration of function prototypes
float getData(string);
void findArea(float, float, float &);
void displayResult(float);

int main()
{
	// declaration of variables
	float base;
	float height;
	float area;
	
	// initialize variables
	base = getData("Enter the base of the triangle: ");
	height = getData("Enter the height of the triangle: ");
	
	// gets the area of the triangle
	findArea(base, height, area);
	
	// displpays the result
	displayResult(area);
	
    system("PAUSE");
    return 0;
} // end of main()

// displayResult() displays area of triangle
void displayResult(float area)
{
	cout << "\nResult: " << endl;
	cout << "The area of the triangle is " << area << endl;
} // end of displayResult()

// findArea() calculates area of triangle
void findArea(float base, float height, float & area)
{
	area = .5 * base * height;
} // end of findArea()

// getData() receives input from the user
float getData(string prompt)
{
	float value;
	
	cout << prompt;
	cin >> value;
	
	return value;	
} // end of getData()
