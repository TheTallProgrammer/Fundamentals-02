/* 
Name:     		Logan Falkenberg
Date: 			Feb 19 2021
Assignment #:	Project2
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments
the user enter the initial balance followed by a series of transactions

*/
#include <iomanip>      // std::setprecision
#include <iostream>				// for cin, cout, endl
using namespace std;

//prototype declerations
double userBalance();
double transaction(double, string);

int main()
{
	// Declaration of variables
	double balance, serviceChargeTotal;
	bool continueTrans;
	string transactionType;
	
	// Initialize Variables
	continueTrans = true;
	serviceChargeTotal = 0.0;
	
	// Gets the user's initial balance
	cout << "Enter the starting balance: ";
	cin >> balance;
	
	// While the user still wants to process transactions
	while (continueTrans){
		// Display the menu
		cout << "\n_______________________________________" << endl;
		cout << "Select Transaction Type:" << endl;
		cout << "C - Process a check\nD - Process a deposit\nE - Exit" << endl;
		
		// Gets the transaction type
		cout << "\nEnter transaction type: ";
		cin >> transactionType;
		
		// If the user wants to exit the program
		if (transactionType == "E"){
			cout << "Processing end of month" << endl;
			balance = balance - serviceChargeTotal;
			cout << "Final Balance: $" << balance;
			
			// Sets the while loops boolean to false to stop the while loop, ending the program.
			continueTrans = false;
		}
		
		// Updates the balance depending on the transaction
		// calls the function double transaction(double balance, string transactionType)
		balance = transaction(balance, transactionType);
		
		// Updates the transaction charge total if the transaction was a check
		if (transactionType == "C"){
			serviceChargeTotal = serviceChargeTotal + 0.25;
			cout << "Service charge: $.25 for a check" << endl;
			cout << "Total service charges: $" << serviceChargeTotal << endl;
		}
		
	}
	
    cin.get();
    return 0;
    
}// end of main

// The transaction() function will pass in the arguments (double balance, string transactionType) to 
// tell the system which transaction type has occurred so that the correct transaction can be processed 
// and will update the balance after transaction is processed.
// It will return the updated user balance to the main() function.
double transaction(double balance, string transactionType){
	
	// Declaring variables
	string userTransactionType;
	double userBalance, transactionAmount;
	
	// Initializing variables
	userTransactionType = transactionType;
	userBalance = balance;
	
	// Conditionals
	if (userTransactionType == "C"){
		// Gets the user's transaction amount for the check
		cout << "Enter transaction amount: ";
		cin >> transactionAmount;
		
		// Checks if transaction is a positive number
		if (transactionAmount > 0.0){
		
			// Tells user about the transaction process
			cout << "Processing check for " << fixed << std::setprecision(2) << transactionAmount  << endl;
			
			// Updates the balance
			userBalance = userBalance - transactionAmount;
			
			// Tells user the updated balance
			cout << "\nProcessed..." << endl;
			cout << "Balance: $" << fixed << std::setprecision(2) << userBalance << endl;
		} else {
			cout << "Value is not positive" << endl;
		}
	} else if (userTransactionType == "D"){
		// Gets the user's transaction amount for a deposit
		cout << "Enter transaction amount: ";
		cin >> transactionAmount;
		
		// Checks if transaction is a positive number
		if (transactionAmount > 0.0){
			// Tells user about the transaction process
			cout << "Processing deposit for " << fixed << std::setprecision(2) << transactionAmount << endl;
			
			// Updates the balance
			userBalance = userBalance + transactionAmount;
			
			// Tells the user the updated balance
			cout << "\nProcessed..." << endl;
			cout << "Balance: $" << fixed << std::setprecision(2) << userBalance << endl;
		} else {
			cout << "Value is not positive" << endl;
		}
	
	// If the user wants to exit, it returns 0 to exit the function
	} else if (userTransactionType == "E"){
		return 0;
	} else {
		cout << "Incorrect Transaction Type" << endl;
	}
	
	// Returns the balance
	return userBalance;
	
} // End of transaction
