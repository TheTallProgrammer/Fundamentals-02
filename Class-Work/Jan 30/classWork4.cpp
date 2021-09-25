/* 
Name:     		Logan Falkenberg
Date: 			Jan 30
Assignment #:	classWork4
Status: 		Completed
-------------------------------------------------------------------------
Comments
we will evaluate an expression a(2b + 3ab) where a and b will be -5 and -10 respectivly
*/

#include <iostream>				// for cin, cout, endl
using namespace std;

int main()
{
	// decleration of variables 
    int a;
    int b;
    int result;
    
    // initializing variables
    a = -5;
    b = -10;
    
    // calculation section
    result = a * (2 * b + 3 * a * b);
	
	// displays the results
	cout << "The result of the expression is " << result <<endl;
    
    system("PAUSE");
    return 0;
} // end of main()

