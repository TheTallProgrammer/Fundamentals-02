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
  		void output() // method, but actually a function 
  			{
  				cout << "Methods defined inside the class.\n";
  			} // End of output

}; // End of class programming, must have a semi colon


int main()
{
	
	Programming myObject; // Creating an instance of the class programming 
	
	myObject.output(); // Calling a method inside of the class programming
	
    cin.get();
    return 0;
    
}// end of main



