/* 
Name:     		Logan Falkenberg
Date: 			Jan 30
Assignment #:	classWork1
Status: 		Completed
-------------------------------------------------------------------------
Comments
This program will display the sum of 2 numbers 
*/

#include <iostream>				// for cin, cout, endl
using namespace std;

int main()
{
	// decleration of variables 
    int numberOne;
    int numberTwo;
    int answer;
    
    // initializing variables
    numberOne = 15;
    numberTwo = 25;
    
    // calculation section
	answer = numberOne + numberTwo;
	
	// displays the results
	cout << " The sum is "  << answer << endl;
    
    system("PAUSE");
    return 0;
} // end of main()

