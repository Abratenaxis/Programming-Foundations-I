//Julio Bonilla
//HW2
//Vwlls (Vowel-less)
//Allen Baker
//PROG 1203

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

const int kVowels = 1;
const int kConsonants = 2;
const int kDigits = 3;
const int kPunctuations = 4;

using namespace std;

// Returns true if checkChar is a vowel
// @ param character in the array
bool isVowel(char checkChar)
{

	char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
	return find(begin(vowels), end(vowels), checkChar) != end(vowels);
}

// Returns true if checkChar is a consonant
// @ param character in the array
bool isConsonant(char checkChar)
{

	char consonants[] = {'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z',
						 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z'};
	return find(begin(consonants), end(consonants), checkChar) != end(consonants);
}

// Returns true if checkChar is a digit
// @ param character in the array
bool isDigit(char checkChar)
{

	char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	return find(begin(digits), end(digits), checkChar) != end(digits);
}

// Returns true if checkChar is a punctuation mark
// @ param character in the array
bool isPunctuation(char checkChar)
{

	char punctuations[] = {'.', ':', ';', ',', '?', '!'};
	return find(begin(punctuations), end(punctuations), checkChar) != end(punctuations);
}

// Returns string sModified without vowels
// @ param string input
string removeVowel(string sModified)
{
	// remove_if moves all the characters for which `isVowel` is true to the end of string array
	// and returns an iterator to the first such character (checkChar)
	auto toErase = remove_if(sModified.begin(), sModified.end(), isVowel);
	// Actually remove the unwanted characters from the string
	sModified.erase(toErase, sModified.end());
	return sModified;
}

// Returns string sModified without consonants
// @ param string input
string removeConsonant(string sModified)
{
	// remove_if moves all the characters for which `isConsonant` is true to the end of string array
	// and returns an iterator to the first such character (checkChar)
	auto toErase = remove_if(sModified.begin(), sModified.end(), isConsonant);
	// Actually remove the unwanted characters from the string
	sModified.erase(toErase, sModified.end());
	return sModified;
}

// Returns string sModified without digits
// @ param string input
string removeDigit(string sModified)
{
	// remove_if moves all the characters for which `isDigit` is true to the end of string array
	// and returns an iterator to the first such character (checkChar)
	auto toErase = remove_if(sModified.begin(), sModified.end(), isDigit);
	// Actually remove the unwanted characters from the string
	sModified.erase(toErase, sModified.end());
	return sModified;
}

// Returns string sModified without punctuations
// @ param string input
string removePunctuation(string sModified)
{
	// remove_if moves all the characters for which `isPunctuation` is true to the end of string array
	// and returns an iterator to the first such character (checkChar)
	auto toErase = remove_if(sModified.begin(), sModified.end(), isPunctuation);
	// Actually remove the unwanted characters from the string
	sModified.erase(toErase, sModified.end());
	return sModified;
}

// Function that:
// prompts user for input
// calls removal functions with input as parameter
// returns bool
// true if again is 'y' or 'Y'
// @ param char string int bool
bool processMenu()
{
	// Initialize variables to store:
	// repeat option
	// user input
	// menu option choice
	char again;
	string input;
	int menuOption;

	do{

		cout << "please enter a string of words or numbers or punctuation marks!" << endl;
		cin.ignore();
		getline(cin, input, '\n');
		cout << "what do you want to leave out? \n 1: vowels \n 2: consonants \n 3: digits \n 4: punctuation marks" << endl;
		cin >> menuOption;
		// loop that gets valid input
		// only allows int 1-0
		while (menuOption < kVowels || menuOption > kPunctuations || cin.fail())
		{
			cout << "invalid input." << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "please choose a valid input AKA one of the 4 options from 1-4... dont mess around" << endl;
			cin >> menuOption;
		}
		if (menuOption == kVowels)
		{
			cout << input << endl;
			cout << removeVowel(input) << endl;
			cin.clear();
		}
		else if (menuOption == kConsonants)
		{
			cout << input << endl;
			cout << removeConsonant(input) << endl;
			cin.clear();
		}
		else if (menuOption == kDigits)
		{
			cout << input << endl;
			cout << removeDigit(input) << endl;
			cin.clear();
		}
		else if (menuOption == kPunctuations)
		{
			cout << input << endl;
			cout << removePunctuation(input) << endl;
			cin.clear();
		}
		else
		{
			cout << "you gotta choose an option brother" << endl;
			return false;
		}
		cout << '\n' << "want to try again? y or n \n" << endl;
		cin >> again;
	}
	// asks user to retry; if not break loop
	while ((again == 'y') || (again == 'Y'));
	return false;
}

// Function that keeps processMenu looping as long as processMenu passes true
// returns int
// @ param bool int
int main()
{
	// if processMenu passes false then display closing statement
	// and breaks loop
	while (!processMenu())
	{
		cout << '\n' << "thanks for playing!" << endl;
		break;
	}
// once while loop breaks
// execute system pause
system("pause");
return 0;
}