#include "Number.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

// Constructor
Number::Number()
{
	mNumber = kZero;
	mReversed = kZero;
	mProcessMenu = kTrue;
}

// Destructor
Number::~Number()
{
	// No action required
}

// Setters
void Number::setOriginalNumber(int newNumberForwards)
{
	mNumber = newNumberForwards;
}
void Number::setBackwardsNumber(int newNumberBackwards)
{
	mReversed = newNumberBackwards;
}

// Prompts user for input
// calls class functions
// @param int menuOption
// return bool again to repeat function
bool Number::processMenu(int menuOption)
{
	// Initialize variables to store:
	// repeat option
	// user input
	// menu option choice
	char again;
	int input;

	do {

		cout << "\nPlease enter a number\n" << endl;
		cin >> input;
		// loop that gets valid input
		// only allows int and not letters
		// or if input is 0 it
		////
		while (true)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\n Invalid input\nTry Again\n" << endl;
				cin >> input;
			}
			else

			{
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
		}
		do
		{
			if (input != kZero)
			{
				cout << "\n\nwhat do you want to do to it? \n 1: Reverse \n 2: Sort(Ascending) \n 3: Sort(Descending) \n 4: BACK to Enter Number or Exit Program \n " << endl;
				cin >> menuOption;
				// loop that gets valid input
				// only allows int 1-4
				while (menuOption < kZero || menuOption > kFour || cin.fail())
				{
					cout << "\ninvalid input.\n" << endl;
					cin.clear();
					cin.ignore(kTen, '\n');
					cout << "\nplease choose a valid input AKA one of the 4 options from 1-4... dont mess around\n" << endl;
					cin >> menuOption;
				}
				if (menuOption == kOne)
				{
					cout << "\n The original number was: "<< input << "\n The Reversed number is:  " << reverse(input) << '\n' << endl;
				}
				else if (menuOption == kTwo)
				{
					cout << "\n The original number was:          " << input << "\n The number in Ascending order is: " << sortAscending(input) << '\n' << endl;
				}
				else if (menuOption == kThree)
				{
					cout << "\n The original number was:           " << input << "\n The number in Descending order is: " << sortDescending(input) << '\n' <<endl;
				}
				else if (menuOption == kFour)
				{
					break;
				}
				else
				{
					cout << "\n...Ya gotta choose an option...\n" << endl;
				}
			}
			else
			{
				break;
			}
		} while (input != kZero);
		cout << '\n' << "\n You've Entered 0 or have chosen to go BACK \n\n Would you like to try again?\n Yes: Y or y \n No: Any other key \n" << endl;
		cin >> again;
	} while ((again == 'y') || (again == 'Y'));
	return false;
}

// Reverse function
// @param int input
// return int reversed input
int Number::reverse(int input)
{
	int reversedNumberFunc = kZero;
	int remainder;

	while (input != kZero)
	{
		remainder = input % kTen;
		reversedNumberFunc = reversedNumberFunc * kTen + remainder;
		input /= kTen;
	}
	return reversedNumberFunc;
}

// Sort in Ascending order
// @param int input
// return int input in Ascending order
int Number::sortAscending(int input)
{
	string numberAscending = "";
	int reversedNum = kZero;
	int remainder;
	int i = kZero;
	int j;
	int temp;
	int count = kZero;
	int iTwo = kZero;
	int ascendingInt = kZero;
	int arr[kTwoK];

	while (input != kZero)
	{
		count++;
		remainder = input % kTen;
		reversedNum = reversedNum * kTen + remainder;
		input /= kTen;
		if (remainder < kZero)
		{
			arr[i] = remainder * kNegOne;
			++i;
		}
		else
		{
			arr[i] = remainder;
			++i;
		}
	}

	for (i = kOne; i < count; ++i)
	{
		for(j=0;j<(count-1);++j)
			if (arr[j] > arr[j + kOne])
			{
				temp = arr[j];
				arr[j] = arr[j + kOne];
				arr[j + kOne] = temp;
			}
	}
	for (i = kZero; i < count; ++i)
		numberAscending += to_string(arr[i]);
	while (numberAscending[iTwo] == '0')
	{
		iTwo++;
	}
	numberAscending.erase(kZero, iTwo);
	ascendingInt = std::stoi(numberAscending);
	return ascendingInt;
}

// Sort in Descending order
// @param int input
// return int input in Ascending order
int Number::sortDescending(int input)
{
	string numberDescending = "";
	int reversedNum = kZero;
	int descendingInt = kZero;
	int remainder;
	int i = kZero;
	int j;
	int temp;
	int count = kZero;
	int iTwo = kZero;
	int tempCount = kZero;
	int tempIndexCount = kZero;
	int arr[kTwoK];

	while (input != kZero)
	{
		count++;
		remainder = input % kTen;
		reversedNum = reversedNum * kTen + remainder;
		input /= kTen;
		if (remainder < kZero)
		{
			arr[i] = remainder * kNegOne;
			++i;
		}
		else
		{
			arr[i] = remainder;
			++i;
		}
	}
	tempCount = count;
	tempIndexCount = count - kOne;
	for (i = kOne; i < count; ++i)
	{
		for (j = kZero; j < (count - kOne); ++j)
			if (arr[j] < arr[j + kOne])
			{
				temp = arr[j];
				arr[j] = arr[j + kOne];
				arr[j + kOne] = temp;
			}
	}
	for (i = kZero; i < count; ++i)
		numberDescending += to_string(arr[i]);
	while (numberDescending[tempIndexCount] == '0')
	{
		iTwo++;
		tempCount--;
		tempIndexCount--;
	}
	cout << tempCount;
	numberDescending.erase(tempCount, iTwo);
	descendingInt = std::stoi(numberDescending);
	return descendingInt;
}

