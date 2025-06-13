#include "LargeInt.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

// Constructor
LargeInt::LargeInt()
{
	mLargeInterger = "";
}

// Destructor
LargeInt::~LargeInt()
{
}

// Setters
void LargeInt::setLargeInt(string newLargeInt)
{
	mLargeInterger = newLargeInt;
}

// Getters
string LargeInt::bigInterger()
{
	return mLargeInterger;
}

int LargeInt::sizeOfBigInterger()
{
	int size = mLargeInterger.length();
	return size;
}

// Do-ers
// Function for finding sum of larger numbers 
string LargeInt::findSum(string number1, string number2)
{
	// Before proceeding further, make sure length 
	// of number2 is larger. 
	if (number1.length() > number2.length())
	{
		swap(number1, number2);
	}
	/*else
	{
		Do Nothing;
	}*/
	// Take an empty string array for storing result 
	string stringSum = "";

	// Calculate lenght of both string arrays
	int n1 = number1.length(), n2 = number2.length();

	// Reverse both of strings to store the one's digit in element 0 of array
	reverse(number1.begin(), number1.end());
	reverse(number2.begin(), number2.end());

	int carry = kZero;
	for (int i = kZero; i < n1; i++)
	{
		// Compute sum of 
		// current digits and carry 
		int sum = ((number1[i] - '0') + (number2[i] - '0') + carry);
		stringSum.push_back(sum % kTen + '0');

		// Calculate carry for next step 
		carry = sum / kTen;
	}

	// Add remaining digits of larger number 
	for (int i = n1; i < n2; i++)
	{
		int sum = ((number2[i] - '0') + carry);
		stringSum.push_back(sum % kTen + '0');
		carry = sum / kTen;
	}

	// Add remaining carry 
	if (carry)
	{
		stringSum.push_back(carry + '0');
	}
	/*else
	{
		Do Nothing;
	}*/
	// reverse resultant string 
	reverse(stringSum.begin(), stringSum.end());
	// set LargeInt to stringSum
	setLargeInt(stringSum);
	return stringSum;
}

bool LargeInt::isNumeric(string number)
{
	bool numeric = true;
	for (int i = kZero; number[i]!= '\0'; i++)
	{
		if (number[i] < '0' || number[i] > '9')
		{
			numeric = false;
		}
		/*else
		{
			Do Nothing;
		}*/
	}
	return numeric;
}