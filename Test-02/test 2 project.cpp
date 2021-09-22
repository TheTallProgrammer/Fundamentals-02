/* 
Name:     		Logan Falkenberg
Date: 			April 9 2021
Assignment #:	test 2 project 
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments
1. create 1 dimensional array to store items
2. create a parallel array to store the item's 1st char
3. create another array to store the price per item
4. read the file and store them in the above 3 arrays

5. create another array to store items sold based on the location of array in #2
6.  create another array to store items price based on the location of the array in #2
6. do a while loop to read all the items (#2) array and the other special selections
7. then populate arrays in 5 and 6

*/
#include <fstream>               //includes filestream header
#include <iostream>				// for cin, cout, endl
#include <string>
#include <sstream>
#include <stdlib.h>     /* atof */
#include <iomanip>      // std::setprecision
using namespace std;

//prototype declerations
void displayMenu(string [], char [], float [], int);
void getTransaction(string [], char  [], float [], int , float &);

int main()
{
	
	// Declare variables
	string tempArr [100];
	string item;
	string newItem;
	char c;
   	int count;
   	int charCount;
   	int arrSize;
   	int itemCount;
   	int numCount;
   	bool keepGoing;
   	float totalCost;
   	int oCount;
   	string temp;
   	
   	// Initialize variables
   	charCount = 0;
   	itemCount = 0;
   	count = 0;
   	numCount = 0;
   	arrSize = 0;
   	keepGoing = true;
   	totalCost = 0.0;
   	oCount = 1;
   	
   	// Opens the file for reading data
   	ifstream infile;    			// open a file in read mode.
   	infile.open("menu.txt",ios::in); 	// Opening an existing file for read
   	
   	// This will get the size of the file that will be used to declare the array sizes
   	if (infile.is_open())   //checking whether the file is open
   {           
      while(getline(infile, item))  //read data from file object and put it into string.
      {
         arrSize += 1;
      }
      
      infile.close(); //close the file object.
   }
   
   // Re-opens the file to read data into the arrays
   infile.open("menu.txt",ios::in); 	// Opening an existing file for read
   
   // Declare the arrays with the size gathered from the file
   string itemsArr [arrSize];
   char itemCharArr [arrSize];
   float itemsPriceArr [arrSize];
   	
   	if (infile.is_open())   //checking whether the file is open
   {           
      while(getline(infile, item))  //read data from file object and put it into string.
      { 
         tempArr[count] = item;
         count += 1;
      }
      
      infile.close(); //close the file object.
   }
   	
   	// Creates the array full of the characters of the items 
   	while (charCount < arrSize){
   		
   		if (charCount == 0 || charCount % 2 == 0){
   		
	   		newItem = tempArr[charCount];
	   		c = newItem[0];
	   		itemCharArr[charCount] = c;
   		}
   		charCount += 1;
   		
	}
	
	// populates the itemArr with the grocery items
	while (itemCount < arrSize){
		if (itemCount == 0 || itemCount % 2 == 0){
			itemsArr[itemCount] = tempArr[itemCount];
		}
		itemCount += 1;
	}
	
	// Close the file because all the data required was gathered
	infile.close();
	
	infile.open("menu.txt",ios::in);
	
	// Populates the price array with the prices of the items 
   char nums[20];
   float num;
   
   for (int i = 0; i < arrSize; i++){
   		if (i % 2 == 0){
   			infile >> nums >> num;
   			itemsPriceArr[i] = num;
		} else {
			itemsPriceArr[i] = 0;
		}

}

	infile.close();
	

	// Displays the menu for the items that were gathered from the file
	displayMenu(itemsArr, itemCharArr, itemsPriceArr, arrSize);
	getTransaction(itemsArr, itemCharArr, itemsPriceArr, arrSize, totalCost);
	
    cin.get();
    return 0;
    
}// end of main

