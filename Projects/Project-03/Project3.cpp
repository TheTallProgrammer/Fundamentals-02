/* 
Name:     		Logan Falkenberg
Date: 			March 3 2021
Assignment #:	Project 3
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments
This project is an updates version of project 2
The user enters the transaction type and amount (if required) on a single line. In other words,
there should not be a separate prompt message for the transaction amount.

*/
#include <iomanip>      // std::setprecision
#include <iostream>				// for cin, cout, endl
using namespace std;

//prototype declerations
void getTransaction(string, float &, char &);
float checkTransaction(float, float);
float depositTransaction(float, float);

int main()
{
	
	// decleration of variables
	const float LOW_BAL_CHARGE = 15.00;
	const float NEG_BAL_CHARGE = 35.00;
	char transactionType;
	float transactionAmount;
	float balance;
	string prompt;
	int balanceChargeCounter;
	float serviceChargeTotal;
	
	
	// Sets the balance charge counter to 0 since there has been no charges made yet
	balanceChargeCounter = 0;
	
	// Gets the user's beginning balance
	cout << "Enter the beginning balance: ";
	cin >> balance;
	
	// Prompt for the main menu 
	prompt = "\n_______________________________________\nSelect Transaction Type:\nC - Process a check\nD - Process a deposit\nE - Exit\n\nEnter a transaction: ";
	
	// Calls the function getTransaction to start the user's transaction process
	getTransaction(prompt, transactionAmount, transactionType);
	
	// Main loop for all remaining transactions, exits when the user types E to exit
	while(transactionType == 'D' || transactionType == 'C' ){
		
		// Transaction type conditionals
		if (transactionType == 'D'){
			
			// Deposit stuff
			// Calls the depositTransaction function to update the balance regarding a deposit
			balance = depositTransaction(transactionAmount, balance);
			
			// Checks if there are service charges
			if (serviceChargeTotal > 0.00){
				cout << "Total service charges: $" << fixed << std::setprecision(2) << serviceChargeTotal << endl;
			}
			
			
		} else {
			
			// Check stuff
			// Calls the checkTransaction function to update the balance regarding a check
			balance = checkTransaction(transactionAmount, balance);
			
			// Since it's a check, we add a $0.35 service charge
			serviceChargeTotal = serviceChargeTotal + 0.35;
			cout << "Service charge: $0.35 for a check" << endl;
			
			// Conditional to see if the check transaction made the balance go below $0.00
			if (balance < 0.00){
				serviceChargeTotal = serviceChargeTotal + NEG_BAL_CHARGE;
				cout << "Service charge: $35.00, balance below $0.00" << endl;
			}
			
			// Displays service charges
			cout << "Total service charges: $" << fixed << std::setprecision(2) << serviceChargeTotal << endl;
			
		}
		
		// Conditional for if the account balance is below $500.00
		if (balance < 500.00 && balanceChargeCounter < 1){
			
			// Updates the balance charge counter so the user doesn't get charged again
			balanceChargeCounter = balanceChargeCounter + 1;
			
			// Updates the service charge total
			serviceChargeTotal = serviceChargeTotal + LOW_BAL_CHARGE;
			
			// Tells the user they went below $500.00
			cout << "Service charge: $15.00, balance below $500.00\nTotal service charges: $" << serviceChargeTotal << endl;
			
		}
		
		// Once the transactions and balances are updated, it calls the getTransaction() function again to restart the process
		getTransaction(prompt, transactionAmount, transactionType);
	} // End of the main while-loop
	
	// THIS IS THE END OF THE MONTH, UPDATE EVERYTHING TO FINISH OFF THE USER
	
	// Adds on the service charges to the balance
	balance = balance + serviceChargeTotal;
	
	// Displays the end of the month balance
	cout << "Processing end of month\nProcessed...\nFinal balance: $" << fixed << std::setprecision(2) << balance << endl;
	
	
	
	// Ends the function 
    cin.get();
    return 0;
    
}// end of main

// This function will get users input for a transaction type, and pass by reference the variables needed to process the transaction
void getTransaction(string prompt, float &transactionAmount, char &transactionType)
{	
	cout << prompt;
	cin >> transactionType;
	transactionType = toupper(transactionType);
	
	cin.clear();
	cin.ignore();
	
	if (transactionType == 'E')
		cout << " " << endl;
	else
		cin >> transactionAmount;
	
	// While no correct transaction has been made
	while (transactionType != 'D' && transactionType != 'E' && transactionType != 'C'){
		
		// Error message 
		cout << "Incorrect transaction. Try again." << endl;
		
		// Receives the input for the transaction type and the transaction amount
		cout << prompt;
		cin >> transactionType;
		
		// toupper makes chars upper case
		transactionType = toupper(transactionType);
		cin.clear();
		cin.ignore();
		
		if (transactionType == 'E')
			break;
		else
			cin >> transactionAmount;
		
	}
	
} // end of getCommand()

// This function updates the balance regarding a deposit
float depositTransaction(float transactionAmount, float balance)
{
	
	// Declare variables
	float bal; 
	float transacAmount;
	
	// Initialize variables
	bal = balance;
	transacAmount = transactionAmount;
	
	// Updating balance
	bal = bal + transacAmount;
	
	// Displaying the transaction of the deposit
	cout << "Processing deposit for $" << fixed << std::setprecision(2) << transactionAmount << endl;
	cout << "\n\nProcessed...\nBalance: $" << fixed << std::setprecision(2) << bal << endl;
	
	// Returns updated balance
	return bal;
	
} // end of depositTransaction()

// This function updates the balance regarding a check
float checkTransaction(float transactionAmount, float balance)
{
	
	// Declare variables
	float bal; 
	float transacAmount;
	
	// Initialize variables
	bal = balance;
	transacAmount = transactionAmount;
	
	// Updating balance
	bal = bal - transacAmount;
	
	// Displaying the transaction of the deposit
	cout << "Processing check for $" << fixed << std::setprecision(2) << transactionAmount << endl;
	cout << "\n\nProcessed...\nBalance: $" << fixed << std::setprecision(2) << bal << endl;
	
	// Returns updated balance
	return bal;
	
} // End of checkTransaction()



