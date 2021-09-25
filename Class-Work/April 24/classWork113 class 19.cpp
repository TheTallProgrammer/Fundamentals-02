/* Progress

comments

project 9?

*/

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
			int dependents;
			int type;
			char gender;
			
			
			
		public: 
			// Declare/Call functions
			void set(int, string, float, int, int, char);
			void setHoursWorked(float);
			int getID();
			string getName();
			float getHourlyPay();
			float getHoursWorked();
			int getDependents();
			int getType();
			char getGender();
			float getGrossPay();
		
}; // End of class Employee


// Setter for Employee objects (member function)
void Employee::set(int newID, string newName, float newHourlyPay, int newDependents, int newType, char newGender){
	ID = newID;
	name = newName;
	hourlyPay = newHourlyPay;
	dependents = newDependents;
	type = newType;
	gender = newGender;
} // End of set()

// Setter for setting the hours worked
void Employee::setHoursWorked(float newHoursWorked = 0.0){
	hoursWorked = newHoursWorked;
} // End of setHoursWorked()


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


// Getter for the gender
char Employee::getGender(){
	return gender;
} // End of getGender()




// Getter for the gross pay
float Employee::getGrossPay(){
	
	float grossPay;
	
	if(hoursWorked <= 40){
            grossPay = hourlyPay*(hoursWorked);
        }
        else{
            grossPay = 40*(hourlyPay) + 1.5*(hoursWorked - 40)*hourlyPay;
        }
	return grossPay;
} // End of getGrossPay()


// Prototype declarations
bool populateClass(Employee [], int &);
bool readHoursWorked(Employee [], int &);
bool search(Employee [], int &, int , int &);
void printResults(Employee[], int);


int main(){
	
	// Declare variables
	const int MAX_SIZE = 25;
	int counter;
	
	// Initialize variables
	counter = 0;
	
	Employee emp[MAX_SIZE];
	
	// Call the function and say so if it fails 
	if(populateClass(emp, counter)==false){
		
		cout << "We are back in main telling you again that your function did not work" << endl;
		return 1;
		
	} // End of function call 
	
	// Call the function and say so if it fails 
	if(readHoursWorked(emp, counter)==false){
		
		cout << "We are back in main telling you again that your function did not work" << endl;
		return 1;
		
	} // End of function call
	
	printResults(emp, counter);
	
	return 0;
	
} // End of main()


// Function for populating the 
bool populateClass(Employee empArray[], int &counter){
	
	// Declare variables
	int newId;
	char newName[20];
	float newHourlyPay;
	int newDependents;
	int newType;
	char newGender;
	
	// Gets the .txt file
	ifstream inputFile("master.txt");
	
	// If there is no input file, display an error message
	if (!inputFile){
		
		cout << "Can not open master file \"employee.txt\"" << endl;
		return false;
	}
	
	// Read records from the file as long as there are records left to read
	while(!inputFile.eof()){
		
		inputFile >> newId;
		
		inputFile.ignore();
        
        inputFile.get(newName, 20);
        
        inputFile >> newHourlyPay;
        
        inputFile >> newDependents;
        
        inputFile >> newType;
        
        inputFile >> newGender;
        
        empArray[counter].set(newId, newName, newHourlyPay, newDependents, newType, newGender);
		
		// Increment the counter
		counter++;
	}
	
	// Close the file 
	inputFile.close();
	
	return 1;
	
} // End of populateClass()


// Reads the hours worked from a file 
bool readHoursWorked(Employee empID[], int &counter){
	
	// Declare variables
	bool found;
	int ID;
	float hoursWorked;
	int foundPosition;
	
	ifstream timeFile("trans10.txt");
	
	// Initialize variables
	found = false;
	
	// If there is no input file, display an error message
	if (!timeFile){
		
		cout << "Can not open the time file \"workweek.txt\"" << endl;
		return false;
		
	}
	
	// Read records from the file as long as there are records left to read
	while(!timeFile.eof()){
		
		// Read data from the file on a line
		timeFile >> ID >> hoursWorked;
		
		// Call function search()
		found = search(empID, counter, ID, foundPosition);
		
		if (found){
			
			empID[foundPosition].setHoursWorked(hoursWorked);
			//cout << "ID " << empID[foundPosition].getHoursWorked() << endl;
			found = false;
			
		} else {
			
			cout << "ID " << ID << " NOT FOUND " << endl;
		}
	}
	
	// Close the file
	timeFile.close();
	
	return 1;
	
} // End of readHoursWorked()


// Searches for the correct index
bool search(Employee empID[], int &counter, int target, int &position){
	
	for (int i = 0; i < counter; i++){
		
		if (empID[i].getID() == target){
			
			position = i;
			return true;
		}
	}
	
	// Returns false
	return 0;
	
} // End of serach()


// Prints the data that was collected and calculated
void printResults(Employee empArray[], int numEmp){
	
	// Column headers
	cout << fixed << setprecision(2);
	cout << setw(3) << left << "ID" << setw(21) << "Name" << setw(15) << "Hourly Pay" << setw(15) << "Hours Worked" << setw(15) << "Gross Pay" << endl;
	
	for (int i = 0; i < numEmp; i++){
		
		// Printing out the information of the employees
		cout << setw(3) << left << empArray[i].getID() << setw(21) 
			<< empArray[i].getName() 
			<< setw(15) << empArray[i].getHourlyPay() 
			<< setw(15) << empArray[i].getHoursWorked() 
			<< "$" << setw(10) << empArray[i].getGrossPay() 
			<< endl;
		
	}
	
} // End of printResult()





