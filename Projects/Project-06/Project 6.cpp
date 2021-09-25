/* 
Name:     		Logan Falkenberg
Date: 			April 11 2021
Assignment #:	Project 6
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments
	This program will hold an array of employees as well as their work information
	Gross pay, net pay, hours worked, ID
*/


#include <string>
#include <iomanip>      // std::setw
#include <iostream>
#include <iomanip>      // std::setprecision
using namespace std;

// Structs
struct Employee
{
	int IDNum;
	string name;
	float payRate;
	float netPay;
	int type;
	float grossPay;
	float tax;
};

struct Timesheet
{
	float hours;
};


// Prototypes
void setEmployeeData(Employee [], int);
void printEmployeeData(Employee [], Timesheet [], int, float &, float &);
void setTimecard(Employee [], Timesheet [], int);
string getName(int);
void getGrossAndNetPay(Employee [], Timesheet [], int, float &, float &);


int main()
{
	
	// Declares variables
	const int TOTAL_EMPLOYEES = 4;
	float totalGrossPay;
	float totalNetPay;
	
	// Initialize variables
	totalGrossPay = 0.0;
	totalNetPay = 0.0;
	
	// Declares arrays
	Employee employees [TOTAL_EMPLOYEES];
	Timesheet employeesTime [TOTAL_EMPLOYEES];
	
	// Calls functions
	setEmployeeData(employees, TOTAL_EMPLOYEES);
	setTimecard(employees, employeesTime, TOTAL_EMPLOYEES);
	getGrossAndNetPay(employees, employeesTime, TOTAL_EMPLOYEES, totalGrossPay, totalNetPay);
	printEmployeeData(employees, employeesTime, TOTAL_EMPLOYEES, totalGrossPay, totalNetPay);
	
    return 0;
    
} // End of main()


// This function sets the data in each struct variable for each employee 
void setEmployeeData(Employee emp[], int SIZE)
{
	
	// Declare variables
	string name;
	float initialPay;
	float netPay;
	int type;
	bool incorrect;
	
    for(int i = 0; i < SIZE; i++)
    {
    	
    	// Gets the employee's information
        cout << "Enter information for employee " << i+1 << endl;
    
        // Gets the employee's ID
        cout << "Employee ID: ";
        
        
        cin >> emp[i].IDNum;
        cin.get();
        
        // Checks to see if the ID number is a positive number
        if (emp[i].IDNum < 0){
        	incorrect = true;
        	while(incorrect){
        		// Gets the employee's ID
        		cout << "Negative values not accepted." << endl;
		        cout << "Employee ID: ";
		        
		        cin >> emp[i].IDNum;
		        cin.get();
		        
		        if(emp[i].IDNum > 0){
		        	incorrect = false;
				}
			}
		}
        
        // Gets the employee's name
        name = getName(i);
        emp[i].name = name;
        
        // Gets pay rate per hour
        cout << "Pay rate: ";
        cin >> emp[i].payRate;
        
        // Checks to see if the payrate is a positive number
        if(emp[i].payRate < 0.0){
        	incorrect = true;
        	while(incorrect){
        		// Gets pay rate per hour
        		cout << "Negative values not accepted." << endl;
		        cout << "Pay rate: ";
		        
		        cin >> emp[i].payRate;
		        
		        if (emp[i].payRate > 0){
		        	incorrect = false;
				}
			}
		}
        
        // Gets the type of employee (0,1)
        cout << "Type: ";
        cin >> emp[i].type;
        
        // Checks to see if the employee type was 0 or 1
        if (emp[i].type < 0 || emp[i].type > 1){
        	incorrect = true;
        	while(incorrect){
        		// Gets the type of employee (0,1)
        		cout << "Invalid Type. Types: (0,1) " << endl;
        		cout << "Type: ";
        		
        		cin >> emp[i].type;
        		
        		if (emp[i].type == 1 || emp[i].type == 0){
        			incorrect = false;
				}
			}
		}
		
		cout << "\n";
        
    }
} // End of setEmployeeData()


// This function gets the name of each employee
string getName(int index){

	char n[20];
	string name;
	
	// Asks for the employees name
	cout << "Employee name: ";
    
    cin.get(n, 20);
    cin.get();
    
    name = n;

	return name;
	
} // End of getName()


