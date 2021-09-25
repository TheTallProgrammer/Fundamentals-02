/* 
Name:     		Logan Falkenberg
Date: 			April 15 2021
Assignment #:	Project 7
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments

This program recives students names and test scores to determine the average of the class and their letter grades

*/


#include <string>
#include <iomanip>      // std::setprecision
#include <iostream>				// for cin, cout, endl
using namespace std;


// Declare structs
struct Student{
	
	string name;
	int scoreOne;
	int scoreTwo;
	int scoreThree;
	char letterGrade;
	float iAverage;
	
};


//prototype declerations
void getStudents(int &);
void getNameAndGrades(Student [], int);
void rearrange(Student [], int);
float getAverage(Student [], int);
void getLetterGrade(Student [], int);
void printData(Student [], int, float);


int main()
{
	
	// Declare variables
	int size;
	float average;
	
	// Calls function getStudents
	getStudents(size);
	
	// Dynamically sets the array size based off of the number of students
	Student students [size];
	
	// Calls function getNameAndGrades
	getNameAndGrades(students, size);
	
	// Calls function rearrange()
	rearrange(students, size);
	
	// Calls function getAverage()
	average = getAverage(students, size);
	
	// Calls function getLetterGrade()
	getLetterGrade(students, size);
	
	// Calls function printData()
	printData(students, size, average);
	
    cin.get();
    return 0;
    
}// end of main


// Gets the number of students that the program will be getting test scores for 
void getStudents(int &size){
	
	cout << "Enter number of students: ";
	cin >> size;
	cout << "\n";
	
} // End of getStudents()


// Gets the name and grades of each student in the dynamic array
void getNameAndGrades(Student students[], int size){
	
	// Declare variables
	char n[30];
	string name;
	bool incorrect;
	
	// Initialize variables
	incorrect = false;
	
	for (int i = 0; i < size; i++){
		
		cin.get();
		
		// Gets information of this specific student
		cout << "Student #" << i+1 << endl;
		
		cout << "Enter the name: ";
		
		cin.get(n, 30);
    	cin.get();
    	
    	name = n;
    	
    	// Initializes the students name to that specific element (student)
    	students[i].name = name;
    	
    	// Gets the scores of the students tests 1-3
    	cout << "Enter the grade for test 1: ";
    	cin >> students[i].scoreOne;
    	
    	// Checking to see if the score if 0-110
    	if(students[i].scoreOne < 0 || students[i].scoreOne > 110){
    		incorrect = true;
    		
    		while(incorrect){
    			
				// Says error
				cout << "That grade isn't in the correct value range (0-110) \n";
    			
    			// Gets the scores of the students tests 1-3
		    	cout << "Enter the grade for test 1: ";
		    	cin >> students[i].scoreOne;
		    	
		    	// Tests to see if the value is correct on the new input
		    	if (students[i].scoreOne > 0 && students[i].scoreOne <= 110){
		    		incorrect = false;
		    		
				}
			}
		}
    	
    	cout << "Enter the grade for test 2: ";
    	cin >> students[i].scoreTwo;
    	
    	// Checking to see if the score if 0-110
    	if(students[i].scoreTwo < 0 || students[i].scoreTwo > 110){
    		incorrect = true;
    		
    		while(incorrect){
    			
				// Says error
				cout << "That grade isn't in the correct value range (0-110) \n";
    			
    			// Gets the scores of the students tests 1-3
		    	cout << "Enter the grade for test 2: ";
		    	cin >> students[i].scoreTwo;
		    	
		    	// Tests to see if the value is correct on the new input
		    	if (students[i].scoreTwo > 0 && students[i].scoreTwo <= 110){
		    		incorrect = false;
		    		
				}
			}
		}
    	
    	cout << "Enter the grade for test 3: ";
    	cin >> students[i].scoreThree;
    	
    	// Checking to see if the score if 0-110
    	if(students[i].scoreThree < 0 || students[i].scoreThree > 110){
    		incorrect = true;
    		
    		while(incorrect){
    			
				// Says error
				cout << "That grade isn't in the correct value range (0-110) \n";
    			
    			// Gets the scores of the students tests 1-3
		    	cout << "Enter the grade for test 3: ";
		    	cin >> students[i].scoreThree;
		    	
		    	// Tests to see if the value is correct on the new input
		    	if (students[i].scoreThree > 0 && students[i].scoreThree <= 110){
		    		incorrect = false;
		    		
				}
			}
		}
    	
    	cout << "\n";
		
	}
} // End of getNameAndGrades()


// Rearranges the values of the grades in acending order
void rearrange(Student students [], int size){
	
	// Declare variables
	int temp;
	
	for (int i = 0; i < size; i++){
		// Checks the 1,2 scores
		if (students[i].scoreOne > students[i].scoreTwo){
			temp = students[i].scoreOne;
			students[i].scoreOne = students[i].scoreTwo;
			students[i].scoreTwo = temp;
		}
		
		// Checks the 2,3 scores
		if (students[i].scoreTwo > students[i].scoreThree){
			temp = students[i].scoreTwo;
			students[i].scoreTwo = students[i].scoreThree;
			students[i].scoreThree = temp;
		}
		
		// Checks the 1,2 scores
		if (students[i].scoreOne > students[i].scoreTwo){
			temp = students[i].scoreOne;
			students[i].scoreOne = students[i].scoreTwo;
			students[i].scoreTwo = temp;
		}
		
		// Checks the 2,3 scores
		if (students[i].scoreTwo > students[i].scoreThree){
			temp = students[i].scoreTwo;
			students[i].scoreTwo = students[i].scoreThree;
			students[i].scoreThree = temp;
		}
	}
} // End of rearrange


// This function returns the average score of all of the students tests
float getAverage(Student students [], int size){
	
	// Declare variables
	float average;
	
	for (int i = 0; i < size; i++){
		
		// Gets the average of the entire class
		average = average + students[i].scoreOne + students[i].scoreTwo + students[i].scoreThree;
		
		// Gets the average of each individual student 
		students[i].iAverage = (students[i].scoreOne + students[i].scoreTwo + students[i].scoreThree) / 3;
		
	}
	
	average = average / (size * 3);
	
	// Returns the average
	return average;
	
} // End of getAverage()


// This function will give the student their overall letter grade based on their average score in the class
void getLetterGrade(Student students [], int size){
	
	for (int i = 0; i < size; i++){
		if (students[i].iAverage >= 90){
			students[i].letterGrade = 'A';
		} else if (students[i].iAverage <= 89 && students[i].iAverage >= 80){
			students[i].letterGrade = 'B';
		} else if (students[i].iAverage <= 79 && students[i].iAverage >= 70){
			students[i].letterGrade = 'C';
		} else {
			students[i].letterGrade = 'D';
		}
	}
} // End of getLetterGrade()


// This function prints all of the data that was collected in a formated output
void printData(Student students[], int size, float average){
	
	cout << left << setw(30) << "Name" << setw(5) << "Scores" << "       " << "Letter Grade" << endl;
	
	for (int i = 0; i < size; i++){
		
		cout << setw(30) << left << students[i].name << students[i].scoreOne << "," << students[i].scoreTwo << "," << students[i].scoreThree << "     " << students[i].letterGrade << endl;
	}
	
	cout << "_______________________________________________________" << endl;
	cout << "Average                       " << fixed << std::setprecision(2) << average << endl;
		
} // End of printData()

