/* 
Name:     		Logan Falkenberg
Date: 			Feb 6
Assignment #:	classWork12
Status: 		Completed
Language: 		C++
-------------------------------------------------------------------------
Comments
The program will find the value of 48 + 2ab + 4b
users will enter ab as integers
*/

#include <iostream>				// for cin, cout, endl
using namespace std;

// Declaration of function prototypes
int getDataAndCalculate(int, int);

int main()
{
	// Declaring variables
	int a, b;
	
	// Getting input
	cout << "Enter a: ";
	cin >> a;
	
	cout << "Enter b: ";
	cin >> b;
	
	// Calls function getData() 
	getDataAndCalculate(a, b);
	
	system("PAUSE");
    return 0;
} // end of main()

int findResult()
{
	
} // end findResult()

// Function getData()
int getDataAndCalculate(int a, int b)
{
	// Declaring variables
	int result;
	
	// Calculation
	result = 4 * a + 2 * (a * b) + 4 * b;
	
	// Display result
	cout << "The answer to the equation of 4a + 2ab + 4b = " << result << endl;
	
} // End function getData()

