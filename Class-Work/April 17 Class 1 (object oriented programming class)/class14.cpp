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
class Rectangle
{
    private:
        double length;
    
    public:
        Rectangle(double value)
        {
            cout << "Constructing Rectangle " << endl;
            length = value;
        }
        
        double getLength(void)
        {
            return length;
        } // end of getLength()
}; // end of class Rectangle
          
int main()
{
    double value;
    
    value = getDouble("Enter the length of the rectangle ");
    
    Rectangle myRectangle(value);
    
    cout << "The length is " << myRectangle.getLength() << endl;
    
    system("PAUSE");
    return 0;
} // end of main()
// getDouble function gets user input
double getDouble(string prompt)
{
    double value;
    cout << prompt;
    cin >> value;
    return value;
} // end of getDouble()

