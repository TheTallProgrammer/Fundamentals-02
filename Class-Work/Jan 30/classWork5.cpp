/* 
Name:     		Logan Falkenberg
Date: 			Jan 30
Assignment #:	classWork5
Status: 		Completed
Language: 		C++
-------------------------------------------------------------------------
Comments
Evaluate expression (2+3)/(4-5)
*/

#include <iostream>				// for cin, cout, endl
using namespace std;

int main()
{
	// decleration of variables 
    int numOne;
    int numTwo;
    int numThree;
    int numFour;
    int result;
    
    // initializing variables
    numOne = 2;
    numTwo = 3;
    numThree = 4;
    numFour = 5;
    
    // calculation section
	result = (numOne + numTwo) / (numThree - numFour);
	
	// displays the results
	cout << "The result is " << result << endl;
    
    system("PAUSE");
    return 0;
} // end of main()

