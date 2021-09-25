/* 
Name:     		Logan Falkenberg
Date: 			May 01 2021
Assignment #:	classWork127
Status: 		Completed
Language:		C++
-------------------------------------------------------------------------
Comments
write a struct with the following member type:
	int for student ID
	string for student name
	array of 3 for student grade 
	float for student GPA
	int for student date
	float for class cost
	
*/

#include <iostream>
using namespace std;
/*
pointers and arrays are not completely interchangeable.
*/

struct Student{
	
	int id;
	string name;
	float grades [3];
	float gpa;
	int date;
	float classCost;
	
};


int main ()
{
	
	// Declaration of the struct
	Student student;

    
	system("PAUSE");
    return 0;
} // end of main()
