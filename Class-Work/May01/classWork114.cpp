/* 
Name:     		Gia Rivera
Date: 			May 01 2021
Assignment #:	classWork114
Status: 		Completed
Language:		C++
-------------------------------------------------------------------------
Comments
Dividing fractions
Create a struct to hold a fraction.
The struct should have an integer numerator and an integer denominator member. 
*/

#include <iostream>				// for cin, cout, endl
#include <string>
 
using namespace std;

// struct definitions
struct Fraction
{
	int numerator;
  	int denominator;
 
}; // end of struct Fraction
 
// function prototypes
int getData(string);
void calculateQuotientOfFractions(Fraction[]);
void output(Fraction[]);
 
int main()
{
	Fraction fraction[3];
 
  	for(int i = 0; i < 2; i++)
  	{
    	fraction[i].numerator = getData("Enter the numerator for fraction " + to_string(i + 1) + ":  ");
    	fraction[i].denominator = getData("Enter the demoninator for fraction " + to_string(i + 1) + ":  ");
  	}
  	
  	calculateQuotientOfFractions(fraction);
 
  	// Call the output funciton
  	output(fraction);
 
} // end of main()
 
// This funciton will prompt the user, get input and return it
int getData(string prompt)
{
  	int value;
  	
  	cout << prompt;
  	cin >> value;
  	
  	return value;
} // end of getData()
 
// This function will calculate the answer
void calculateQuotientOfFractions(Fraction inputFraction[])
{
  	inputFraction[2].numerator = inputFraction[0].numerator * inputFraction[1].denominator;
  	inputFraction[2].denominator = inputFraction[1].numerator * inputFraction[0].denominator;
} // end of calculateAnswer()
 
// This function will check if it's an improper fraction or not then output results
void output(Fraction myOutput[])
{
	int mixed;
 	
 	if(myOutput[2].numerator > myOutput[2].denominator)
 	{
	 	mixed = myOutput[2].numerator / myOutput[2].denominator;
   		myOutput[2].numerator = myOutput[2].numerator % myOutput[2].denominator;
   		cout << "This is a mixed fraction:  " << mixed << " " << myOutput[2].numerator << "/" << myOutput[2].denominator << endl;
 	}
 	else
 	{
    	cout << "This is not a mixed fraction:  " << myOutput[2].numerator << "/" << myOutput[2].denominator << endl;
 	}
} // end of output()
