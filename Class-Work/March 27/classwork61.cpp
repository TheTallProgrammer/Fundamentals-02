/* 
Name:     		Logan Falkenberg
Date: 			March 27 2021
Assignment #:	classwork61
Status: 		Completed
Language: C++
With whom I got help: 
-------------------------------------------------------------------------
Comments

Enter a float data until you get a negative number 
*/
#include <iostream>				// for cin, cout, endl
using namespace std;

//prototype declerations
float getData(string);
void printGrades(int []);

int main()
{
	int SIZE = 5;
	int grades[SIZE];
	float number;
	int count = 0;
	number = getData("Enter a number: ");
	
	while (number >= 0 && count < 5){
		grades[count] = number;
		count = count + 1;
		if (count < 5)
			number = getData("Enter a number: ");	
		
	}
	
	cout << "\nCount: " << count << endl;
	printGrades(grades);
	

	
    cin.get();
    return 0;
    
}// end of main

void printGrades(int grades[]){
	
	cout << "\nResults: " << endl;
	for (int x = 0; x < 5; x++){
		cout << grades[x] << endl;
	}
}


float getData(string prompt){
	
	float value;
	cout << prompt;
	cin >> value;
	return value;
	
}
