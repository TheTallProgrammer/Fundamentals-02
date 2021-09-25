/* 
Name:     		Logan Falkenberg
Date: 			March 27 2021
Assignment #:	classwork56
Status: 		Completed
Language: C++
With whom I got help: 
-------------------------------------------------------------------------
Comments

size of students in the class is 10
populate their grades
*/
#include <iostream>				// for cin, cout, endl
using namespace std;

//prototype declerations
float getGrades(string);
void populateGrades(int []);

int main()
{
	// Creates an array with size 5

	int grades[10];
	
	populateGrades(grades);
	
    cin.get();
    return 0;
    
}// end of main

void populateGrades(int grades[]){
	
	for (int x = 0; x < 10; x++){
		grades[x] = getGrades("Enter a grade: ");
	}
}

float getGrades(string prompt){
	
	float value;
	cout << prompt;
	cin >> value;
	return value;
}
