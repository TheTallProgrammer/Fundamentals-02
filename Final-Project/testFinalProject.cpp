/* 
Name:     		Logan Falkenberg
Date: 			May 4 2021
Assignment #:	Test Final Project 
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments

This program is a quiz that imports a list of vocab words and asks the user what the foreign word is that correlates to the english word.

*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>

using namespace std;


// Declaring class 
class Words{
		private:
			
			// Declare variables
			string foreignWord;
			string englishWord;
			
			
		public: 
			
			// Declare functions
			void foreignSet(string);
			void englishSet(string);
			string getForeignWord();
			string getEnglishWord();

		
}; // End of class Words


// Setter for Words objects (member function)
void Words::foreignSet(string newForeignWord){
	
	foreignWord = newForeignWord;
	

} // End of foreignSet()

void Words::englishSet(string newEnglishWord){
	
	englishWord = newEnglishWord;
	
} // End of englishSet()


// Getter for the foreign word
string Words::getForeignWord(){
	
	return foreignWord;
	
} // End of getForeignWord()


// Getter for the English word
string Words::getEnglishWord(){
	
	return englishWord;
	
} // End of getEnglishWord()


class quizAnswers{
		private:
			
			// Declare variables
			string wordToGuess;
			string guessedWord;
			int questionNumber;
			string rightOrWrong;
			
			
		public: 
			
			// Declare functions
			void wordToGuessSet(string, int);
			void guessedWordSet(string, string);
			string getWordToGuess();
			string getGuessedWord();
			int getQuestionNumber();
			string getRightOrWrong();

		
}; // End of class quizAnswers


// Setter for quizAnswers objects (member function)
void quizAnswers::wordToGuessSet(string newWordToGuess, int newQuestionNumber){
	
	wordToGuess = newWordToGuess;
	questionNumber = newQuestionNumber;

} // End of foreignSet()


void quizAnswers::guessedWordSet(string newGuessedWord, string newRightOrWrong){
	
	guessedWord = newGuessedWord;
	rightOrWrong = newRightOrWrong;
	
} // End of englishSet()


// Getter for the foreign word
string quizAnswers::getWordToGuess(){
	
	return wordToGuess;
	
} // End of getForeignWord()


// Getter for the English word
string quizAnswers::getGuessedWord(){
	
	return guessedWord;
	
} // End of getEnglishWord()


int quizAnswers::getQuestionNumber(){
	
	return questionNumber;
	
} // End of getQuestionNumber()


string quizAnswers::getRightOrWrong(){
	
	return rightOrWrong;
	
} // End of getRightOrWrong()


// Prototype declarations
bool populateClass(Words [], Words [], int &);
int getData(string);
string getLanguage(string);
void runQuiz(Words [], Words [] , quizAnswers [], quizAnswers [], int, string, string);
void gradeQuiz(int, int, int, string);
void displayQuestionAnswers(quizAnswers [], quizAnswers [], int);
void askForInput(string);

int main(){
	
	// Declare variables
	const int MAX_WORD_COUNT = 100;
	int counter;
	int wordsAsked;
	string language;
	string name;
	bool isWrong;
	Words foreignWords [MAX_WORD_COUNT];
	Words englishWords [MAX_WORD_COUNT];

	// Initialize variables
	isWrong = true;
	
	// Call the function and say so if it fails 
	if(populateClass(foreignWords, englishWords, counter)==false){
		
		cout << "We are back in main telling you again that your function did not work" << endl;
		return 1;
		
	} // End of function call 
	
	cout << "Welcome to the Logan Falkenberg vocabulary quiz program!" << endl;
	
	cout << "\nWhat is your name? ";
	
	cin >> name;
	
	cout << "\nMax words available: " << counter << endl;
	
	language = getLanguage("What is the foreign language? ");
	
	wordsAsked = getData("How many words would you like to be quizzed on? ");
	
	// Declare and initialize the quizAnswers array that will be used later on 
	quizAnswers wordsToGuess [wordsAsked];
	quizAnswers guessedWords [wordsAsked];
	
	// Checks to see if the word amount asked is possible 
	if (wordsAsked < 1 || wordsAsked > 100){
		while(isWrong){
			cout << "Word amount not accepted. Try again." << endl;
			wordsAsked = getData("How many words would you like to be quizzed on? ");
			if (wordsAsked > 0 && wordsAsked <= 100){
				isWrong = false;
			}
		}
		
	}
	
	// Calls the runQuiz() function to run the quiz based upon the vocab list chosen 
	runQuiz(foreignWords, englishWords, wordsToGuess, guessedWords, wordsAsked, language, name);
	
	return 0;
	
} // End of main()


// Function for populating the class
bool populateClass(Words foreignWords [], Words englishWords [], int &counter){
	
	// Declare variables
	char foreignWord [20];
	char englishWord [20];
	
	// Initialize Variables
	counter = 0;
	
	// Gets the .txt file
	ifstream inputFile("vocabFile.txt");
	
	// If there is no input file, display an error message
	if (!inputFile){
		
		cout << "Can not open master file \"employee.txt\"" << endl;
		return false;
	}
	
	// Read records from the file as long as there are records left to read
	while(!inputFile.eof()){
		
		inputFile.get(foreignWord, 20, '\n');
//		cout << "Foreign Word: " << foreignWord << endl;
		
		inputFile.ignore();
		
		inputFile.get(englishWord, 20, '\n');
//		cout << "English Word: " << englishWord << endl;
		
		inputFile.ignore();
		
		foreignWords[counter].foreignSet(foreignWord);
		
		englishWords[counter].englishSet(englishWord);
		
		counter ++;
	}
	
	// Checks to see if there's anything in the list 
	if (counter < 1){
		cout << "The vocab list is empty" << endl;
	}
	
	// Close the file 
	inputFile.close();
	
	return 1;
	
} // End of populateClass()


// Function for receiving and returning data 
int getData(string prompt){
	
	int value;
	
	cout << prompt;
	
	cin >> value;
	
	return value;
	
} // End of getData()


// Function for receiving and returning data 
string getLanguage(string prompt){
	
	string lagnuage;
	
	cout << prompt;
	
	cin >> lagnuage;
	
	return lagnuage;
	
} // End of getLanguage()


// This function runs the quiz 
void runQuiz(Words foreignWords [], Words englishWords [], quizAnswers wordsToGuess [], quizAnswers guessedWords [], int wordsAsked, string language, string name){
	
	// Declare variables
	char enteredWord [20];
	int correctAnswers;
	int wrongAnswers;
	string wordTG;
	string guessedWord;
	string rightOrWrong;
	
	// Initialize Variables
	correctAnswers = 0;
	wrongAnswers = 0;
	
	cout << "\n---------------------------------" << endl;
	cout << "Quiz Time" << endl;
	cout << "**Type all answers in lower case**" << endl;
	cout << "---------------------------------" << endl;
	
	for (int i = 0; i < wordsAsked; i++){

		cout << "Question " << i + 1 << ": English Word: " << englishWords[i].getEnglishWord() << endl;
		cout << "Enter 1 equivalent " << language << " word(s)." << endl; 
	
		cout << "Word[1]: ";
		
		wordTG = englishWords[i].getEnglishWord();

		cin.get();
		cin.get(enteredWord,20);
		
		guessedWord = enteredWord;
		
		wordsToGuess[i].wordToGuessSet(wordTG, i+1);

		// Conditions to see if the correct word is inputted 
		if (enteredWord == foreignWords[i].getForeignWord()){
			cout << "\nCorrect!" << endl;
			correctAnswers++;
			rightOrWrong = "Correct";
			

		} else {
			cout << "\nIncorrect!" << endl;
			wrongAnswers++;
			rightOrWrong = "Incorrect";
		}
		
		guessedWords[i].guessedWordSet(guessedWord, rightOrWrong);

		cout << "---------------------------------" << endl;
	
	}
	
	// Calls the function to calculate the quiz
	gradeQuiz(correctAnswers, wrongAnswers, wordsAsked, name);
	
	displayQuestionAnswers(wordsToGuess, guessedWords, wordsAsked);
	
	askForInput(language);
	
} // End of runQuiz()


// This function will grade the quiz that the user took 
void gradeQuiz(int correctAnswers, int wrongAnswers, int wordsAsked, string name){
	
	// Declare variables
	float grade;
	float wordsA;
	float cAnswers;
	
	// Initialize variables
	wordsA = float(wordsAsked);
	cAnswers = float(correctAnswers);
	
	cout << "\nGrade Time" << endl;
	cout << "Name: " << name << endl;
	cout << "Words Asked: " << wordsAsked << endl;
	cout << "Wrong Answers: " << wrongAnswers << endl;
	
	// Calculates the grade
	grade = (cAnswers / wordsA) * 100;
	
	cout << "	Grade: %" << fixed << std::setprecision(2) << grade;
	
	// Checks to see if the grade is above an 80%
	if (grade <= 80){
		cout << " (Failed. You have scored below 80%)" << endl;
	} else {
		cout << " (Passed. You have scored above 80%)" << endl;
	}
	
} // End of gradeQuiz()


// This function displays the questions and answers of the quiz 
void displayQuestionAnswers(quizAnswers wordsToGuess [], quizAnswers guessedWords [], int wordsAsked){
	
	cout <<"\n---------------------------------" << endl;
	cout << "Quiz Questions Report" << endl;
	
	for (int i = 0; i < wordsAsked; i++){
		
		cout << "\nQuestion " << i+1 << ": Word to translate: " << wordsToGuess[i].getWordToGuess() << endl;;
		cout << "Your input: " << guessedWords[i].getGuessedWord() << " **" << guessedWords[i].getRightOrWrong() << "** " << endl;
		
	}
	
} // End of displayQuestioAnswers()


// This function asks the user if they want to add any words to their vocab file
void askForInput(string language){
	
	// Delcare variables
	string answer;
	bool keepGoing;
	string foreignWord;
	string englishWord;
	
	// Initialize variables
	keepGoing = true;
	
	cout <<"\n---------------------------------" << endl;
	cout << "Would you like to add words to the vocab list?(yes/no): ";
	cin >> answer;
	
	if (answer == "yes"){
		
		std::ofstream outFile;
		
		outFile.open("vocabFile.txt", std::ios_base::app); // append instead of overwrite
		
		cout << "To exit at any time, type 'stop'. " << endl;
		
		outFile << endl;
		
		while (keepGoing){
			
			cout << "Type " << language << " word: ";
			cin >> foreignWord;
			
			if (foreignWord == "stop"){
				keepGoing = false;
				outFile.close();
			}
			
			outFile << foreignWord << endl;;
			
			cout << "Type correlating English word: ";
			cin >> englishWord;
			
			if (englishWord == "stop"){
				keepGoing = false;
				outFile.close();
			}
			
			outFile << englishWord << endl;
			
		}
		
	} else {
		cout << "Goodbye." << endl;
	}
	
} // End of askForInput


