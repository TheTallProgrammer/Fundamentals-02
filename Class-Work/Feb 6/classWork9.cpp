/* 
Name:     		Logan Falkenberg
Date: 			Feb 6
Assignment #:	classWork9
Status: 		Completed
Language: 		C++
-------------------------------------------------------------------------
Comments
The program is about functions
*/

#include <iostream>				// for cin, cout, endl
using namespace std;

// Declaration of function prototypes
void header(string);
int getData(string);

int main()
{
	int valueOne;
	int valueTwo;
	int tallySum;
	
	header("classwork9"); // Calling the header() function
	valueOne = getData("Enter the first integer: ");
	valueTwo = getData("Enter the second integer: ");
	
	tallySum = valueOne + valueTwo;
	
	cout << endl << "The sum of " << valueOne << " and " << valueTwo << " is " << tallySum << endl;
    
	system("PAUSE");
    return 0;
} // end of main()


int getData(string prompt)
{
	int value;
	cout << prompt;
	cin >> value;
	
	return value; 
} // End of getData()

// header() function displays 
void header(string prompt)
{
	cout << "-----------------------------------------------------------------" << endl;
	cout << prompt << endl;
	cout << "Written by Logan" << endl;
	cout << "Feb 6, 2021" << endl;
	cout << "-----------------------------------------------------------------" << endl;
} // End of header()
