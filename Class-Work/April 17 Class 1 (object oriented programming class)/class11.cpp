/* 
Name:     		Logan Falkenberg
Date: 			March 13 2021
Assignment #:	classwork55
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments

1. Create a class called Rectangle. 
2. Two PRIVATE data attributes: length and width.
3. PUBLIC Method findArea() will be created.
4. Create Setters to set the value of the PRIVATE data attributes.
5. Create Getters to access the PRIVATE data attributes.

Program definition
1. Object of Rectangle will be created.
2. Two values will be entered by users and assigned to the data attributes using Setters.
3. findArea() method will be called.
4. Print the data attributes using Getters.
5. Print the area.
*/

#include <iostream>				// for cin, cout, endl
using namespace std;

// Declare classes
class Rectangle
{
    private:
        double length;
        double width;
    
    public:
        // this method will return the value of the length attribute
        double getLength(void)
        {
            return length;
        } // end of getLength()
        // this method will return the value of the width attribute
        double getWidth(void)
        {
            return width;
        } // end of getWidth()
        // this method will assign the value of the length attribute
        void setLength(double value)
        {
            length = value;
        } // end of setLength()
        // this method will assign the value of the width attribute
        void setWidth(double value)
        {
            width = value;
        } // end of setWidth()
        double getArea() // the method is outside the scope of the class
        {
            return length * width;
        } // end of getArea()    
}; // end of class Rectangle
       
// prototype declaration
double getDouble(string);
          
int main()
{
    Rectangle myRectangle;
    double area;
    double length;
    double width;
    
    length = getDouble("Enter the length of the rectangle ");
    width = getDouble("Enter the width of the rectangle ");
    
    myRectangle.setLength(length); // assigning the value of length using method setLength()
    myRectangle.setWidth(width); // assigning the value of width using method setWidth()
    
    area = myRectangle.getArea();
    
    cout << "\nResults" << endl;
    cout << "The length is " << myRectangle.getLength() << endl;
    cout << "The width is " << myRectangle.getWidth() << endl;
    cout << "The area of the rectangle is " << area << endl;
    
    system("PAUSE");
    return 0;
} // end of main()
double getDouble(string prompt)
{
    double value;
    cout << prompt;
    cin >> value;
    return value;
} // end of getDouble()
