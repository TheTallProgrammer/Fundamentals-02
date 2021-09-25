/* 
Name:     		Logan Falkenberg
Date: 			Feb 6
Assignment #:	classWork12
Status: 		Completed
Language: 		C++
-------------------------------------------------------------------------
Comments
The program will find the male and female percentage in the class
users will enter the number of males and number of females
*/

#include <iostream>				// for cin, cout, endl
using namespace std;

// Declaration of function prototypes
float getData(int, int);

int main()
{
	float maleCount, femaleCount;
	
	// Getting the inputs
	cout << "What's the number of males?: ";
	cin >> maleCount;
	
	cout << "What's the number of females?: ";
	cin >> femaleCount;
	
	getData(maleCount, femaleCount);
	
	system("PAUSE");
    return 0;
} // end of main()

float getData(int maleCount, int femaleCount)
{
	// Delcaring variables
	float percentMale, percentFemale, total;
	
	// Calculations 
	total = maleCount + femaleCount;
	percentMale = maleCount / total * 100;
	percentFemale = femaleCount / total * 100;
	
	// Display results
	cout << endl << "The total of both genders is: " << total << endl;
	cout << "With " << maleCount << " males, the percetange of males is " << percentMale << "%" << endl;
	cout << "With " << femaleCount << " females, the percetange of females is " << percentFemale << "%" << endl;
	
}

