/* 
Name:     		Logan Falkenberg
Date: 			March 6 2021
Assignment #:	classWork46
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments
Find factorial of a number 
users will be asked for the number and it will print out the factorial
*/
#include <iostream>				// for cin, cout, endl
using namespace std;

//prototype declerations
int getData(string);
int getFactorial(int);


int main()
{
	
	int value;
	int factorialValue;
	
	value = getData("Enter a value: ") << endl;
	
	factorialValue = getFactorial(value);
	
	cout << "The factorial of " << value << " is " << factorialValue << endl;
	

	// Ends the function 
    cin.get();
    return 0;
    
}// end of main

int getData(string prompt){
	
	int value;
	
	cout << prompt << endl;
	cin >> value;
	
	return value;
	
} // End of getData()

int getFactorial(int value){
	
	int factorialVal;
	
	factorialVal = 1;
	
	for (int i = value; i >= 1; i--){
		factorialVal = factorialVal * i;
	}
	
	return factorialVal;
	
} // End of getFactorial


