#include "Phrase.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

// Constructor
Phrase::Phrase()
{
	mPhrase = "";
}

// Destructor
Phrase::~Phrase()
{
	// No action required
}

// Setters
void Phrase::setPhrase(string newPhrase)
{
	mPhrase = newPhrase;
}

// Getters
string Phrase::phrase()
{
	return mPhrase;
}

// Do-ers

// Prompts user for input
// Calls class functions
// @param int menuOption
// return bool again to repeat function
bool Phrase::processMenu(int menuOption)
{
	string input;
	char again;

	do
	{
		cout << "\nPlease enter a Phrase to manipulate.\n" << endl;
		getline(cin, input,'\n');
		setPhrase(input);
		//cout << phrase() << endl;
		while (!cin.fail())
		{
			if (input == "")
			{
				cin.clear();
				getline(cin, input, '\n');
				setPhrase(input);
				//cout << phrase() << endl;
			}
			else
			{
				break;
			}
		}
		do
		{
			if (input != "")
			{
				cout << "\n\nWhat do you want to do to it?\n" << endl;
				cout << " 1: Reverse Phrase \n" << endl;
				cout << " 2: Sort(Alpha - Numerically[ASCENDING]) \n" << endl;
				cout << " 3: Sort(Alpha - Numerically[DESCENDING]) \n" << endl;
				cout << " 4: Rot13 \n" << endl;
				cout << " 5: Pig Latin \n" << endl;
				cout << " 6: Enter a New Phrase OR Exit the Program \n" << endl;
				cin >> menuOption;
				while (menuOption < kOne || menuOption > kSix || cin.fail())
				{
					cout << "\nInvalid Input.\n" << endl;
					cin.clear();
					cin.ignore(kTen, '\n');
					cout << "\nPlease choose a valid menu option (1-6).\n" << endl;
					cin >> menuOption;
				}
				if (menuOption == kOne)
				{
					cout << "The original input is:................. " << input << endl;
					cout << "The phrase saved to class member is:... " << phrase() << endl;
					cout << "The result of function manipulation is: " << reversePhrase(mPhrase) << endl;
				}
				else if (menuOption == kTwo)
				{
					cout << "The original input is:................. " << input << endl;
					cout << "The phrase saved to class member is:... " << phrase() << endl;
					cout << "The result of function manipulation is: " << ascendingAlphaSortPhrase(mPhrase) << endl;
				}
				else if (menuOption == kThree)
				{
					cout << "The original input is:................. " << input << endl;
					cout << "The phrase saved to class member is:... " << phrase() << endl;
					cout << "The result of function manipulation is: " << descendingAlphaSortPhrase(mPhrase) << endl;
				}
				else if (menuOption == kFour)
				{
					cout << "The original input is:................. " << input << endl;
					cout << "The phrase saved to class member is:... " << phrase() << endl;
					cout << "The result of function manipulation is: " << encryptPhrase(mPhrase) << endl;
				}
				else if (menuOption == kFive)
				{
					cout << "The original input is:................. " << input << endl;
					cout << "The phrase saved to class member is:... " << phrase() << endl;
					cout << "The result of function manipulation is: " << pigPhrase(mPhrase) << endl;
				}
				else if (menuOption == kSix)
				{
					cout << "\n\n !Option 5! " << endl;
					break;
				}
				else
				{
					cout << "\n...You have to choose a valid menu option!\n" << endl;
				}
			}
			else
			{
				break;
			}
			
		} while (input != "");
		input = "";
		cout << "\n\nYou've chosen menu option 5\n\nWould you like to Enter a New Phrase?\nIf you choose 'No' the program will close\n Yes: Y or y\n No: Any other key\n\n" << endl;
		cin >> again;
	} while ((again == 'y')||(again == 'Y'));
	return false;
}

// Reverse phrase function
// @param string mPhrase
// Return string reversed phrase
string Phrase::reversePhrase(string mPhrase)
{
	string wholeString = phrase();
	string reversedPhrase;
	int wordsInPhrase{kOne};
	vector<string> word(wordsInPhrase);

	for (size_t i = kZero; i < wholeString.length(); i++)
	{
		if (wholeString[i]!= ' ')
		{
			word[wordsInPhrase - kOne] += wholeString[i];
		}
		else
		{
			wordsInPhrase++;
			word.resize(wordsInPhrase);
		}
	}
	reverse(word.begin(), word.end());
	for (auto &currentWord : word)
	{
		reversedPhrase.append(currentWord + " ");
	}
	return reversedPhrase;
}

