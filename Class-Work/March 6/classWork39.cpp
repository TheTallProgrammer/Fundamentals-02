/* 
Name:     		Gia Rivera
Date: 			Feb 27 2021
Assignment #:	classWork39
Status: 		Completed
Language:		C++
-------------------------------------------------------------------------
Comments
users will enter (D)eposit, (C)heck, (E)xit
otherwise an error message of wrong entry
*/

#include <iostream>				// for cin, cout, endl
#include <string>
using namespace std;

// declaration of function prototypes
char getCommand(string);
float getAmount(string);
void updateBalance(float &, float, char);

int main()
{
	char cmd;
	float tAmount;
	float balance;
	
	balance = getAmount("Enter the initial balance: ") << endl;
	
	cmd = getCommand("Enter (D)eposit, (C)heck, (E)xit "); // pre-read
	
	while (cmd == 'D' || cmd == 'C')
	{
		if (cmd == 'D')
		{
			cout << "Depositing checks" << endl;
			tAmount = getAmount("Enter the deposit amount: ");
			updateBalance(balance,tAmount,'D');
		}
		else
		{
			cout << "Cashing checks" << endl;
			tAmount = getAmount("Enter the check cash amount: ");
			updateBalance(balance,tAmount,'C');
		}
		
		cmd = getCommand("Enter (D)eposit, (C)heck, (E)xit "); // update-read
	}
	
	cout << " I am exiting the Data entry loop" << endl;
	
	system("PAUSE");
    return 0;
} // end of main()

float getAmount(string prompt)
{
	float amt;
	cout << prompt;
	cin >> amt;
	
	while (amt <= 0){
		cout << "Entered a negative number " << endl;
		cout << prompt;
		cin >> amt;
	}
	
	return amt;
} // end of getAmount()

// getCommand() will get users input for a character command
// only returns D, C, or E
char getCommand(string prompt)
{
	char cmd;
	cout << prompt;
	cin >> cmd; // pre-read
	cmd = toupper(cmd);
	
	while (cmd != 'D' && cmd != 'E' && cmd != 'C')
	{
		cout << prompt;
		cin >> cmd; // update-read
		cmd = toupper(cmd);
	}
	
	return cmd;
} // end of getCommand()

void updateBalance(float & balance, float tAmount, char cmd){
	if(cmd == 'D'){
		balance = balance + tAmount;
	} else {
		balance = balance + tAmount;
	}
}
