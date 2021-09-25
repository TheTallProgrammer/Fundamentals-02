/* 
Name:     		Logan Falkenberg
Date: 			Jan 30
Assignment #:	classWork3
Status: 		Completed
-------------------------------------------------------------------------
Comments
This program will find the area of a triangle given base and height
*/

#include <iostream>				// for cin, cout, endl
using namespace std;

int main()
{
	// decleration of variables 
    float base;
    float height;
    float area;
    
    // initializing variables
    base = 3.0;
    height = 4.0;
    
    // calculation section
	area = 0.5 * base * height;
	
	// displays the results
    cout << "The area of the triangle is " << area << endl;
    
    system("PAUSE");
    return 0;
} // end of main()

