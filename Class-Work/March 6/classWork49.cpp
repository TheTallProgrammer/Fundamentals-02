/* 
Name:     		Logan Falkenberg
Date: 			March 6 2021
Assignment #:	classWork47
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments

*/
#include <iostream>				// for cin, cout, endl
#include <math.h> // Can also put <cmath>
using namespace std;

//prototype declerations
float getData(string);
float findDiscriminant(float, float, float);
void findRoots(float, float, float, float);

int main()
{
	
	float sideA;
	float sideB;
	float sideC;
	float discriminant;
	
	sideA = getData("Enter side A: ");
	sideB = getData("Enter side B: ");
	sideC = getData("Enter side C: ");

	discriminant = findDiscriminant(sideA, sideB, sideC);
	
	findRoots(sideA, sideB, sideC, discriminant);

	// Ends the function 
    cin.get();
    return 0;
    
}// end of main

void findRoots(float a, float b, float c, float discriminant){
	
	float rootOne;
	float rootTwo;
	
	if (discriminant < 0){
		cout << "Roots: imaginary" << endl;
	} else {
		
		rootOne = (-b + sqrt(discriminant)) / 2;
		rootTwo = (-b - sqrt(discriminant)) / 2;
		
		cout << "Root One: " << rootOne << " \nRoot Two: " << rootTwo << endl;
	}
	
}

// Function getData() will receive an input from the user and return it back to the main function
float getData(string prompt){
	
	float value;
	
	cout << prompt;
	cin >> value;
	
	return value;
	
} // End of getData()

float findDiscriminant(float a, float b, float c){
	
	return b * b - 4 * a * c;
	
}

