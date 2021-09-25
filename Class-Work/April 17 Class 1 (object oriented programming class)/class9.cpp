/* 
Name:     		Logan Falkenberg
Date: 			March 13 2021
Assignment #:	classwork55
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments

1. Create a class called Triangle. 
2. Two PRIVATE data attributes: base and height.
3. PUBLIC Method findArea() will be created.
4. Create Setters to set the value of the PRIVATE data attributes.
5. Create Getters to access the PRIVATE data attributes.

Program definition
1. Object of Triangle will be created.
2. Two values will be entered by users and assigned to the data attributes using Setters.
3. findArea() method will be called.
4. Print the data attributes using Getters.
5. Print the area.
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
        double getBase(void);
        double getHeight(void);
        
        
}; // end of class Triangle


// This method will return the value of the base attribute
double Triangle::getBase(void){
	
	return base;
	
} // end of getBase()

// This method will return the value of the base attribute
double Triangle::getHeight(void){
	
	return base;
	
} // end of getHeight()

// This method will assign the value of the base attribute
void Triangle::setBase(double value){
	base = value;
} // End of setBase()

// This method will assign the value of the height attribute
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
    
    cout << "\nResults" << endl;
    
    cout << "The base is " << myTriangle.getBase() << endl;
    cout << "The height is " << myTriangle.getHeight() << endl; 
    
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
