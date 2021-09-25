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
			char gender;
			
			
			
		public: 
			
			// Delcare variables
			int dependents;
			float insurance;
			float tax;
			float netPay;
			
			// Declare/Call functions
			void set(int, string);
			int getID();
			string getName();

		
}; // End of class Employee


// Setter for Employee objects (member function)
void Employee::set(int newID, string newName){
	ID = newID;
	name = newName;
} // End of set()


// Getter for the ID 
int Employee::getID(){
	return ID;
} // End of getID()


// Getter for the name
string Employee::getName(){
	return name;
} // End of getName()


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
	
	
//	getInsurance(emp, counter);
//	
//	printResults(emp, counter, errorReport, errorCount);
	
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
        
        empArray[counter].set(newId, newName);
		
		cout << "Employee: " << empArray[counter].getID() << endl;
		cout << "Employee: " << empArray[counter].getName() << endl;
		// Increment the counter
		counter++;
	}
	
	// Close the file 
	inputFile.close();
	
	return 1;
	
} // End of populateClass()

