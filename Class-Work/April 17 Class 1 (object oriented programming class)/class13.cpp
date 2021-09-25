/* 
Name:     		Logan Falkenberg
Date: 			March 13 2021
Assignment #:	classwork55
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments

1. Create a class called Rectangle. 
2. Create a constructor called simple. Constructor means method that will execute when the object is created. 

Program definition
1. Object of simple will be created

A class constructor is a special member function of a class 
that is executed whenever we create new objects of that class.
A constructor will have exact same name as the class 
and it does not have any return type at all, not even void. Constructors can be very useful 
for setting initial values for certain member variables.
*/

#include <iostream>				// for cin, cout, endl
using namespace std;

// Declare classes
class Simple{
	
	private:
		double length;
	
	public:
		Simple(double value){
			
			cout << "Constructing Simple" << endl;
			length = value;
		}
		
		double getLength(void){
			
			return length;
			
		}
		
		
};
          
int main()
{
    Simple mySimple(10);
    
    cout << "The length is " << mySimple.getLength() << endl;
    
    system("PAUSE");
    return 0;
} // end of main()

