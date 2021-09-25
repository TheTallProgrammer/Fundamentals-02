/* 
Name:     		Logan Falkenberg
Date: 			March 6 2021
Assignment #:	classWork47
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments
This program will calculate an employees weekly pay, given the pay rate and hours worked, more than 40 hours is *1.5 for pay rate
getHours(), findPayRate(), printResult()
*/
#include <iostream>				// for cin, cout, endl
using namespace std;

//prototype declerations
float getData(string);
float findWeeklyPay();
void findWeeklyPay(float, float, float &);
void printResults(float, float, float);

int main()
{
	
	float payRate;
	float weeklyPay;
	float hoursWorked;
	
	hoursWorked = getData("Enter the hours worked: ");
	payRate = getData("Enter the pay rate: ");
	
	findWeeklyPay(hoursWorked, payRate, weeklyPay);
	
	printResults(hoursWorked, payRate, weeklyPay);

	// Ends the function 
    cin.get();
    return 0;
    
}// end of main

// Function getData() will receive an input from the user and return it back to the main function
float getData(string prompt){
	
	float value;
	
	cout << prompt;
	cin >> value;
	
	return value;
	
} // End of getData()

// Finds the user's weekly pay amount
void findWeeklyPay(float hoursWorked, float payRate, float &weeklyPay){
	
	float overTime;
	
	overTime = 0.0;
	
	if (hoursWorked > 40){
		overTime = hoursWorked - 40;
		weeklyPay = 40 * payRate + overTime * payRate * 1.5;
	} else {
		weeklyPay = hoursWorked * payRate;
	}
	
	
} // End of findPayRate

// Prints the users data that was collected in the previous functions
void printResults(float hoursWorked, float payRate, float weeklyPay){
	
	cout << endl << "Results: " << endl;
	cout << "Number of hours worked: " << hoursWorked << endl;
	cout << "Pay rate is: " << payRate << endl;
	cout << "Weekly pay is: " << weeklyPay << endl;
	
} // End of printResults()

