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
		
	write a function that will populate the student struct object until 0 is entered for student ID -- sentinel value
	
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
void getNameGPA(string &, float &, const int, Student []);
int searchArray(const int, int, Student []);
void printNames(const int, Student []);



int main ()
{
    const int MAX_STUDENTS = 25;
    Student student[MAX_STUDENTS];
    string stuName = "\0";
    float stuGPA = 0.0;
    
    
    populateArray(MAX_STUDENTS, student);
    getNameGPA(stuName, stuGPA, MAX_STUDENTS, student);
    
    cout << "Name of student found: " << stuName << "\nGPA of student: " << stuGPA;
    
    
    cin.ignore();
    cin.get();
    return 0;
}


void printNames(const int SIZE, Student stu[])
{
    cout << "Names of the students entered:\n";
    cout << "_____________________________________\n";
    for(int i = 0; i < SIZE; i++)
    {
        if(stu[i].name == "\0")
            break;
        cout << stu[i].name << endl;
    }
}


void getNameGPA(string &name, float &gpa, const int SIZE, Student stu[]){
	
	int id = 0;
	bool found = false;
	int pos;
	
	while(!found){
		
		id = getInt("Please enter the ID of a student");
		
		if (id == 0){
			break;
		}
		
		pos = searchArray(SIZE, id, stu);
		
		if (pos == -1){
			
			cout << "ID not found, please try again\n";
			continue;
		}
		
		name = stu[pos].name;
		gpa = stu[pos].gpa;
		found = true;
		
	}
}


int searchArray(const int SIZE, int target, Student stu[])
{
    int position = -1;
    for(int i = 0; i < SIZE; i++)
    {
        if(stu[i].id == target)
        {
            position = i;
            break;
        }
    }
    return position;
} //end of searchArray


void populateArray(const int size, Student stu[])
{
    int counter = 0;
    int temp = 0;
    while(counter < size)
    {
        temp = getInt("Please enter the students ID or 0 to exit:");
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
