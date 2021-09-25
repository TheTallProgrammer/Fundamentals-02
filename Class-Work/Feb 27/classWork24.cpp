/* 
Name:     		Gia Rivera
Date: 			Feb 27 2021
Assignment #:	classWork24
Status: 		Completed
Language:		C++
-------------------------------------------------------------------------
Comments
Regular boat ride:
	users will enter # of group members
	20 or more = 15% off
	10 to 19 = 10% off
	5 to 9 = 5% off
	otherwise, $15
*/

#include <iostream>				// for cin, cout, endl
#include <string>
using namespace std;

// declaration of function prototypes
int getData(string);
float percentageCheck(int);

int main()
{
	// declaration of variables
	const float BASE_PRICE = 15;
	int groupCount;
	float percentage;
	float price;
	
	// get group number from user, determine the percentage off their boat ride,
	// and display final cost of boat ride
	string prompt = "Enter the number of people about to take this boat ride: ";
	
	groupCount = getData(prompt);
	
	percentage = percentageCheck(groupCount);
	
	price = (BASE_PRICE - BASE_PRICE * percentage) * groupCount;
	
	cout << "The cost of a boat ride for this group is " << price << endl;
	
    system("PAUSE");
    return 0;
} // end of main()

// percentageCheck() determines the percent discount based on group size
float percentageCheck(int groupNumber)
{
	float percentage;
	
	if (groupNumber >= 20)
	{
		percentage = .15;
	}
	else if (groupNumber >= 10)
	{
		percentage = .1;
	}
	else if (groupNumber >= 5)
	{
		percentage = .05;
	}
	else
	{
		percentage = 0;	
	}
	
	return percentage;
} // end of percentageCheck()

// getData() uses a prompt to provoke and return user input
int getData(string prompt)
{
	int value;
	
	cout << prompt;
	cin >> value;
	
	return value;	
} // end of getData()
