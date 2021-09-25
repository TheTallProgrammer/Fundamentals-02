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
int main() 
{
    while (true)
    {
        try
        {
            double value;
            cout << "Enter a number more than 0 (no negative number): ";
            cin >> value;
        
            if (value < 0) 
                throw "Negative square root is imaginery!";
            
            cout << "Square root of " << value <<  " is " << sqrt(value) << endl;
            break;   
        }
        catch(char const *str)
        {
            cout << str  << endl;
        }
    }
    cin.ignore();
    cin.get();
    return 0;
}

