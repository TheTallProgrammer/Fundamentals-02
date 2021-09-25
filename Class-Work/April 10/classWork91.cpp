/* 
Name:     		Logan Falkenberg
Date: 			March 13 2021
Assignment #:	classwork55
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments


*/
/* isdigit example */

#include <string>
#include <iostream>
using namespace std;

struct Employee
{
	int IDNum;
	float hoursWorked;
	float grossPay;
	float netPay;
};

void setEmployeeData(Employee [], int);
void printEmployeeData(Employee [], int);

int main()
{
	const int TOTAL_EMPLOYEES = 5;
	Employee employees [TOTAL_EMPLOYEES];
	
	setEmployeeData(employees, TOTAL_EMPLOYEES);
	printEmployeeData(employees, TOTAL_EMPLOYEES);
    
    return 0;
}

void printEmployeeData(Employee emp[], int SIZE)
{
    for(int i = 0; i < SIZE; i++)
    {
        cout << "\nData for employee: " << i+1 << endl << endl;
        cout << "The employee's ID number is: " << emp[i].IDNum << endl;
        cout << "The employee worked " << emp[i].hoursWorked<< " hours.\n";
        cout << "The employee's gross pay is: " << emp[i].grossPay << endl;
        cout << "The employee's net pay is: " << emp[i].netPay << endl;
        cout << endl;
    }
}


void setEmployeeData(Employee emp[], int SIZE)
{
    for(int i = 0; i < SIZE; i++)
    {
        cout << "\nEnter data for employee " << i+1 << endl;
        
        cout << "Enter the employee number:\n";
        
        cin >> emp[i].IDNum;
        
        cout << "Enter the hours worked:\n";
        
        cin >> emp[i].hoursWorked;
        
        cout << "Enter the gross pay:\n";
        
        cin >> emp[i].grossPay;
        
        emp[i].netPay = emp[i].grossPay * 0.9;
    }
}
