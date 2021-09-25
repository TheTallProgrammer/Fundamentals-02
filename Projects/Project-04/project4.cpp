/* 
Name:     		Logan Falkenberg
Date: 			March 23 2021
Assignment #:	Project 4
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments


*/
#include <iostream>				// for cin, cout, endl
#include <iomanip>      // std::setprecision
using namespace std;

//prototype declerations
float getPounds(string, int);
void printResults(float, float ,float, float [], float [], float[]);
float findAverage(float [], float [], float[]);
float findLeast(float [], float [], float[]);
float findLargest(float [], float [], float[]);

int main()
{
	// Declare variables
	int remainingDays;
	float leastAmount;
	float largestAmount;
	float pounds;
	float average;
	bool keepGoing;
	string weekDay;
	string weekDays [7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"}; // length = 7
	int monkeyNumber;
	float monkeyOne [7];
	float monkeyTwo [7];
	float monkeyThree [7];

	
	// Initialize the variables values
	keepGoing = true;
	remainingDays = 0;
	monkeyNumber = 1;
	
	// loop for navigating through the week while getting the users information on how many pounds were fed each day
	while (keepGoing){
		
		// If the end of the week was reached, then go to the next monkey
		if (remainingDays == 7){
			monkeyNumber += 1;
			remainingDays = 0;
			cout <<"\n";
		}
		
		// Asigns the weekDay variable to the index of the specific day in the weekDays array
		weekDay = weekDays[remainingDays];
		
		// Calls the function getPounds() to get the pounds that were fed on that day
		pounds = getPounds(weekDay, monkeyNumber);

		
		if (monkeyNumber == 1){
			monkeyOne[remainingDays] = pounds;
		}
		
		
		if (monkeyNumber == 2){
			monkeyTwo[remainingDays] = pounds;
		}
		
		
		if (monkeyNumber == 3){
			monkeyThree[remainingDays] = pounds;
		}
		
		// Increases the days remaining by 1 so the week array can go through all of the days in the week 
		remainingDays += 1;
		
		
		// Breaks the loop if we got all of the information needed
		if (remainingDays == 7 && monkeyNumber == 3){
			keepGoing = false;
		}
		
	} // End of while-loop
	
	average = findAverage(monkeyOne, monkeyTwo, monkeyThree);
	
	leastAmount = findLeast(monkeyOne, monkeyTwo, monkeyThree);
	
	largestAmount = findLargest(monkeyOne, monkeyTwo, monkeyThree);
	
	
	// Calls the print results function to print out the results of the monkeys food 
	printResults(average, leastAmount, largestAmount, monkeyOne, monkeyTwo, monkeyThree);

	// Closes out the program
    cin.get();
    return 0;
    
}// end of main

// This function will get the user's inputs for the amount of pounds of food 
float getPounds(string weekDay, int monkeyNum){
	
	// Declare variables
	string day;
	float pounds;
	
	// Initializes the day variable to the weekDay
	day = weekDay;
	
	// Gets the user's input for the pounds for each day
	cout << "Enter pounds of food eaten by monkey " << monkeyNum << " on " << day <<": ";
	cin >> pounds; 
	
	// Returns the pounds
	return pounds;
	
} // End of function getPounds()

// This function will find the average of the data collected from the arrays that are being passed into the function
float findAverage(float monkeyOne[7], float monkeyTwo[7], float monkeyThree[7]){
	
	// Declare variables
	float average = 0.0;
	float averageOne = 0.0;
	float averageTwo = 0.0;
	float averageThree = 0.0;
	float averageFour = 0.0;
	float averageFive = 0.0;
	float averageSix = 0.0;
	float averageSeven = 0.0;
	
	
	float dayOne [3];
	float dayTwo [3];
	float dayThree [3];
	float dayFour [3];
	float dayFive [3];
	float daySix [3];
	float daySeven [3];
	
	dayOne[0] = monkeyOne[0];
	dayOne[1] = monkeyTwo[0];
	dayOne[2] = monkeyThree[0];
	
	dayTwo[0] = monkeyOne[1];
	dayTwo[1] = monkeyTwo[1];
	dayTwo[2] = monkeyThree[1];
	
	dayThree[0] = monkeyOne[2];
	dayThree[1] = monkeyTwo[2];
	dayThree[2] = monkeyThree[2];
	
	dayFour[0] = monkeyOne[3];
	dayFour[1] = monkeyTwo[3];
	dayFour[2] = monkeyThree[3];
	
	dayFive[0] = monkeyOne[4];
	dayFive[1] = monkeyTwo[4];
	dayFive[2] = monkeyThree[4];
	
	daySix[0] = monkeyOne[5];
	daySix[1] = monkeyTwo[5];
	daySix[2] = monkeyThree[5];
	
	daySeven[0] = monkeyOne[6];
	daySeven[1] = monkeyTwo[6];
	daySeven[2] = monkeyThree[6];
	
	for (int kOne = 0; kOne < 3; kOne++){
		averageOne = averageOne + dayOne[kOne];
	}
	
	for (int kTwo = 0; kTwo < 3; kTwo++){
		averageTwo = averageTwo + dayTwo[kTwo];
	}
	for (int kThree = 0; kThree < 3; kThree++){
		averageThree = averageThree + dayThree[kThree];
	}
	
	for (int kFour = 0; kFour < 3; kFour++){
		averageFour = averageFour + dayFour[kFour];
	}
	
	for (int kFive = 0; kFive < 3; kFive++){
		averageFive = averageFive + dayFive[kFive];
	}
	
	for (int kSix = 0; kSix < 3; kSix++){
		averageSix = averageSix + daySix[kSix];
	}
	
	for (int kSeven = 0; kSeven < 3; kSeven++){
		averageSeven = averageSeven + daySeven[kSeven];
	}
	
	// Divides by the total to get the average
	average = (averageOne + averageTwo + averageThree + averageFour + averageFive + averageSix + averageSeven) / 7;
	
	return average;
	
} // End of function findAverage()

// This function finds the lowest numeric value element in the arrays that are passed into the function
float findLeast(float monkeyOne[7], float monkeyTwo[7], float monkeyThree[7]){
	
	// Delcare variables
	float leastArr [3];
	float least;
	float leastOne;
	float leastTwo;
	float leastThree;
	
	leastOne = monkeyOne[0];
	
	for (int i = 0; i < 7; i++){
		if(leastOne > monkeyOne[i]){
			leastOne = monkeyOne[i];
		}
	}
	
	leastTwo = monkeyTwo[0];
	
	for (int j = 0; j < 7; j++){
		if(leastTwo > monkeyTwo[j]){
			leastTwo = monkeyTwo[j];
		}
	}
	
	leastThree = monkeyThree[0];
	
	for (int p = 0; p < 7; p++){
		if(leastThree > monkeyThree[p]){
			leastThree = monkeyThree[p];
		}
	}
	
	leastArr[0] = leastOne;
	leastArr[1] = leastTwo;
	leastArr[2] = leastThree;
	
	least = leastArr[0];
	for (int a = 0; a < 3; a++){
		if (least > leastArr[a]){
			least = leastArr[a];
		}
	}
	
	return least;
	
} // End of function findLeast()

// This function finds the largest numeric value element in the arrays that are passed into the function
float findLargest(float monkeyOne[7], float monkeyTwo[7], float monkeyThree[7]){
	
	// Delcare variables
	float largestArr [3];
	float largest;
	float largestOne;
	float largestTwo;
	float largestThree;
	
	largestOne = monkeyOne[0];
	
	for (int i = 0; i < 7; i++){
		if(largestOne < monkeyOne[i]){
			largestOne = monkeyOne[i];
		}
	}
	
	largestTwo = monkeyTwo[0];
	
	for (int j = 0; j < 7; j++){
		if(largestTwo < monkeyTwo[j]){
			largestTwo = monkeyTwo[j];
		}
	}
	
	largestThree = monkeyThree[0];
	
	for (int p = 0; p < 7; p++){
		if(largestThree < monkeyThree[p]){
			largestThree = monkeyThree[p];
		}
	}
	
	largestArr[0] = largestOne;
	largestArr[1] = largestTwo;
	largestArr[2] = largestThree;
	
	largest = largestArr[0];
	for (int a = 0; a < 3; a++){
		if (largest < largestArr[a]){
			largest = largestArr[a];
		}
	}
	
	return largest;
	
	
} // End of findLargest()

// This function prints the results of the data gathered above in a structured format
void printResults(float average, float lowest, float highest, float monkeyOne [7], float monkeyTwo [7], float monkeyThree [7]){
	
	// Declare variables
	string weekDays [8] = {"Monkey", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"}; // length = 7
	
	cout << "\n\n\n\n";
	cout << "Pounds of Food Eaten by Monkey and Day of Week " << endl;
	cout << "\n";
	
	for (int i = 0; i < 8; i++){
		cout << weekDays[i] << "   ";
	}
	
	cout << " " << endl;
	
	for (int j = 0; j < 3; j++){
		if (j == 0){
			cout << "     1   ";
			for (int one = 0; one < 7; one++){
				cout << fixed << std::setprecision(1) << monkeyOne[one] << "   ";
			}
		}
		if (j == 1){
			cout << "\n";
			cout << "     2   ";
			for (int two = 0; two < 7; two++){
				cout << fixed << std::setprecision(1) << monkeyTwo[two] << "   ";
			}
		}
		if (j == 2){
			cout << "\n";
			cout << "     3   ";
			for (int three = 0; three < 7; three++){
				cout << fixed << std::setprecision(1) << monkeyThree[three] << "   ";
			}
		}
	}
	
	cout << "\n";
	cout << "\n";
	cout << "The average food eaten per day by all monkeys     : " << fixed << std::setprecision(1) << average << " pounds" << endl;
	cout << "The least amount of food eaten by any monkey      : " << lowest << " pounds " << endl;
	cout << "The largest amount of food eaten per by any monkey: " << highest << " pounds " << endl;
	
} // end of printResults()

