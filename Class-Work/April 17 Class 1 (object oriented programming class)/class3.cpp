/* 
Name:     		Logan Falkenberg
Date: 			March 13 2021
Assignment #:	classwork55
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments

A class definition starts with the keyword class followed by the class name; 
and the class body, enclosed by a pair of curly braces. A class definition must be followed either by a semicolon 
or a list of declarations;
The keyword public determines the access attributes of the members of the class that follow it. 
A public member can be accessed from outside the class anywhere within the scope of the class object.

*/

#include <iostream>				// for cin, cout, endl
using namespace std;

// Declare classes

class Box
{
   private:
      double length;   // Length of a box
      double width;  // width of a box
      double height;   // Height of a box
};


int main()
{
	
	// Creating instance of class Box (object)
	Box myBoxOne;
	
	// Declare variables
	double volume;
	
	myBoxOne.length = 3;
	myBoxOne.width = 1;
	myBoxOne.height = 2;
	
	volume = myBoxOne.length * myBoxOne.width * myBoxOne.height;
	
	cout << "Volume: " << volume << endl;
	
    cin.get();
    return 0;
    
}// end of main



