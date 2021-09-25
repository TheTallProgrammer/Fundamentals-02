/* 
Name:     		Logan Falkenberg
Date: 			March 13 2021
Assignment #:	classwork55
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments

how to write/read to a file
*/
#include <fstream>
#include <iostream>
using namespace std;

int main () {
   char data[100];
   ofstream outfile; 			// open a file in write mode.
   outfile.open("afile.txt");  	// opening a text file to write
   
   cout << "Writing to the file" << endl;
   cout << "Enter your name: "; 
   cin.getline(data, 100);

   outfile << data << endl; 	// write inputted data into the file.
   cout << "Enter your age: "; 
   cin >> data;
   cin.ignore();
   
   
   outfile << data << endl;		// again write inputted data into the file.
   
   outfile.close();				// close the opened file.

   ifstream infile;    			// open a file in read mode.
   infile.open("afile.txt"); 	// Opening an existing file for read
 
   cout << "Reading from the file" << endl; 
   infile >> data; 

   cout << data << endl;   		// write the data at the screen.
   
   
   infile >> data; 				// again read the data from the file and display it.
   cout << data << endl; 
   
   infile.close(); 				// close the opened file.
   return 0;
}

