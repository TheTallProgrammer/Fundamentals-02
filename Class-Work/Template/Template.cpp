/* 
Name:     		Logan Falkenberg
Date: 			March 13 2021
Assignment #:	classwork55
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments


*/
#include <iostream>				// for cin, cout, endl
using namespace std;

//prototype declerations
int getData(string);

int main()
{
	
    cin.get();
    return 0;
    
}// end of main

// The function getData() gets passed in the prompt and recieves the users input and returns it back to main
int getData(string prompt)
{
	// Declaration of variables
	int value;
	
	// Gets the user's input
	cout << prompt;
	cin >> value;
	
	// Returns value
	return value;
	
	
} // End of getData()

