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
int findAboveAverage(int []);

int main()
{
	int SIZE = 5;
	int grades[SIZE];
	float number;
	int count = 0;
	int countAbove;
	number = getData("Enter a number: ");
	
	while (number >= 0 && count < 5){
		grades[count] = number;
		count = count + 1;
		if (count < 5)
			number = getData("Enter a number: ");	
		
	}
	
	cout << "\nCount: " << count << endl;
	printGrades(grades);
	
	countAbove = findAboveAverage(grades);
	cout << "Count over average: " << countAbove <<  endl;
	

	
    cin.get();
    return 0;
    
}// end of main

int findAboveAverage(int grades[]){
	
	float sum;
	float average;
	int countAbove;
	
	countAbove = 0;
	
	sum = 0.0;
	
	for (int x = 0; x < 5; x++){
		sum = sum + grades[x];
	}
	
	average = sum / 5;
	
	for (int x = 0; x < 5; x++){
		if (grades[x] > average){
			countAbove = countAbove + 1;
		}
	}
	
	return countAbove;
	
}

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
