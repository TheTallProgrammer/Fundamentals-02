/* 
Name:     		Gia Rivera
Date: 			May 01 2021
Assignment #:	classWork115
Status: 		Completed
Language:		C++
-------------------------------------------------------------------------
Comments
Learning recursion.
Finding factorial of a number using recursion.
*/

#include <iostream>
using namespace std;

// function prototypes
int factorial(int);

int main() 
{
	int number;
	
	cout<<"Enter a number to find factorial: ";
    cin>>number;
    cout<<"Factorial of " << number <<" = "<< factorial(number);
    
    return 0;
} // end of main()

// factorial() finds the factorial of a number using recursion
int factorial(int num) 
{
    if (num  > 1) 
	{
        return num * factorial(num - 1);
    }
    else 
	{
        return 1;
    }
} // end of factorial()
