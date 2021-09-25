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
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
	
   fstream newfile; // newFile object will be used for both read(::in) and write(::out)
   string name;
   
   newfile.open("data03.txt", ios::out);  // open a file to perform write operation using file object
   
   if(newfile.is_open()) //checking whether the file is open
   {
      newfile<<"AllyBaba \n";   //inserting text
      newfile.close();          //close the file object
   }
   
   newfile.open("data03.txt",ios::in); //open a file to perform read operation using file object
   if (newfile.is_open())   //checking whether the file is open
   {           
      while(getline(newfile, name))  //read data from file object and put it into string.
      { 
         cout << name << "\n"; //print the data of the string
      }
      
      newfile.close(); //close the file object.
   }
}
