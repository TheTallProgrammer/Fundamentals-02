/* 
Name:     		Logan Falkenberg
Date: 			March 27 2021
Assignment #:	classwork61
Status: 		Completed
Language: C++
With whom I got help: 
-------------------------------------------------------------------------
Comments

4 students each having 2 letter grades
*/
#include <iostream>				// for cin, cout, endl
using namespace std;

//prototype declerations
float getData(string);

int main()
{
	int STUDENTS = 3;
	int GRADES = 2;
	int value;
	float average;
	
	average = 0.0;
	
	float grade[STUDENTS] [GRADES];
	
	 for (int rows = 0; rows < STUDENTS; rows++){
	 	
	 	cout << "Student number: " << rows + 1 << endl;
	 	
	 	// populating the cells
	 	for (int cols = 0; cols < GRADES; cols++){
	 		
	 		value = getData("Enter the grade: ");
	 		grade[rows][cols] = value;
	 	}
	 }
	 
	 for (int rows = 0; rows < STUDENTS; rows++){
	 	
	 	cout << "Student Number: " << rows + 1 << endl;
	
	 	average = (grade[rows][0] + grade[rows][1] / 2);
	 	
	 	cout << "\tThe average is " << average << endl;
	 	
	 }
	

	
    cin.ignore();
    return 0;
    
}// end of main



float getData(string prompt){
	
	float value;
	cout << prompt;
	cin >> value;
	return value;
	
}
