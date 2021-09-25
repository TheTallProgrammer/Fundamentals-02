/* 
Name:     		Logan Falkenberg
Date: 			March 13 2021
Assignment #:	classwork55
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments

uses the principles of try and catch
throws error message and it catches it
*/
#include<iostream>
using namespace std;

// Prototype
int getData(string);
int main() 
{
    int studentAge;
   
    studentAge = getData("Student Age: ");
    cout << "\nStudent Age: " << studentAge << "\n\n";
    cin.ignore();
    cin.get();
    return 0;
}

int getData(string prompt){
	
	int studentAge;
	
	while (true){
		
       try{
       	
        cin >> studentAge;
        if (studentAge < 0)
            throw "Positive Number Required";
        cout << "\nStudent Age: " << studentAge << "\n\n";
        return studentAge;
    }
    
    catch(const char* Message){
    	
        cout << "Error: " << Message;    
	}
	
    cout << "\n";
   }
	
	return studentAge;
} // End of getData()
