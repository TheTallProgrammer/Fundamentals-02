/* 
Name:     		Gia Rivera
Date: 			Feb 27 2021
Assignment #:	classWork38
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

int main()
{
	char cmd;
	
	cmd = getCommand("Enter (D)eposit, (C)heck, (E)xit "); // pre-read
	
	while (cmd == 'D' || cmd == 'C')
	{
		if (cmd == 'D')
		{
			cout << "Depositing checks" << endl;
		}
		else
		{
			cout << "Cashing checks" << endl;
		}
		
		cmd = getCommand("Enter (D)eposit, (C)heck, (E)xit "); // update-read
	}
	cout << "I am exiting the Data Entry loop" << endl;
	
	system("PAUSE");
    return 0;
} // end of main()

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
