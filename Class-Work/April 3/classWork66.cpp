/* 
Name:     		Logan Falkenberg
Date: 			March 13 2021
Assignment #:	classwork55
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments
This program will recieve an employees id, name, hourly pay
and will calculate their total pay if the employees id is searched
SEQUENTIAL SEARCH
*/
#include <iostream>				// for cin, cout, endl
using namespace std;

//prototype declerations
void inputData(int [], float [], float [], int &, string []);
void search(int [], float [], float [], int ,string []);

const int MAX_EMPLOYEE = 3;
int main()
{
	int employeeID[MAX_EMPLOYEE];
	float hourlyPay[MAX_EMPLOYEE];
	float hoursWorked[MAX_EMPLOYEE];
	string employeeName[MAX_EMPLOYEE];
	
	int count = 0;
	
	inputData(employeeID, hourlyPay, hoursWorked, count, employeeName);
	search(employeeID, hourlyPay, hoursWorked, count, employeeName);
	
    cin.get();
    return 0;
    
}// end of main

// This function recieves the data revolving around emp id, hours payed, hours worked, emp name
void inputData(int empId[], float hPay[], float hWorked[], int & count,string empName[])
{
    int ID;
    cout << "Please enter employee ID: ";
    cin >> ID;    
    while (ID != 0 && count < MAX_EMPLOYEE)
    {
        empId[count] = ID;
        cout << "Please enter employee name: ";
        cin >> empName[count];
        cout << "Please enter employee hourly pay: ";
        cin >> hPay[count];
        cout << "Please enter employee hours worked: ";
        cin >> hWorked[count];    
        cout << endl;
        count++;    
        if (count < MAX_EMPLOYEE)
        {    
        cout << "Please enter employee ID: ";
        cin >> ID;
        }  // end of if
    }  // end of while    
}   // end of inputData()

// This function searches for a specific piece of inputted data
void search(int empId[], float hPay[], float hWorked[], int count,string empName[])
{
    int ID;
    int counter;
    bool found = false;
    float salary = 0.0;
    cout << "Enter your employee ID to search: ";
    cin >> ID;
    while (counter < count && not found)
    {
        if (empId[counter] == ID)
        {
            found = true;
            salary = hPay[counter] * hWorked[counter];
        } 
        counter = counter +1;
    }
    if (not found)
    {        cout << "We didn't find your thing";    }
    else
    {        cout << empName[counter-1]<< " made : $" << salary;    }
}  // end of search

	


