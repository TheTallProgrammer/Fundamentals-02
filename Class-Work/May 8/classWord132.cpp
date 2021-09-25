/* 
Name:     		Logan Falkenberg
Date: 			May 01 2021
Assignment #:	classWork127
Status: 		Completed
Language:		C++
-------------------------------------------------------------------------
Comments
write a class with the following member type:
	int for student ID
	string for student name [20]
	array of 3 for student grade 
	char for letter grade

	
	write a declaration statement for the struct
		Maximum students = 25
		
	write a function that will populate the student class object until 0 is entered for student ID -- sentinel value
	
	write a method that will find the letter grade
	
	have a function to print the names 
	
	
*/

#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Student
{
    private:
        const int charNameLimit = 20;
        const int gradeArraySize = 3;
        int id;
        char name[20];
        int *grade;
        char letterGrade;
        int getGradeAverage();
    public:
        Student();
        ~Student();
        int setID(int);
        //1-line member function to return ID
        int getID() { return id; }
        //1-line member function to return the limit for the name length --shouldn't change!
        int getNameLimit() const { return charNameLimit; }
        //1-line member function to return maximum grade array size --shouldn't change!
        int getGradeSize() const { return gradeArraySize; }
        void setName(char [20]);
        //1-line member function to return name char string
        char * getName() { return name;};
        char getLetterGrade();
        void setGrades(int *);
};

//constructor intializes pointer array
Student::Student()
{
    grade = new int[gradeArraySize];
}
//destructor to clear up pointer memory used
Student::~Student() //~signifies destructor
{
    delete[] grade;
}
//member function to get the average of all provided grades
int Student::getGradeAverage()
{
    int sum = 0;
    for(int i = 0; i < gradeArraySize; i++)
    {
        sum += grade[i];
    }
    return sum / gradeArraySize;
}

//member function to find the letter grade based on found average
char Student::getLetterGrade()
{
    int average = getGradeAverage();
    cout << average << endl;
    if(average >= 90)
        return 'A';
    else if(average >= 80)
        return 'B';
    else if(average >= 70)
        return 'C';
    else if(average >= 60)
        return 'D';
    else
        return 'F';
}
//member function to set grades
void Student::setGrades(int *grades)
{
    grade = grades;
}
//member function to set new name value (limited to 20 char)
void Student::setName(char newName[20])
{
    strcpy(name, newName);
}
//member function to set new id if greater than 0
int Student::setID(int newID)
{
    if(newID > 0)
    {
        id = newID;
        return 0;
    }
    else
        return 1;
}

//prototypes
int getInt(string);
void populateArray(const int, Student [], int &);
char * getCStr(string, const int);
float getFloat(string);
int searchArray(const int, int, Student []);
void printNameGrade(int, Student []);
int main ()
{
    const int MAX_STUDENTS = 25;
    Student student[MAX_STUDENTS];
    string stuName = "\0";
    float stuGPA = 0.0;
    int studentsEntered = 0;
    populateArray(MAX_STUDENTS, student, studentsEntered);
    printNameGrade(studentsEntered, student);
    cin.ignore();
    cin.get();
    return 0;
}

//function to print results of processing
void printNameGrade(int size, Student stu[])
{
    cout << "Name and grade of student:\n";
    for(int i = 0; i < size; i++)
    {
        cout << "Name: " << stu[i].getName() << endl;
        cout << "Letter grade: " << stu[i].getLetterGrade() << endl;
    }
}

//function to populate Student type array of objects
//keeps a count of the number of objects entered
void populateArray(const int SIZE, Student stu[], int &stuEntered)
{
    int counter = 0;
    int temp;
    int gradeArraySize = stu->getGradeSize();
    int *tempGrades;
    tempGrades = new int[gradeArraySize];
    while(counter < SIZE)
    {
        temp = getInt("Please enter an integer or 0 to exit:");
        if(temp == 0)
            break;
        stu[counter].setID(temp);
        stu[counter].setName(getCStr("Please enter the student's name:", stu[counter].getNameLimit()));
        for(int i = 0; i < gradeArraySize; i++)
        {
            tempGrades[i] = getInt("Please enter the student's score:");
        }
        stu[counter].setGrades(tempGrades);
        counter++;
    } //end while
    stuEntered = counter;
}


//simple function to prompt for and return float value
float getFloat(string prompt)
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
            cout << "That's not an number! Please try again.\n";
        }
        else
            break;
    }
    return value;
} //end of get float

//function to prompt for and return string value
char * getCStr(string prompt, const int sizeLimit)
{
    char *value;
    value = new char[sizeLimit];
    cout << prompt << endl;
    cin.ignore(100, '\n'); //clear newlines from buffer before getting input
    cin.getline(value, sizeLimit);
    return value;
} //end of getStr

//function to prompt for and return an int value
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
} //end of getInt
