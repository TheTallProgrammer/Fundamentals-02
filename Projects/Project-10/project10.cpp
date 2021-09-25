/* 
Name:     		Logan Falkenberg
Date: 			April 26 2021
Assignment #:	Project 10
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments

This program recieves employees information and outputs tabled data file accordingly.
Wrong values 


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
			int type;
			
			
			
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


float Employee::getInsurance(){
	return insurance;
} // End of getInsurance()


// Getter for the gross pay
float Employee::getGrossPay(){
	
	float grossPay;
	float tax;
	float grossWithTax;
	
	
	if(hoursWorked <= 40){
            grossPay = hourlyPay*hoursWorked;
            tax = grossPay * .15;
            grossWithTax = tax + grossPay;
        }
        else{
            grossPay = 40*(hourlyPay) + 1.5*(hoursWorked - 40)*hourlyPay;
            tax = grossPay * .15;
            grossWithTax = tax + grossPay;
        }
	return grossWithTax;
} // End of getGrossPay()



// Declare structs
struct ErrorEmployees{
	
	int ID;
	
};


// Prototype declarations
bool populateClass(Employee [], int &);
bool readHoursWorked(Employee [], int &, ErrorEmployees [], int &);
bool search(Employee [], int &, int , int &);
void getInsurance(Employee [], int);
void printResults(Employee[], int, ErrorEmployees [], int);
float getTax(Employee [], int);
float getNetPay(Employee [], int );


int main(){
	
	// Declare variables
	const int MAX_SIZE = 25;
	int counter;
	int errorCount;
	
	// Initialize variables
	counter = 0;
	errorCount = 0;
	
	ErrorEmployees errorReport [100];
	Employee emp[MAX_SIZE];
	
	// Call the function and say so if it fails 
	if(populateClass(emp, counter)==false){
		
		cout << "We are back in main telling you again that your function did not work" << endl;
		return 1;
		
	} // End of function call 
	
	cout << "Employee: " << emp[1].getID() << endl;
	
	// Call the function and say so if it fails 
	if(readHoursWorked(emp, counter, errorReport, errorCount)==false){
		
		cout << "We are back in main telling you again that your function did not work" << endl;
		return 1;
		
	} // End of function call
	
	printResults(emp, counter, errorReport, errorCount);
	
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


// Reads the hours worked from a file 
bool readHoursWorked(Employee empID[], int &counter, ErrorEmployees errorReport[], int &errorCount){
	
	// Declare variables
	bool found;
	int ID;
	int x;
	int n;
	float hoursWorked;
	int foundPosition;
	
	ifstream timeFile("trans9.txt");
	
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
		
		if (found && hoursWorked > 0.0){
			
			empID[foundPosition].setHoursWorked(hoursWorked);
			empID[foundPosition].tax = getTax(empID, foundPosition);
			empID[foundPosition].netPay = getNetPay(empID, foundPosition);
			//cout << "ID " << empID[foundPosition].getHoursWorked() << endl;
			found = false;
			
		} else {
			
//			cout << "ID " << ID << " NOT FOUND " << endl;
			errorReport[errorCount].ID = ID;
			
			errorCount++;
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


// Gets the insurance of each employee dependent of the number of dependents that are under them 
void getInsurance(Employee empArray[], int counter){
	
	// Declare variables
	int dependents;
	float insuranceNum;
	
	for (int i = 0; i < counter; i++){
		
		empArray[i].insurance = 30.00 * empArray[i].dependents;
	}
	
} // End of getInsurance


// This function gets the tax of each employee
float getTax(Employee empArray[], int position){
	
	// Declare variables
	float tax;
	float gross;
	
	gross = empArray[position].getGrossPay();
	
	tax = gross * .15;
	
	return tax;
	
} // End of getTax()


// This function gets the netPay of each employee 
float getNetPay(Employee empArray[], int position){
	
	// Declare variables
	float gross;
	float tax;
	float netPay;
	
	gross = empArray[position].getGrossPay();
	
	tax = empArray[position].tax;
	
	netPay = gross - tax;
	
	return netPay;
	
} // End of getNetPay()


// Prints the data that was collected and calculated into a file and the screen
void printResults(Employee empArray[], int numEmp, ErrorEmployees errorReport[], int errorCount){
	
	std::ofstream resultsFile("results.txt");
	
	// Column headers
	resultsFile << fixed << setprecision(2);
	resultsFile << setw(3) << left << "ID" << setw(21) << "Name" << setw(20) << "Hourly Pay" 
	<< setw(20) << "Hours Worked" << setw(10) << "Gross Pay" << setw(15) 
	<< "Dependents"  << setw(12) << "Insurance" << setw(5) << "Tax" << right << setw(12) << "Net Pay" << endl;
	
	for (int i = 0; i < numEmp-1; i++){
		
		// Printing out the information of the employees
		resultsFile << setw(3) << left << empArray[i].getID() << setw(21) 
			<< empArray[i].getName() 
			<< setw(20) << empArray[i].getHourlyPay() 
			<< setw(20) << empArray[i].getHoursWorked() 
			<< empArray[i].getGrossPay() 
			<< setw(20) << right << empArray[i].dependents << setw(15) 
			<< empArray[i].insurance << setw(12) << empArray[i].tax 
			<< right << setw(12) << empArray[i].netPay << endl;
			
		
	}
	
	resultsFile.close();
	
	cout << "\nERROR REPORT\n";
	for (int i = 0; i < errorCount; i++){
		
		cout << "ID: " << errorReport[i].ID << " does not exist or their hours are negative. " << endl;
	}
	
} // End of printResult()





