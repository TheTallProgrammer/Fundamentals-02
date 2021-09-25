/* 
Name:     		Logan Falkenberg
Date: 			Jan 30
Assignment #:	classWork2
Status: 		Completed
-------------------------------------------------------------------------
Comments
This program will find the perimeter and area of a rectangle
*/

#include <iostream>				// for cin, cout, endl
using namespace std;

int main()
{
	// decleration of variables 
    int length;
    int width;
    int perimeter;
    int area;
    
    // initializing variables
    length = 18;
    width = 5;
    
    // calculation section
	perimeter = (length * 2) + (width * 2);
	area = length * width;
	
	// displays the results
    cout << "The perimeter is " << perimeter << endl;
    cout << "The area is " << area << endl;
    
    system("PAUSE");
    return 0;
} // end of main()

