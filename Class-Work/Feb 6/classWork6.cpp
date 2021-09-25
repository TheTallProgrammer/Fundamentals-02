/* 
Name:     		Logan Falkenberg
Date: 			Feb 6
Assignment #:	classWork6
Status: 		Completed
Language: 		C++
-------------------------------------------------------------------------
Comments
The program is finding the sum, difference, remainder of two integers
*/

#include <iostream>				// for cin, cout, endl
using namespace std;

int main()
{
	// This section declares all variables used in the program
	int valueOne;
	int valueTwo;
	int tallySum;
	int tallyDif;
	int tallyRem;
	
	// This section will initialize the values
	valueOne = 6;
	valueTwo = 9;
	
	// This section will find the sum, difference, and remainder
	tallySum = valueOne + valueTwo;
	tallyDif = valueOne - valueTwo;
	tallyRem = valueOne % valueTwo;
	
	// This section will display the sum, difference, and remainder
	cout << "The sum of " << valueOne << + " and  " << valueTwo << " is " << tallySum << endl;
	cout << "The difference of " << valueOne << + " and " << valueTwo << " is " << tallyDif << endl;
	cout << "The remainder after dividing " << valueOne << + " by " << valueTwo << " is " << tallyRem << endl;
	
    
    system("PAUSE");
    return 0;
} // end of main()

