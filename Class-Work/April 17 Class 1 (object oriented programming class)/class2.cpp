/* 
Name:     		Logan Falkenberg
Date: 			March 13 2021
Assignment #:	classwork55
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments

Learning about classes

*/
#include <iostream>				// for cin, cout, endl
using namespace std;



class Programming 
{
	public: // needs to have a colon
  		void output(); // This prototype must be created if the function (method) is defined outside the scope of the class
  		
  		// ** Another way to create a method of the class **
//  		void output() // method, but actually a function 
//  			{
//  				cout << "Methods defined inside the class.\n";
//  			} // End of output

}; // End of class programming, must have a semi colon

// This is a method that belongs to the class programming, it only prints 
void Programming::output() // method, but actually a function 
  			{
  				cout << "Methods defined inside the class.\n";
  			} // End of output

int main()
{
	
	Programming myObject; // Creating an instance of the class programming 
	
	myObject.output(); // Calling a method inside of the class programming
	
    cin.get();
    return 0;
    
}// end of main