// Sort in Ascending alpha order
// @param string mPhrase
// return string alphaSortPhrase
string Phrase::ascendingAlphaSortPhrase(string mPhrase)
{
	string wholeString = phrase();
	string alphaSortPhrase;
	string temp;
	int wordsInPhrase{ kOne };
	vector<string> word(wordsInPhrase);

	for (size_t i = kZero; i < wholeString.length(); i++)
	{
		if (wholeString[i] != ' ')
		{
			word[wordsInPhrase - kOne] += wholeString[i];
		}
		else
		{
			wordsInPhrase++;
			word.resize(wordsInPhrase);
		}
	}
	for (size_t i = kZero; i < wordsInPhrase; i++)
	{
		for (size_t j = kZero; j < (wordsInPhrase - kOne); j++)
		{
			if (word[j] > word [j + kOne])
			{
				temp = word[j];
				word[j] = word[j + kOne];
				word[j + kOne] = temp;
			}
			/*else
			{
				do nothing
			}*/
		}
	}
	for (auto &currentWord : word)
	{
		alphaSortPhrase.append(currentWord + " ");
	}
	return alphaSortPhrase;
}

// Sort in Descending alpha order
// @param string mPhrase
// return string alphaSortPhrase
string Phrase::descendingAlphaSortPhrase(string mPhrase)
{
	string wholeString = phrase();
	string alphaSortPhrase;
	string temp;
	int wordsInPhrase{ kOne };
	vector<string> word(wordsInPhrase);

	for (size_t i = kZero; i < wholeString.length(); i++)
	{
		if (wholeString[i] != ' ')
		{
			word[wordsInPhrase - kOne] += wholeString[i];
		}
		else
		{
			wordsInPhrase++;
			word.resize(wordsInPhrase);
		}
	}
	for (size_t i = kZero; i < wordsInPhrase; i++)
	{
		for (size_t j = kZero; j < (wordsInPhrase - kOne); j++)
		{
			if (word[j] > word[j + kOne])
			{
				temp = word[j];
				word[j] = word[j + kOne];
				word[j + kOne] = temp;
			}
			/*else
			{
				do nothing
			}*/
		}
	}
	reverse(word.begin(), word.end());
	for (auto &currentWord : word)
	{
		alphaSortPhrase.append(currentWord + " ");
	}
	return alphaSortPhrase;
}

// Encrypt phrase in ROT13
// @param string mPhrase
// return string encryptedPhrase
string Phrase::encryptPhrase(string mPhrase)
{
	string wholeString = phrase();
	string encryptedPhrase;

	for (size_t i = kZero; i < wholeString.size(); i++)
	{
		if (isalpha(wholeString[i]))
		{
			if ((tolower(wholeString[i]) - 'a') < kFourteen)
			{
				if (tolower(wholeString[i]) == 'n')
				{
					encryptedPhrase.append(kOne, wholeString[i] - kThirteen);
				}
				else
				{
					encryptedPhrase.append(kOne, wholeString[i] + kThirteen);
				}
			}
			else
			{
				encryptedPhrase.append(kOne, wholeString[i] - kThirteen);
			}
		}
		else
		{
			encryptedPhrase.append(kOne, wholeString[i]);
		}
	}
	return encryptedPhrase;
}

// Ig-pay Atin-lay

// Checks if character is a vowel
// @param char ch
// return bool true : false
bool Phrase::isVowel(char character)
{
	switch (character)
	{
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U':
	case 'Y':
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
	case 'y':
		return true;
	default:
		return false;
	}
}

// Rotates first group of consonants to the end of string
// @param string pigString
// return string rotatedString
string Phrase::rotate(string pigString)
{
	string::size_type len = pigString.length();
	string rotatedString;
	rotatedString = pigString.substr(kOne, len - kOne) + pigString[kZero];
	return rotatedString;
}

// Converts single word to pig latin
// @param string word[i]
// return string pigString
string Phrase::pigLatinString(string pigString)
{
	string::size_type len;
	bool foundVowel;
	string::size_type counter;

	if (isVowel(pigString[kZero]))
		pigString = pigString + "-way";
	else
	{
		pigString = pigString + '-';
		pigString = rotate(pigString);
		len = pigString.length();
		foundVowel = false;
		for (counter = kOne; counter < len - kOne;
			counter++)
			if (isVowel(pigString[kZero]))
			{
				foundVowel = true;
				break;
			}
			else
				pigString = rotate(pigString);
		if (!foundVowel)
			pigString = pigString.substr(kOne, len) + "-way";
		else
			pigString = pigString + "ay";
	}
	return pigString;
}

// Converts entire phrase to pig latin
// @param string mPhrase
// return string pigPhrase
string Phrase::pigPhrase(string mPhrase)
{
	string wholeString = phrase();
	string pigPhrase;
	int wordsInPhrase{ kOne };
	vector<string> word(wordsInPhrase);

	for (size_t i = kZero; i < wholeString.length(); i++)
	{
		if (wholeString[i] != ' ')
		{
			word[wordsInPhrase - kOne] += wholeString[i];
		}
		else
		{
			wordsInPhrase++;
			word.resize(wordsInPhrase);
		}
	}
	for (size_t i = kZero; i < wordsInPhrase; i++)
	{
		word[i] = pigLatinString(word[i]);
	}
	for (auto &currentWord : word)
	{
		pigPhrase.append(currentWord + " ");
	}
	return pigPhrase;
}