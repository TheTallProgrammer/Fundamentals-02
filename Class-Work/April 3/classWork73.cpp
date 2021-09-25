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
#include <iostream>              //includes iostream header
#include <fstream>               //includes filestream header
using namespace std;
int main() {
    
    {                                
        int score;
        ifstream input("data11.txt");   //creating input stream named input stream filename=in.txt
     
     	if (input){ // file existance check
     		while (input >> score)
           		cout << score << endl;
		 } else {
		 	cout << "File doesn't exist." << endl;
		 }
     
        
        input.close();
    }
    return 0;
}
