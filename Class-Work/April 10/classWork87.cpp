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
    short id;
    int age;
    double wage;
};

void printInformation(Employee);

int main(){
	
	Employee josh= { 14, 32, 24.15 };
    Employee daniel= { 15, 28, 18.27 };
    
     // Print Joe's information
    printInformation(josh);
 
    cout << "\n";
 
    // Print Frank's information
    printInformation(daniel);
	
	return 0;
}

void printInformation(Employee employee)
{
    cout << "ID:   " << employee.id << "\n";
    cout << "Age:  " << employee.age << "\n";
    cout << "Wage: " << employee.wage << "\n";
}
