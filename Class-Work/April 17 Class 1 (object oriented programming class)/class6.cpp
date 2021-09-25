/* 
Name:     		Logan Falkenberg
Date: 			March 13 2021
Assignment #:	classwork55
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments

Class definition
1. Create a class Triangle. 
2. Two Public data attiributes (base, height)

Program definition
1. An object of Triangle will be created, 
2. 2 data attributes will be entered by the user
3. Find the area of a triangle
4. Print the area of the triangle
*/

#include <iostream>				// for cin, cout, endl
using namespace std;

// Declare classes

class Triangle{
	
	public:
		double base;
		double height;
	
}; // End of class Triangle

// Prototype declaration
double getDouble(string);

int main()
{
	
	// Create instance of class
	Triangle myTriangle;
	
	// Declare variables
	double area;
	
	// Assign values to the attributes 
	myTriangle.base = getDouble("Enter the base of the triangle: ");
	myTriangle.height = getDouble("Enter the height of the triangle: ");
	
	area = 0.5 * myTriangle.base * myTriangle.height;
	
	cout << "Area: " << area << endl;
	
    cin.get();
    return 0;
    
}// end of main

double getDouble(string prompt){
	
	// Declare variables
	double value;
	
	cout << prompt;
	cin >> value;
	
	return value;
	
} // End of getDouble()

