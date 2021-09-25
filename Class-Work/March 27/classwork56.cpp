/* 
Name:     		Logan Falkenberg
Date: 			March 27 2021
Assignment #:	classwork56
Status: 		Completed
Language: C++
With whom I got help: 
-------------------------------------------------------------------------
Comments


*/
#include <iostream>				// for cin, cout, endl
using namespace std;

//prototype declerations
void populateNumbers(int []);
void printNumbers(int []);

int main()
{
	// Creates an array with size 5
	int numbers[5];
	
	populateNumbers(numbers);
	printNumbers(numbers);
	
	
	
    cin.get();
    return 0;
    
}// end of main

void printNumbers(int num[]){

	for(int i = 0; i < 5; i++){
			cout << num[i] << endl;
		}
		
}


void populateNumbers(int numbers[]){
	
	for(int i = 0; i < 5; i++){
		numbers[i] = i;
	}
	
}

