/* 
Name:     		Logan Falkenberg
Date: 			April 4 2021
Assignment #:	Project 5
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments

This program gets a users location and package weight and determines whether
the package will be accepted dependent on the weight 
if its accepted, a charge will be calculated 

*/
#include <iomanip>      // std::setprecision
#include <iostream>				// for cin, cout, endl
using namespace std;

//prototype declerations
void getInput(char &, int &, int &, int &, int &, int &, bool &, int &, int &);
string getLocation(char);
int getGirth(int, int, int);
void shippingCharge(int, float &, float &);
void displayTransactionResults(bool, int, string, float, int);
void displayFinalResults(int, int, float);


int main()
{
	
	// Declaration of variables
	char transactionType;
	int transactionNum;
	int acceptedPackages;
	int packageWeight;
	int rejectedPackages;
	int sideOne;
	int sideTwo;
	int sideThree;
	float shipCharge;
	float totalCost;
	bool packageRejected;
	bool keepGoing;
	string location;
	
	// Initialize variables
	keepGoing = true;
	packageRejected = false;
	rejectedPackages = 0;
	transactionNum = 0;
	
	while (keepGoing){
		// Calls the function getInput to recieve the user's input data for the transaction
		getInput(transactionType, packageWeight, sideOne, sideTwo, sideThree, rejectedPackages, packageRejected, transactionNum, acceptedPackages);
		
		if (transactionType == 'X'){
			keepGoing = false;
			break;
		}
		
		location = getLocation(transactionType);
		
		if (packageRejected == true){
			
			shipCharge = 0.0;
			displayTransactionResults(packageRejected, packageWeight, location, shipCharge, transactionNum);
			packageRejected = false;
			
		} else {
			
			shippingCharge(packageWeight, shipCharge, totalCost);
			
			// Calls this function to show the user their transcation
			displayTransactionResults(packageRejected, packageWeight, location, shipCharge, transactionNum);
			
		}
		
	}
	
	displayFinalResults(acceptedPackages, rejectedPackages, totalCost);
	
    cin.get();
    return 0;
    
}// end of main


// This function will have pass by reference values
void getInput(char &transactionType, int &packageWeight, int &sideOne, int &sideTwo, int &sideThree, int &rejectedPackages, bool &packageRejected, int &transactionNum, int &acceptedPackages){
	
	// Declare variables
	bool keepGoing;
	int girth;
	girth = 0;
	keepGoing = true;
	
	while (keepGoing){
		
		// Display entire menu
		cout << "\nEnter Location - (T)exas; (O)ut of state; (F)oreign (X)it\nEnter package weight and 3 dimensions" << endl;
		
		// Display the transaction options
		cout << "\nEnter Location - (T)exas; (O)ut of state; (F)oreign (X)it: ";
		cin >> transactionType;		
		
		// Capitalize the transactionType input
		transactionType = toupper(transactionType);
		
		// Checks to see if the transcationType is correct
		if (transactionType == 'T' || transactionType == 'O' || transactionType == 'F'){
		
			// Gets the package weight
			cout << "Enter package weight: ";
			cin >> packageWeight;
			
			// Checks if it's a positive number
			if (packageWeight < 0){
				
				cout << "Invalid Weight Dimensions." << endl;
				
			} else if (packageWeight > 0 && packageWeight <= 50){
				
				// Asks for the size of the package
				cout << "Enter side1: ";
				cin >> sideOne;
				
				cout << "Enter side2: ";
				cin >> sideTwo;
				
				cout << "Enter side3: ";
				cin >> sideThree;
				
				// Checks to see if any of the sides are not positive
				if (sideOne < 0 || sideTwo < 0 || sideThree < 0 ){
					
					cout << "Invalid Size Dimensions." << endl;
					
				} else {
					
					// Checks to see if the size of the sides are allowed
					if (sideOne < 7 && sideTwo < 7 && sideThree < 7){
						
						// Gets the total girth of the package
						girth = getGirth(sideOne, sideTwo, sideThree);
						transactionNum = transactionNum + 1;
						
						// Checks to see if the girth size is correct
						if (girth <= 10){
							
							acceptedPackages += 1;
							keepGoing = false;
							
						} else {
							
							rejectedPackages += 1;
							packageRejected = true;
							keepGoing = false;
							
						}
						
					} else {
						
						rejectedPackages += 1;
						packageRejected = true;
						keepGoing = false;
						
					}
					
				}
				
			} else {
				
				rejectedPackages += 1;
				packageRejected = true;
				keepGoing = false;
				
			}
			
		} else if (transactionType == 'X' || transactionType == '0'){
			
			keepGoing = false;
			
		}
		
		else { // The transcation type was entered incorrectly
			
			cout << "Incorrect Transaction Type.\n" << endl;
			
		}
		
	} // End of while-loop
	
} // End of displayMenu

