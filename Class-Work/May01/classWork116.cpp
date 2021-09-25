/* 
Name:     		Gia Rivera
Date: 			May 01 2021
Assignment #:	classWork116
Status: 		Completed
Language:		C++
-------------------------------------------------------------------------
Comments
Learning recursion.
Finding LCM and GCD of two numbers.
GCD function uses recursion. 
*/

#include <iostream>
using namespace std;

// function prototypes
int gcd(int, int);
int lcm(int, int);

int main() 
{
    cout<<"LCM" << " = " << lcm(12,16)  << endl;
    cout<<"GCD" << " = " << gcd(12,16)  << endl;
    
    return 0;
}

// gcd() uses recursion to find the greatest common divisor
// (aka greatest common factor) of two integers
int gcd(int valueOne , int valueTwo)
{
    if (valueOne == 0)
        return valueTwo;
    return gcd(valueTwo % valueOne, valueOne);
            //gcd(16 % 12, 12); -> gcd(4, 12)
            //gcd (12 % 4, 12); -? gcd(0, 4)
} // end of gcd()
 
// function to calculate  LCM of two numbers.
int lcm(int valueOne, int valueTwo)
{
    return (valueOne * valueTwo) / gcd(valueOne, valueTwo);
} // end of lcm()
