/* 
Name:     		Logan Falkenberg
Date: 			April 21 2021
Assignment #:	Project 8
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments

This program gets the values of a date and outputs three different outputs of the date

*/
#include <iostream>				// for cin, cout, endl
using namespace std;


// Declare Classes
class Date{
	
	private:
		
		// Declare variables
		int day;
		int month; 
		int year;
		
		string getMonthName(int month){
			
			string m;
			string months [12] {"January", "February", "March", "April", "May", "June", "July", 
								"August", "September", "October", "November", "December"};
								
			for (int i = 0; i < 12; i++){
				
				if(month == i){
					m = months[i-1];
				}
					
			}
			
			return m;
			
		} // End of getMonthName()
		
	public:
		
		// Constructor
		Date(){
			
			// Initializing variables 
			day = 1;
			month = 1;
			year = 2020;
	
		} // End of Date()
		
		
		// This function gets new values for the day,month,year
		void setNewDate(int d, int m, int y){
			
			// Tests to see if the day is between 1-31
			if (d >= 1 && d <= 31){
				day = d;
			}
			
			// Tests to see if the month is between 1-12
			if (m >= 1 && m <= 12){
				month = m;
			}
			
			// Tests to see if the year is between 1950-2020
			if (y >= 1950 && y <= 2020){
				year = y;
			}
			
		} // End of setNewDate()
		
		
		// Prints the first format of the date (01/01/0001)
		void printDateOne(void){
			
			cout << "\n" << month << "/" << day << "/" << year << endl;
			
		} // End of printDateOne
		
		
		// Prints the second format of the date (January 01, 0001)
		void printDateTwo(void){
			
			// Declare variables
			string m;
			
			m = getMonthName(month);
			
			cout << m << " " << day << ", " << year << endl;
			
		} // End of printDateTwo()
		
		
		// Prints the second format of the date (01 January 0001)
		void printDateThree(void){
			
			// Declare variables
			string m;
			
			m = getMonthName(month);
			
			cout << day << " " << m << " " << year << endl;
			
		} // End of printDateThree()
		
}; // End of class Date()

//prototype declerations
int getValue(string);

int main()
{
	
	// Declare variables
	Date myDate;
	int day;
	int month;
	int year;
	
	// Initializing the values of the date
	month = getValue("Enter the month: ");
	day = getValue("Enter the day: ");
	year = getValue("Enter the year: ");
	
	// Giving new values to the variables in the class
	myDate.setNewDate(day, month, year);
	
	// Printing out the first format of the date
	myDate.printDateOne();
	
	// Printing out the second format of the date
	myDate.printDateTwo();
	
	// Printing out the third format of the date
	myDate.printDateThree();
	
    cin.get();
    return 0;
    
}// end of main


// Used to assign values to a variable
int getValue(string prompt){
	
	// Declare variables
	int value;
	
	cout << prompt;
	cin >> value;
	
	return value;
	
} // End of getValue()