// This function gets the hours worked for each employee
void setTimecard(Employee emp[], Timesheet timeCardEmp[], int SIZE){
	
	// Declare variables
	bool incorrect;
	
	cout << "\nEnter timecard information for each employee: " << endl;	
	
	for (int i = 0; i < SIZE; i++){
		
		// Asks for the employee's hours
		cout << "Hours worked for " << emp[i].name << ": ";
		
		cin >> timeCardEmp[i].hours;
		
		// Checks to see if the hours entered were a positive value
		if (timeCardEmp[i].hours < 0.0){
			incorrect = true;
			while(incorrect){
				
				// Asks for the hours again
				cout << "Hours cannot be a negative value" << endl;
				cout << "Hours worked for " << emp[i].name << ": ";
				
				cin >> timeCardEmp[i].hours;
				
				if (timeCardEmp[i].hours > 0.0){
					incorrect = false;
				}
			}
		}
		
	}
	
} // End of setTimecard()


// This function gets the users struct data and calculates the gross and net pay of each employee
void getGrossAndNetPay(Employee emp[], Timesheet timeCardEmp[], int SIZE, float &totalNetPay, float &totalGrossPay){
	
	// Declare variables
	float grossPay;
	float overTime;
	float tax;
	float netPay;
	
	for (int i = 0; i < SIZE; i++){
		
		// Checking to see what type the employee was
		if (emp[i].type == 0){
			
			// If the employee worked overtime
			if (timeCardEmp[i].hours > 40){
				
				// Gets the grossPay
				overTime = timeCardEmp[i].hours - 40;
				grossPay = 40 * emp[i].payRate + overTime * emp[i].payRate * 1.5;
				tax = grossPay * .15;
				emp[i].tax = tax;
				grossPay = grossPay + tax;
				emp[i].grossPay = grossPay;
				totalGrossPay = totalGrossPay + grossPay;
				
				// Gets the netPay
				netPay = grossPay - tax;
				emp[i].netPay = netPay;
				totalNetPay = totalNetPay + netPay;
				
			// If the employee didn't work overtime
			} else {
			
				// Gets the grossPay
				grossPay = emp[i].payRate * timeCardEmp[i].hours;
				tax = grossPay * .15;
				emp[i].tax = tax;
				grossPay = grossPay + tax;
				emp[i].grossPay = grossPay;
				totalGrossPay = totalGrossPay + grossPay;
				
				// Gets the netPay
				netPay = grossPay - tax;
				emp[i].netPay = netPay;
				totalNetPay = totalNetPay + netPay;
			}
		
		// if employee is the other type
		} else if (emp[i].type == 1) {
			
			if (timeCardEmp[i].hours > 40){
				
				// Gets the grossPay
				overTime = timeCardEmp[i].hours - 40;
				grossPay = 40 * emp[i].payRate + overTime * emp[i].payRate;
				tax = grossPay * .15;
				emp[i].tax = tax;
				grossPay = grossPay + tax;
				emp[i].grossPay = grossPay;
				totalGrossPay = totalGrossPay + grossPay;
				
				// Gets the netPay
				netPay = grossPay - tax;
				emp[i].netPay = netPay;
				totalNetPay = totalNetPay + netPay;
				
			// If the employee didn't work overtime
			} else {
				
				// Gets the grossPay
				grossPay = emp[i].payRate * timeCardEmp[i].hours;
				tax = grossPay * .15;
				emp[i].tax = tax;
				grossPay = grossPay + tax;
				emp[i].grossPay = grossPay;
				totalGrossPay = totalGrossPay + grossPay;
				
				// Gets the netPay
				netPay = grossPay - tax;
				emp[i].netPay = netPay;
				totalNetPay = totalNetPay + netPay;
			}
		}
	} // End of for-loop
} // End of getGrossAndNetPay()


// This function displays the all the data that was collected in a formated state
void printEmployeeData(Employee emp[], Timesheet timeCardEmp[], int SIZE, float &totalNetPay, float &totalGrossPay){
	
	cout << "\nPayroll Report" << endl;
	cout << "\nID" << setw(10) << "Name" << setw(25) << "Gross Pay" << setw(10) << "Tax" << setw(12) << "Net Pay" << endl;
	
//	IDNum;
//	string name;
//	float payRate;
//	float netPay;
//	int type;
//	float grossPay;
	
	for (int i = 0; i < SIZE; i++){
		
		cout << left << setw(8) << emp[i].IDNum << left << setw(20) << emp[i].name << left << setw(8) << fixed << std::setprecision(2) << emp[i].grossPay << right << 
		setw(13) << fixed << std::setprecision(2) << emp[i].tax << right << setw(9) << fixed << std::setprecision(2) << emp[i].netPay << endl;
		
	}
	
	cout << "\nTotal Gross Pay $ " << fixed << std::setprecision(2) << totalGrossPay << endl;
	cout << "Total Net Pay   $ " << right << setw(4) << fixed << std::setprecision(2) << totalNetPay << endl;
	
	
} // End of printEmployeeData()

