/* 
Name:     		Gia Rivera
Date: 			May 01 2021
Assignment #:	classWork117
Status: 		Completed
Language:		C++
-------------------------------------------------------------------------
Comments
Dividing fractions
Create a struct to hold a fraction.
The struct should have an integer numerator and an integer denominator member. 
*/

#include <iostream>				// for cin, cout, endl
#include <fstream>
#include <iomanip>
#include <string>
 
using namespace std;
 
struct Fraction
{
  int numerator;
  int denominator;
 
};
 
//function prototypes
int getData(string);
void calculateSumOfFractions(Fraction[]);
void output(Fraction[]);
int gcd(int, int);
int lcm (int, int);
 
int main()
{
  Fraction fraction[3];
 
  for(int i = 0; i < 2; i++)
  {
    fraction[i].numerator = getData("Enter the numerator for fraction " + to_string(i + 1) + ": ");
    fraction[i].denominator = getData("Enter the denominator for fraction " + to_string(i + 1) + ": ");
  }
  
  calculateSumOfFractions(fraction);
 
  // Call the output funciton
  output(fraction);
 
} // end of main()
 
// This funciton will prompt the user, get input and return it
int getData(string prompt)
{
  	int value;
  
  	do
  	{
  		cout << prompt;
  		cin >> value;
  		
  		if (value == 0)
  		{
    		cout << "No dice.  Try again:  ";
  		}
  	} while(value <= 0);
 
  	return value;
} // end of getData()
 
// This function will calculate the answer
void calculateSumOfFractions(Fraction inputFraction[])
{
  	int lowestCommonDenominator; 
  	int greatestCommonMultiple;
  	int factor1;
  	int factor2;
  
  	lowestCommonDenominator = lcm(inputFraction[0].denominator, inputFraction[1].denominator);
  	factor1 = lowestCommonDenominator / inputFraction[0].denominator;
  	factor2 = lowestCommonDenominator/ inputFraction[1].denominator;
 
  	inputFraction[2].numerator = (inputFraction[0].numerator * factor1) + (inputFraction[1].numerator * factor2);
  	inputFraction[2].denominator = lowestCommonDenominator;
 
  	greatestCommonMultiple = gcd(inputFraction[2].denominator, inputFraction[2].numerator);
  	
  	if (greatestCommonMultiple % 2 == 0)
  	{
    	inputFraction[2].denominator = greatestCommonMultiple;
  	}
}// end of calculateSumOfFractions()
 
// This function will check if it's an improper fraction or not then output results
void output(Fraction myOutput[])
{
  	int mixed;
 
 	if (myOutput[2].numerator > myOutput[2].denominator)
 	{
   		mixed = myOutput[2].numerator / myOutput[2].denominator;
   		myOutput[2].numerator = myOutput[2].numerator % myOutput[2].denominator;
   		cout << "This is a mixed fraction:  " << mixed << " " << myOutput[2].numerator << "/" << myOutput[2].denominator << endl;
 	}
 	else if(myOutput[2].numerator == myOutput[2].denominator)
 	{
  		cout << "Result is a whole number: "  << myOutput[2].numerator / myOutput[2].denominator << endl; 
 	} // end of else if
 	else
 	{
    	cout << "This is not a mixed fraction:  " << myOutput[2].numerator << "/" << myOutput[2].denominator << endl;
 	} // end of else
} // end of output()
 
// function to find greatest common denominator 
int gcd(int valueOne , int valueTwo) 
{ 
	if (valueOne == 0) 
    return valueTwo; 
    return gcd(valueTwo % valueOne, valueOne); 
} // end of gcd()

// function to find LCM of two numbers 
int lcm(int valueOne, int valueTwo) 
{ 
	return (valueOne * valueTwo) / gcd(valueOne, valueTwo); 
} // end of lcm()
