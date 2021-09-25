/* 
Name:     		Logan Falkenberg
Date: 			Feb 27 2021
Assignment #:	classWork38
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments


*/
#include <iostream>				// for cin, cout, endl
using namespace std;

//prototype declerations
void getTransaction(string, float &, char &);

int main()
{
	// decleration of variables
	char transactionType;
	float transactionAmount;
	float balance;
	string prompt;
	float checkSC;
	
	// Gets the user's beginning balance
	cout << "Enter the beginning balance: ";
	cin >> balance;
	
	// Prompt for the main menu 
	prompt = "\n_______________________________________\nSelect Transaction Type:\nC - Process a check\nD - Process a deposit\nE - Exit\n\nEnter a transaction: ";
	
	// Calls the function getTransaction to start the user's transaction process
	getTransaction(prompt, transactionAmount, transactionType);
	
	// Main loop for all remaining transactions, exits when the user types E to exit
	while(transactionType == 'D' || transactionType == 'C'){
		if (transactionType == 'D'){
			cout << "deposit" << endl;
			// Deposit do something
		} else {
			cout << "check for $" << transactionAmount <<endl;
			
			// Check do something
		}
		getTransaction(prompt, transactionAmount, transactionType);
	} // End of the main while-loop
	
	
	
	cout << "I am exiting the Data entry loop" << endl;
	
	
	// Ends the function 
    cin.get();
    return 0;
    
}// end of main

// This function will get users input for a transaction type, and pass by reference the variables needed to process the transaction
void getTransaction(string prompt, float &transactionAmount, char &transactionType)
{	
	cout << prompt;
	cin >> transactionType >> transactionAmount;
	transactionType = toupper(transactionType);
	
	// While no correct transaction has been made
	while (transactionType != 'D' && transactionType != 'E' && transactionType != 'C'){
		cout << "Incorrect transaction. Try again." << endl;
		cout << prompt;
		cin >> transactionType >> transactionAmount;
		// toupper makes chars upper case
		transactionType = toupper(transactionType);
	}
	
} // end of getCommand()