// Displays the menu for the user's items
void displayMenu(string arrayOne[], char arrayTwo[], float arrayThree[], int arrSize){
	
	// Declare variables
	string line; 
	int size;
	int count;
	int index;

	// Initialize variables
	size = arrSize;
	line = "---------------------------------------";
	count = 0;
	index = 0;
	
	cout << line << endl;
	cout << "Logan Falkenberg Grocery Store" << endl;
	cout << line << endl;
	
	cout << "Grocery Items" << endl;

	while(count < arrSize){
		
		cout << arrayTwo[index] << " " << arrayOne[index] << " ($" << fixed << std::setprecision(2) << arrayThree[index] << " per lb)" << endl;
		index += 2;
		count += 2;
		
	}
	
	cout << "\nT Complete Transaction" << endl;
	cout << "X Cancel Transaction" << endl;
	cout << "E End of Daily sales" << endl;
	
} // End of displayMenu()

// Gets the transaction that the user commits 
void getTransaction(string itemsArr[], char itemCharArr [], float itemsPriceArr[], int arrSize, float &totalCost){
	
	// Declare variables
	bool keepGoing;
	char input;
	int size;
	string item;
	int pounds;
	float cost;
	float costPerPound;
	string groceryList [arrSize];
	int count;
	int poundsArr [arrSize];
	int temp;
	float costArr [arrSize];
	string line = "---------------------------------------";
	float salesTax;
	
	// Initialize variables
	count = 0;
	keepGoing = true;
	size = arrSize;
	cost = 0;
	salesTax = 0.0;
	
	while (keepGoing){
		
		cout << "\nMake your selection: ";
		cin >> input;
		
		input = toupper(input);
		
		for (int i = 0; i < arrSize; i++){
			if(input == itemCharArr[i]){
				item = itemsArr[i];
				cout << "Pounds of " << item << ": ";
				cin >> pounds;
				groceryList[count] = item;
				poundsArr[count] = pounds;
				costPerPound = itemsPriceArr[i];
				cost = pounds * costPerPound;
		
				costArr[count] = cost;
				
				//Cost: 2 lbs. of Apples: $6.00
				cout << "Cost: " << pounds << " lbs. of " << item << ": $" << fixed << std::setprecision(2) << cost << endl;
				
				totalCost = totalCost + cost;
				
				count += 1;
				break;
			} else if (input == 'X'){
				
				cout << "!! Transaction Cancelled" << endl;
				break;
			}
			
		}
		if (input == 'T'){
			
				cout << "\nGrocery List" << endl;
				for (int k = 0; k < count; k++){
					cout << groceryList[k] << " " << poundsArr[k] << " lbs. $" << fixed << std::setprecision(2) << costArr[k] << endl;
				}
				cout << line << endl;
				cout << "Sub Total: $" << totalCost << endl;
				salesTax = 8.25 / totalCost;
				cout << "Sales Tax (8.25%) $" << fixed << std::setprecision(2) << salesTax << endl;
				cout << line << endl;
				totalCost = totalCost + salesTax;
				cout << "Total Sales: $" << totalCost << endl;

				
				
			}
		
		// Cancels transaction
		if (input == 'X'){
			
			cout << "!! Transaction Cancelled" << endl;
			
		}
		
		if (input == 'E'){
			
			cout << "\nDaily Sales Transactions (Grand Total)" << endl;
			cout << "Items Sold..." << endl;
			
			for (int i = 0; i < count; i++){
				cout << groceryList[i] << " " << poundsArr[i] << " lbs. $" << costArr[i] << endl; 
			}
			
			cout << line << endl;
			salesTax = 8.25 / totalCost;
			cout << "Sub Total: $" << fixed << std::setprecision(2) << totalCost << endl;
			cout << "Sales Tax (8.25%) $" << fixed << std::setprecision(2) << salesTax << endl;
			cout << line << endl;
			totalCost = totalCost + salesTax;
			cout << "Total Sales	$" << totalCost << endl;
			keepGoing = false;
			
		}
		
	} // End of main while-loop
	
} // End of getTransaction()
