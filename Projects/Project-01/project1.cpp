/* 
Name:     		Logan Falkenberg
Date: 			Jan 30
Assignment #:	Project 1
Status: 		Completed
-------------------------------------------------------------------------
Comments:
	Write a C++ program that reads 2 integer values from the keyboard (be sure to
	print a prompt message for the user). The program calculates and prints the
	following:
		* the sum of the integers
		* the product of the integers
		* the average of the integers
		* the quotient of the integers
		* the remainder of the integers
		* Be sure to include identifying labels with your output. 
		
	User’s Entry
	Enter an integer value 29
	Enter another integer value 8


*/

#include <iostream>				// for cin, cout, endl
using namespace std;

//prototype declerations


int main()
{
	// decleration of variables 
    int inputNumber1;
    int inputNumber2;
    float sum;
    float product;
    float average;
    float quotient;
    float remainder;
    
    // input section
    // First Integer
    cout << "Enter an integer value: ";
    cin >> inputNumber1;
    
    // Second Integer
    cout << "Enter another integer value: ";
    cin >> inputNumber2;
    
    // calculation section
	sum = inputNumber1 + inputNumber2;
	product = inputNumber1 * inputNumber2;
	average = (inputNumber1 + inputNumber2) / 2;
	quotient = inputNumber1 / inputNumber2;
	remainder = inputNumber1 % inputNumber2;
	
	// displays the results
	cout << endl << "Results" << endl;
	cout << "The sum of "  << inputNumber1 << " and " << inputNumber2 << " is " << sum << endl;
	cout << "The product of "  << inputNumber1 << " and " << inputNumber2 << " is " << product << endl;
	cout << "The average of "  << inputNumber1 << " and " << inputNumber2 << " is " << average << endl;
	cout << "The quotient of "  << inputNumber1 << " and " << inputNumber2 << " is " << quotient << endl;
	cout << "The remainder after dividing "  << inputNumber1 << " by " << inputNumber2 << " is " << remainder << endl;
	
    
    system("PAUSE");
    return 0;
    
}// end of main()

