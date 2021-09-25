#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>

using namespace std;


// Declaring class 
class Employee{
		private:
			// Declare variables
			int ID;
			string name;
			float hourlyPay;
			float hoursWorked;
			int type;
			string hashTag;
			char gender;
			
			
			
		public: 
			
			// Delcare variables
			int dependents;
			float insurance;
			float tax;
			float netPay;
			
			// Declare/Call functions
			void set(int, string, float, int, int);
			void setHoursWorked(float);
			int getID();
			string getName();
			float getHourlyPay();
			float getHoursWorked();
			int getDependents();
			int getType();
			char getGender();
			float getInsurance();
			float getTax();
			float getGrossPay();
		
}; // End of class Employee


// Setter for Employee objects (member function)
void Employee::set(int newID, string newName, float newHourlyPay, int newDependents, int newType){
	ID = newID;
	name = newName;
	hourlyPay = newHourlyPay;
	dependents = newDependents;
	type = newType;
} // End of set()


// Getter for the ID 
int Employee::getID(){
	return ID;
} // End of getID()


// Getter for the name
string Employee::getName(){
	return name;
} // End of getName()


// Getter for the hourly pay
float Employee::getHourlyPay(){
	return hourlyPay;
} // End of getHourlyPay()


// Getter for the hours worked
float Employee::getHoursWorked(){
	return hoursWorked;
} // End of getHoursWorked()


// Getter for the dependent number
int Employee::getDependents(){
	return dependents;
} // End of getDependents()


// Getter for the type number
int Employee::getType(){
	return type;
} // End of getType()


bool populateClass(Employee [], int &);


int main(){
	
	// Declare variables
	const int MAX_SIZE = 25;
	int counter;
	int errorCount;
	
	// Initialize variables
	counter = 0;
	errorCount = 0;
	
	Employee emp[MAX_SIZE];
	
	// Call the function and say so if it fails 
	if(populateClass(emp, counter)==false){
		
		cout << "We are back in main telling you again that your function did not work" << endl;
		return 1;
		
	} // End of function call 
	
	cout << "End of populateClass() " << endl;
	
	
//	getInsurance(emp, counter);
//	
//	printResults(emp, counter, errorReport, errorCount);
	
	return 0;
	
} // End of main()


// Function for populating the
bool populateClass(Employee empArray[], int &counter){

int ID;
    char name[20];
    float hourlyPay;
    int numDeps;
    int type;
   
    ifstream inputFile("master9.txt");
   
    // If there is no input file, display error message and return false
    if (!inputFile)
    {
    return false;
    } // end of if
   
    // Read records from the file as long as there are records left to read
    while(!inputFile.eof())
    {    
        inputFile >> ID;
        inputFile.ignore(); // ingore one character between ID and name
        inputFile.get(name, 20, '\n');
        inputFile >> hourlyPay;
        inputFile >> numDeps;
        inputFile >> type;
        inputFile.ignore(2); // skips over the gender info at end of each line in file
       
        cout << "Counter: " << counter + 1 << endl;
		cout << "Employee ID: " << ID << endl;
		cout << "Name: " << name << endl;
		cout << "Salary: " << hourlyPay << endl;
        cout << "newDependents: " << numDeps << endl;
        cout << "newType: " << type << endl;
   
        //empArray[counter] = Employee(ID, name, hourlyPay, numDeps, type);
       
        counter++; // increment the counter of number of employees in file
    } // end of while
   
    inputFile.close();
    return true;  


} // End of populateClass()


