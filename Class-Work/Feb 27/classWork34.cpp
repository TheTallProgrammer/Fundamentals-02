/* 
Name:     		Gia Rivera
Date: 			Feb 27 2021
Assignment #:	classWork34
Status: 		Completed
Language:		C++
-------------------------------------------------------------------------
Comments
ask users to enter integers until -999
-999 will terminate the users input; sentinel value
display how many numbers were entered
*/

#include <iostream>				// for cin, cout, endl
#include <string>
using namespace std;

// declaration of function prototypes
int getUserData(string);

int main()
{
	// declaration of variables
	int number;
	int count;
	
	count = 0;
	// pre-read
	number = getUserData("Enter an integer; -999 will terminate ");
	
	while (number != -999)
	{
		count = count + 1;
		
		// update read
		number = getUserData("Enter an integer; -999 will terminate ");
	} // end of while
	
	cout << "The number of integers entered: " << count << endl;
	
	system("PAUSE");
    return 0;
} // end of main()

// getUserData() receives integer input from the user
int getUserData(string prompt)
{
	int value;
	
	cout << prompt;
	cin >> value;
	
	return value;	
} // end of getUserData()
