/* 
Name:     		Logan Falkenberg
Date: 			March 7
Assignment #:	Test 1 (Project)
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments
This program will manage an apartment complex with 10 units
The rent is $2,000 per month.

*/
#include <iomanip>      // std::setprecision
#include <iostream>				// for cin, cout, endl
using namespace std;


//prototype declerations
void getDayAndUnit(int &, int &);
void getMonth(string, string &, int &);
void calculateMonthlyTotal(int [], int [], int &, int &, int &, int &, double &, double &, double &);
void printResults(string, int, int, int, int, int, double, double, double);


int main()
{
	// decleration of variables 
	// Date variables
	string month;
	int days [10];
	int day;
	int year;
	// Unit variables
	int unitNums [10];
	int unitNumber;
	int unitCounter;
	const int UNIT_MAX = 10;
	int numOfUnitsPaid;
	int numOfUnitsPaidOnTime;
	int numOfUnitsPaidLate;
	double lateFees;
	double totalRent;
	int numOfEvicted;
	double totalEvictedAmount;
	
	// Ititialize the variables
	numOfUnitsPaid = 0;
	numOfUnitsPaidOnTime = 0;
	numOfUnitsPaidLate = 0;
	lateFees = 0.0;
	totalRent = 0.0;
	numOfEvicted = 0; 
	totalEvictedAmount = 0.0;
	
	// Initialize the unitCounter to start at 0 which will help exit the while loop
	unitCounter = 0;
	
	// Gets the month 
	getMonth("Enter the month: ", month, year);
	
	// Get the date and unit number of 10 units
	while (unitCounter < UNIT_MAX){
		
		// Calls the function to get the current day/unit number
		getDayAndUnit(day, unitNumber);
		cout << " " << endl;
		
		// Pushes the current day into the days array 
		days[unitCounter] = day;
		
		// Pushes in the unit numbers to the complexUnits array
		unitNums[unitCounter] = unitNumber;
		
		// Adds 1 to the counter so it's not an infinite loop
		unitCounter = unitCounter + 1;
	}

	// Calls the function to get the monthly total of the inputted units with their days
	calculateMonthlyTotal(days, unitNums, numOfUnitsPaid, numOfUnitsPaidOnTime, numOfUnitsPaidLate, numOfEvicted, lateFees, totalRent, totalEvictedAmount);

	// Print the results of the calculations
	printResults(month, year, numOfUnitsPaid, numOfUnitsPaidOnTime, numOfUnitsPaidLate, numOfEvicted, lateFees, totalEvictedAmount, totalRent);

	// Ends the function 
    cin.get();
    return 0;
    
}// end of main()


// The function getDateAndUnit() gets passed in the prompt and recieves the users input and updates the variables in the parameter using pass by reference
void getDayAndUnit(int &day, int &unitNumber)
{
	// Declaration of variables
	
	// Gets the user's input
	cout << "Unit number: ";
	cin >> unitNumber;
	
	cout << "Enter the day of the month: ";
	cin >> day;
	
	
} // End of getDayAndUnit()


// This function asks the user for the month/year
void getMonth(string prompt, string &month, int &year){
	
	cout << prompt;
	cin >> month >> year;
	
	
} // End of getMonth()


// This function will calculate the montly pay of all of the units dependent upon the day they were paid
void calculateMonthlyTotal(int days[], int unitNums[10], int &numOfUnitsPaid, int &numOfUnitsPaidOnTime, int &numOfUnitsPaidLate, 
						   int &numOfEvicted, double &lateFees, double &totalRent, double &totalEvictedAmount){
	
	// Declare variables
	int currentDay;
	int eachDayAfterThirdTotal;
	
	// Loop for navigating through the days array to see if any day was before or after the 3rd, and if the day was after the 30th
	for (int i = 0; i < 10; i++){
		
		// Assigning currentDay to the element of the index of the array days
		currentDay = days[i];
		
		// Conditional to see if the day was paid before the 3rd of the month
		if (currentDay <= 3){
			
			// If it meets the requirements, then its paid and its on time
			numOfUnitsPaid = numOfUnitsPaid + 1;
			numOfUnitsPaidOnTime = numOfUnitsPaidOnTime + 1;
		
		// Conditional to see if the day was paid after the 3rd, but still before the eviction date
		} else if (currentDay > 3 && currentDay <= 30){
		
			// Met the requirements of payment before eviction, but still late.
			numOfUnitsPaid = numOfUnitsPaid + 1;
			
			// Updates the paid late variable
			numOfUnitsPaidLate = numOfUnitsPaidLate + 1;
			
			// Gets the amount of days that the payment was late
			eachDayAfterThirdTotal = eachDayAfterThirdTotal + currentDay - 3;
			
			
		} else if (currentDay > 30){
			
			// This means that it's too late to pay, so they must be evicted
			numOfEvicted = numOfEvicted + 1;
			totalEvictedAmount = totalEvictedAmount + (30-3) * 5;
			
		} 
		
	} // End of main for-loop
	
	// Calculations
	
	// Gather the late fees for all of the days after the 3rd * $5.00
	lateFees = eachDayAfterThirdTotal * 5.00;
	
	// Totals up the charges for the number of evicted 
	totalEvictedAmount = totalEvictedAmount + numOfEvicted * 500.00;
	totalEvictedAmount = totalEvictedAmount + numOfEvicted * 2000.00;
	
	// This gathers the total amount of fees
	totalRent = (numOfUnitsPaid * 2000) + lateFees;
	
	
} // End of calculateMonthlyTotal()


// This function displays the results of the month
void printResults(string month, int year, int numOfUnitsPaid, int numOfUnitsPaidOnTime, int numOfUnitsPaidLate, int numOfEvicted, 
					double lateFees, double totalEvictedAmount, double totalRent){
	
	// Displays the results
	cout << "--- Rental Transaction for the month of " << month << " " << year << " -----" << endl;
	cout << "Payment Summary" << endl;
	cout << "	Number of units paid: " << numOfUnitsPaid << endl;
	cout << "	Number of units paid on-time: " << numOfUnitsPaidOnTime << endl;
	cout << "	Number of units paid late: " << numOfUnitsPaidLate << endl;
	cout << "	Amount collected for late fees: $" << fixed << std::setprecision(2) << lateFees << endl;
	cout << "	Total rent(including late fees) collected: $" << fixed << std::setprecision(2) << totalRent << endl;
	cout << "\nEviction Summary" << endl;
	cout << "	Number of tenants evicted: " << numOfEvicted << endl;
	cout << "	Total amount for eviction collections: $" << fixed << std::setprecision(2) << totalEvictedAmount << endl;
	
} // End of printResults()

