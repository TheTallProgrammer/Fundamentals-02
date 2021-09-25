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
	
	write a declaration statement for the struct
		Maximum students = 25
		
	write a function that will populate the struct 
	
	write a function that will ask the user for a student ID
		Will return student name and GPA 
	
	
*/

#include <iostream>
using namespace std;
/*
pointers and arrays are not completely interchangeable.
*/

struct Student{
	
	const int GRADE_ARRAY_SIZE = 3;
	int id;
	string name;
	int age;
	int grades [3];
	float gpa;
	int date;
	float classCost;
	
};

void populateArray(const int, Student []);
int getInt(string);
string getStr(string);
int getFloat(string);



int main ()
{
    const int MAX_STUDENTS = 25;
    Student student[MAX_STUDENTS];
    populateArray(MAX_STUDENTS, student);
    return 0;
}


void populateArray(const int size, Student stu[])
{
    int counter = 0;
    int temp = 0;
    while(counter < size)
    {
        temp = getInt("Please enter an integer or 0 to exit:");
        if(temp == 0)
            break;
        stu[counter].id = temp;
        stu[counter].name = getStr("Please enter the student's name:");
        stu[counter].age = getInt("Please enter the student's age:");
        stu[counter].gpa = getFloat("Please enter the student's GPA:");
        stu[counter].classCost = getFloat("Please enter the class cost:");
       
        //cout << "Student id: " << stu[counter].id << "\nStudent name: "
        //    << stu[counter].name << "\nStudent age: " << stu[counter].age
        //    << "\nStudent GPA: " << stu[counter].gpa << "\nClass cost: "
        //    << stu[counter].classCost << endl;
        for(int i = 0; i < stu->GRADE_ARRAY_SIZE; i++)
        {
            stu[counter].grades[i] = getInt("Please enter the student's score:");
            //cout << "Entered grade: " << stu[counter].grade[i] << endl;
        }
        counter++;
    }
    
}


int getInt(string prompt)
{
    int value;
    while(true)
    {
        cout << prompt << endl;
        cin >> value;
        if(!cin)
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "That's not an integer! Please try again.\n";
        }
        else
            break;
    }
    return value;
}


int getFloat(string prompt)
{
    float value;
    while(true)
    {
        cout << prompt << endl;
        cin >> value;
        if(!cin)
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "That's not a number! Please try again.\n";
        }
        else
            break;
    }
    return value;
}



string getStr(string prompt){
	
	string value;
	
	cin.ignore(100, '\n');
	
	cout << prompt << endl;
	
	getline(cin, value);
	
	return value;
	
	
}
