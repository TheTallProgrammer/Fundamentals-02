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
			
			
			
		public: 
			// Declare/Call functions
			void set(int, string, float);
			int getID();
			string getName();
			float getHourlyPay();
		
		
}; // End of class Employee


// Setter for Employee objects (member function)
void Employee::set(int newID, string newName, float newHourlyPay){
	ID = newID;
	name = newName;
	hourlyPay = newHourlyPay;
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
} // End of getHourlyPay


// Prototype declarations
bool populateClass(Employee []);


int main(){
	
	// Declare variables
	const int MAX_SIZE = 25;
	
	Employee emp[MAX_SIZE];
	
	// Call the function and say so if it fails 
	if(populateClass(emp)==false){
		
		cout << "We are back in main telling you again that your function did not work" << endl;
		return 1;
		
	} 
	
	return 0;
	
} // End of main()


// Function for populating the 
bool populateClass(Employee empArray[]){
	
	// Declare variables
	int counter;
	int newId;
	char newName[20];
	float newHourlyPay;
	
	// Initialize variables
	counter = 0;
	
	// Gets the .txt file
	ifstream inputFile("employee.txt");
	
	// If there is no input file, display an error message
	if (!inputFile){
		
		cout << "Can not open master file \"employee.txt\"" << endl;
		return false;
	}
	
	// Column headers
	cout << setw(3) << left << "ID" << setw(21) << "Name" << setw(10) << left << "Hourly Pay" << endl;
	
	// Read records from the file as long as there are records left to read
	while(!inputFile.eof()){
		
		inputFile >> newId;
		
		inputFile.ignore();
        
        inputFile.get(newName, 20);
        
        inputFile >> newHourlyPay;
        
        empArray[counter].set(newId, newName, newHourlyPay);
		
		// Printing out the information of the employees
		cout << setw(3) << left << empArray[counter].getID() << setw(21) << empArray[counter].getName() 
		<< setw(10) << left << empArray[counter].getHourlyPay() << endl;
		
		// Increment the counter
		counter++;
	}
	
	// Close the file 
	inputFile.close();
	
	return 1;
	
} // End of populateClass()


