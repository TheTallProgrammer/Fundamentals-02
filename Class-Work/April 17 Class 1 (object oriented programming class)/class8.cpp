/* 
Name:     		Logan Falkenberg
Date: 			March 13 2021
Assignment #:	classwork55
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments

Class definition
1. Create a class Triangle. 
2. Two Private data attiributes (base, height)
3. Public method findArea() will be created

Program definition
1. An object of Triangle will be created, 
2. 2 data attributes will be entered by the user
3. findArea() method will be called
4. Print the area of the triangle
*/

#include <iostream>				// for cin, cout, endl
using namespace std;

// Declare classes

class Triangle
{
    private:
        double base;
        double height;
        
    public:
        double getArea(); // prototype of the method called outside of the class
        void setBase(double base);
        void setHeight(double height);
        
        
}; // end of class Triangle


// this method finds the area of the triangle

void Triangle::setBase(double value){
	base = value;
} // End of setBase()

void Triangle::setHeight(double value){
	height = value;
} // End of setHeight()

double Triangle::getArea() // the method is outside the scope of the class
{
    return 0.5 * base * height;
} // end of getArea()
        
// prototype declaration
double getDouble(string);
          
int main()
{
    Triangle myTriangle;
    double area;
    double base;
    double height;
    
    base = getDouble("Enter the base of the triangle ");
    height = getDouble("Enter the height of the triangle ");
    
    myTriangle.setBase(base); // Assigning value of the base using setBase()
    myTriangle.setHeight(height); // Assigning value of the height using setHeight()
    
    area = myTriangle.getArea();
    
    cout << "The area of the triangle is " << area << endl;
    
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
