/* 
Name:     		Logan Falkenberg
Date: 			March 13 2021
Assignment #:	classwork55
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments

class definition
Create a class Triangle. Two Public data attiributes (base, height)

program definition
An object of Triangle will be created, 2 values will be assigned to the data attributes
it will find the area of the triangle and will print
*/

#include <iostream>				// for cin, cout, endl
using namespace std;

// Declare classes

class Triangle{
	
	public:
		double base;
		double height;
	
}; // End of class Triangle


int main()
{
	
	// Create instance of class
	Triangle myTriangle;
	
	// Declare variables
	double area;
	
	// Assign values to the attributes 
	myTriangle.base = 3;
	myTriangle.height = 5;
	
	area = 0.5 * myTriangle.base * myTriangle.height;
	
	cout << "Area: " << area << endl;
	
    cin.get();
    return 0;
    
}// end of main



