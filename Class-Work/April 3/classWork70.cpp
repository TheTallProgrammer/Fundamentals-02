/* 
Name:     		Logan Falkenberg
Date: 			March 13 2021
Assignment #:	classwork55
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments

uses the principles of try and catch
throws error message and it catches it
*/
#include <iostream>
#include<cmath>
#
using namespace std;

// prototypes
int divide_numbers(int, int);

int main()
{
    int dividend, divisor;
    
    while(true){

	    cout << "Enter dividend: ";
	    cin >> dividend;
	    
	    cout << "Enter divisor: ";
	    cin >> divisor;
	    try
	    {
	        cout << "The quotient is " << divide_numbers(dividend, divisor)  << endl;
	        break;
	    }
	    
	    catch(int& code)
	    {
	        if (code == 1)
	           cout << "ERROR CODE if divisor is zero: " << code  << endl;  
	    }
	    
	    /*
	    A default catch can be made by giving an ellipsis as a parameter - 
	    this should be at the bottom of the chain if there are multiple catchs as it will handle any and all exceptions.
	    */
	    catch(...)
	    {
	        cout << "An unknown error has occurred."  << endl;
	    }
	    
	}
    
    
    cout << "I can add the rest of my codes below " << endl;
   system("PAUSE");
   return 0;
}

int divide_numbers(int num, int den)
{
    if(den == 0)
    
        /* The throw statement behaves much like return. 
        You can (and usually do) pass it a value, and then this value is passed as a parameter into the catch block. 
        Often either int or string-esque data-types are thrown as they can either represent an error code or text explaining the error
        */
        throw 1;         
    return num/den;
}