// Gets the location of the transaction type if the user is not exiting out of the program
string getLocation(char transactionType){
	
	// Declare variables
	string location;
	
	if (transactionType == 'T'){
			location = "Texas";
		} else if (transactionType == 'O'){
			location = "Out of state";
		} else if (transactionType == 'F'){
			location = "Out of country";
		}
		
	return location;
	
} // End of getLocation()

// Uses an equation to determine the girth of the package
int getGirth(int sideOne, int sideTwo, int sideThree){
	
	// Declare variables
	int girth;
	int largest;
	int sizeArray [3] = {sideOne, sideTwo, sideThree};
	
	largest = sizeArray[0];
	
	for (int i = 0; i < 3; i++){
		if(largest < sizeArray[i]){
			largest = sizeArray[i];
		}
	}
	
	girth = 2 * ( sideOne + sideTwo + sideThree - largest );
	
	return girth;
	
} // End of getGirth()

// Finds and calculates the shipping charge according to the weight
void shippingCharge(int packageWeight, float &shipCharge, float &totalCost){
	
	// Declare variables
	int weightArray [15] = {1, 2, 3, 5, 7, 10, 13, 16, 20, 25, 30, 35, 40, 45, 50};
	float shippingChargeArray [15] = {1.50, 2.10, 4.00, 6.75, 9.90, 14.95, 19.40, 24.20, 
									27.30, 31.90, 38.50, 43.50, 44.80, 47.40, 55.20};
	int weight;
	bool found;
	int counter;
	
	// Initialize variables
	weight = packageWeight;
    counter = 0;
    found = false;
    
    while (counter < 16 && not found)
    {
        if (weightArray[counter] == weight)
        {
            found = true;
            shipCharge = shippingChargeArray[counter];
        } 
        counter = counter +1;
    }
    
    if (not found){
    	while (not found){
	    	if (weight == 4 || weight == 5){
	    		found = true;
	    		shipCharge = shippingChargeArray[3];
			} else if (weight == 6 || weight == 7){
				found = true;
				shipCharge = shippingChargeArray[4];
			} else if (weight == 8 || weight == 9){
				found = true;
				shipCharge = shippingChargeArray[5];
			} else if (weight == 11 || weight == 12){
				found = true;
				shipCharge = shippingChargeArray[6];
			} else if (weight == 14 || weight == 15){
				found = true;
				shipCharge = shippingChargeArray[7];
			} else if (weight == 17 || weight == 18 || weight == 19){
				found = true;
				shipCharge = shippingChargeArray[8];
			} else if (weight == 21 || weight == 22 || weight == 23 || weight == 24){
				found = true;
				shipCharge = shippingChargeArray[9];
			} else if (weight == 26 || weight == 27 || weight == 28 || weight == 29){
				found = true;
				shipCharge = shippingChargeArray[10];
			} else if (weight == 31 || weight == 32 || weight == 33 || weight == 34){
				found = true;
				shipCharge = shippingChargeArray[11];
			} else if (weight == 36 || weight == 37 || weight == 38 || weight == 39){
				found = true;
				shipCharge = shippingChargeArray[12];
			} else if (weight == 41 || weight == 42 || weight == 43 || weight == 44){
				found = true;
				shipCharge = shippingChargeArray[13];
			} else if (weight == 46 || weight == 47 || weight == 48 || weight == 49){
				found = true;
				shipCharge = shippingChargeArray[14];
			}
    	
   		}
	}
    
    totalCost = totalCost + shipCharge;
    
	
} // End of shippingCharges()

// This displays the current transaction
void displayTransactionResults(bool packageRejected, int packageWeight, string location, float shipCharge, int transactionNum){
	
	cout << "\nTransaction #" << transactionNum << endl;
	cout << "Location: " << location << endl;
	if (packageRejected == true){
		cout << "Status:   Rejected" << endl;
		cout << "Weight:   " << packageWeight << " lb " << endl;
		cout << "Cost:     N/A" << endl;
	} else {
		cout << "Status:   Accepted" << endl; 
		cout << "Weight:   " << packageWeight << endl;
		cout << "Cost:     $" << fixed << std::setprecision(2) << shipCharge << endl;
	}
	
} // End of displayTransactionResults()

// This function displays the final results of the program
void displayFinalResults(int acceptedPackages, int rejectedPackages, float totalCost){
	
	cout << "\nNumber of accepted packages: " << acceptedPackages << endl;
	cout << "Number of rejected packages: " << rejectedPackages << endl;
	cout << "Total Cost:		     $" << fixed << std::setprecision(2) << totalCost << endl;
	
	 
} // End of displayFinalResults



