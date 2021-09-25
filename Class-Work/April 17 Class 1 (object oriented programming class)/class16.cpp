/* 
Name:     		Logan Falkenberg
Date: 			March 13 2021
Assignment #:	classwork55
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments

1. Create a class called Rectangle. 
2. Create a constructor called simple. Constructor means method that will execute when the object is created. 

Program definition
1. Object of simple will be created

A class constructor is a special member function of a class 
that is executed whenever we create new objects of that class.
A constructor will have exact same name as the class 
and it does not have any return type at all, not even void. Constructors can be very useful 
for setting initial values for certain member variables.
*/

#include <iostream>				// for cin, cout, endl
using namespace std;

// Declare classes
class Employee
{
    private:
        double hoursWorked;
        double hourlyPay;
    
    public:
        Employee(double valueOne, double valueTwo)
        {
            cout << "Constructing Employee " << endl;
            hoursWorked = valueOne;
            hourlyPay = valueTwo;
        } // end of constructor Employee
        
        // returns the data attribute hoursWorked
        double getHoursWorked(void)
        {
            return hoursWorked;
        } // end of getHoursWorked
        
        // returns the data attribute hourlyPay
        double getHourlyPay(void)
        {
            return hourlyPay;
        } // end of getHourlyPay

		// this method will assign the value of the hoursWorked attribute
        void setHoursWorked(double value)
        {
            hoursWorked = value;
        } // end of setHoursWorked
        
        // this method will assign the value of the hourlyPay attribute
        void setHourlyPay(double value)
        {
            hourlyPay = value;
        } // end of setHourlyPay
        
        // calculates salary by hoursWorked multiplied by hourlyPay
        double findSalary(void)
        {
            return hoursWorked * hourlyPay;
        } // end of findSalary
}; // end of class Employee
        
// prototype declaration
double getDouble(string);
          
// prototype declaration
double getDouble(string);
          
int main()
{
    double hours;
    double pay;
    
    hours = getDouble("Enter the hours worked ");
    pay = getDouble("Enter the hourly pay rate ");
    
    Employee myEmployee(hours, pay);
    
    cout << "The hours worked is " << myEmployee.getHoursWorked() << endl;
    cout << "The hourly pay is " << myEmployee.getHourlyPay() << endl;
    cout << "The salary is " << myEmployee.findSalary() << endl;
    
    system("PAUSE");
    return 0;
} // end of main()
// getDouble function gets user input
double getDouble(string prompt)
{
    double value;
    cout << prompt;
    cin >> value;
    return value;
} // end of getDouble()
