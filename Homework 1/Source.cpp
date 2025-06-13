//Julio Bonilla
//HW1
//Right-On!
//Allen Baker

// Header files
#include <iostream>
#include <cmath>
#include <cstdio>
#include <iomanip>

using namespace std;

// Initialize constants
const double tolerance = 0.0001;

// declare and initialize main()
int main()
{
	// Assign temp values to variables
	char again;
	double sideOne;
	double sideTwo;
	double sideThree;
	double apparantHypotenuse;
	double calculatedHypotenuse;
	double shortestSide;
	double middleSide;
	double longestSide;
	double oddSideOut;
	double sameSides;
	do
	{


	// Program pompts user for input of triangle sides
	cout << '\n' << endl;
	cout << "Enter three sides of a triangle." << endl;
	cout << '\n' << endl;
	cout << "Enter first side: " << endl;
	cin >> sideOne;

	// Three while loops to get 3 user inputs
	// filters unacceptable input with a while loop
	// rejecting strings, new lines, and spaces
	// using .ignore() refusing to continue without acceptable input
	//
	//	@param = double that is no less than 0.1 and no more than 100.0

	while (sideOne < 0.1 || sideOne > 100.0 || cin.fail())
	{
		cout << "Invalid input." << endl;
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "Please enter a side no less than  0.1 inches and no greater than 100.0 inches." << endl;
		cin >> sideOne;
	}
	cout << '\n' << endl;
	cout << "Enter second side: " << endl;
	cin >> sideTwo;
	while (sideTwo < 0.1 || sideTwo > 100.0 || cin.fail())
	{
		cout << "Invalid input." << endl;
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "Please enter a side no less than  0.1 inches and no greater than 100.0 inches." << endl;
		cin >> sideTwo;
	}
	cout << '\n' << endl;
	cout << "Enter third side: " << endl;
	cin >> sideThree;
	while (sideThree < 0.1 || sideThree > 100.0 || cin.fail())
	{
		cout << "Invalid input." << endl;
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "Please enter a side no less than  0.1 inches and no greater than 100.0 inches." << endl;
		cin >> sideThree;
	}
	cout << '\n' << endl;

	// This part of the function is to check input for a scalene triangle
	// followed by an argument for a right triangle
	// followed by a series of sorting 'if...else' statements that sorts input from least to greatest
	//
	// @param = double that has gone through filtering
	if ((sideOne != sideTwo) && (sideOne != sideThree) && (sideTwo != sideThree))
	{
		if ((sideOne < sideTwo) && (sideTwo < sideThree))
		{
			longestSide = sideThree;
			middleSide = sideTwo;
			shortestSide = sideOne;
		}
		else if ((sideTwo < sideOne) && (sideOne < sideThree))
		{
			longestSide = sideThree;
			middleSide = sideOne;
			shortestSide = sideTwo;
		}
		else if ((sideThree < sideOne) && (sideOne < sideTwo))
		{
			longestSide = sideTwo;
			middleSide = sideOne;
			shortestSide = sideThree;
		}
		else if ((sideOne < sideThree) && (sideThree < sideTwo))
		{
			longestSide = sideTwo;
			middleSide = sideThree;
			shortestSide = sideOne;
		}
		else if ((sideTwo < sideThree) && (sideThree < sideOne))
		{
			longestSide = sideOne;
			middleSide = sideThree;
			shortestSide = sideTwo;
		}
		else if ((sideThree < sideTwo) && (sideTwo < sideOne))
		{
			longestSide = sideOne;
			middleSide = sideTwo;
			shortestSide = sideThree;
		}

		// Write a new line
		cout << '\n' << endl;

		// Find the longest side and assigning it as the apparant hypotenuse
		apparantHypotenuse = longestSide;

		// Calculate the hypotenuse by using the pythagorean theorm
		calculatedHypotenuse = pow((shortestSide*shortestSide) + (middleSide*middleSide), 0.5);

		// Display the expected hypotenuse based on the two shortest sides
		cout << "!!! Based off the two shortest sides the Hypotenuse will be:  " << apparantHypotenuse << " !!!" << '\n' << endl;

		// Will not accept any combination of length sides in which the sum of the two shorter sides is less than or equal to the length of the longest side after sorting
		// Diplays message to use of invalid input combination
		if (longestSide >= (shortestSide + middleSide))
		{
			cout << "Bruh... these sides don't form a Triangle... (scalene/right) \n" << endl;

		}

		// If the difference of the absolute value of the longest side squared from the sum of the two shorter sides squared
		// is less than the tolerance then declare a Right Triangle that is also Scalene
		//
		// @param = double of a difference among variables below a threshold
		else if (abs(pow(longestSide, 2) - (pow(shortestSide, 2) + pow(middleSide, 2))) < tolerance)
		{
			cout << "The three sides you entered were:  " << sideOne << " ,  " << sideTwo << " ,and " << sideThree << '\n' << endl;
			cout << "!!! According to my calculatations the Hypotenuse is: " << calculatedHypotenuse << " !!!" << '\n' << endl;
			cout << "Right-On!" << '\n' << endl;
			cout << "The expected Hypotenuse(" << apparantHypotenuse << ") and the calculated Hypotenuse(" << calculatedHypotenuse << ") are the same(or close enough)!!!" << endl;
			cout << "The differentce between the expected hypotenuse and the calculated hypotenuse is: " << abs(apparantHypotenuse - calculatedHypotenuse) << '\n' << endl;
			cout << "You have a Right Scalene Triangle" << '\n' << endl;
		}

		// If it only the top level parameters are met
		// declare a Scalene Triangle
		//
		// @param = doubles that do not equal each other
		else
		{
			cout << '\n' << endl;
			cout << "This is what you would call a Scalene Triangle\n" << endl;
			cout << "Not Right!" << '\n' << endl;
			cout << "The three sides you entered were:  " << sideOne << " ,  " << sideTwo << " ,and " << sideThree << '\n' << endl;
			cout << "Those measurements in order from least to greatests are:  " << shortestSide << " ,  " << middleSide << " ,and " << longestSide << '\n' << endl;
		}

	}

	// This is the argument for an Equilateral Triangle
	// All inputs must be the same
	// Displays all three sides in same order of input
	// Declares an Equilateral Triangle
	//
	// @param = doubles must all be the same
	if ((sideOne == sideTwo) && (sideOne == sideThree) && (sideTwo == sideThree))
	{
		cout << '\n' << endl;
		cout << "This is Def an Equilateral Triangle" << '\n' << endl;
		cout << "Not Right!" << '\n' << endl;
		cout << "The three sides you entered were:  " << sideOne << " ,  " << sideTwo << " ,and " << sideThree << '\n' << endl;
	}

	// This section is an argument for an Isosceles Triangle
	// At least two input must be the same regardless of input order
	//
	// @param = double and at least two input that are equal
	else if ((sideOne == sideTwo) || (sideOne == sideThree) || (sideTwo == sideThree) || (sideTwo == sideOne) || (sideThree == sideOne) || (sideThree == sideTwo))
	{
		if ((sideOne == sideTwo) && (sideOne && sideTwo < sideThree))
		{
			longestSide = sideThree;
			middleSide = sideTwo;
			shortestSide = sideOne;
			oddSideOut = sideThree;
			sameSides = sideOne;
		}
		else if ((sideOne == sideThree) && (sideOne && sideThree < sideTwo))
		{
			longestSide = sideTwo;
			middleSide = sideThree;
			shortestSide = sideOne;
			oddSideOut = sideTwo;
			sameSides = sideOne;
		}
		else if ((sideTwo == sideThree) && (sideTwo && sideThree < sideOne))
		{
			longestSide = sideOne;
			middleSide = sideThree;
			shortestSide = sideTwo;
			oddSideOut = sideOne;
			sameSides = sideTwo;
		}
		else if ((sideTwo == sideOne) && (sideOne && sideTwo > sideThree))
		{
			longestSide = sideTwo;
			middleSide = sideOne;
			shortestSide = sideThree;
			oddSideOut = sideThree;
			sameSides = sideTwo;
		}
		else if ((sideThree == sideOne) && (sideOne && sideThree > sideTwo))
		{
			longestSide = sideThree;
			middleSide = sideOne;
			shortestSide = sideTwo;
			oddSideOut = sideTwo;
			sameSides = sideThree;
		}
		else if ((sideThree == sideTwo) && (sideTwo && sideThree > sideOne))
		{
			longestSide = sideThree;
			middleSide = sideTwo;
			shortestSide = sideOne;
			oddSideOut = sideOne;
			sameSides = sideThree;
		}

		// Write a new line
		cout << '\n' << endl;

		// Find the longest side and assigning it as the apparant hypotenuse
		apparantHypotenuse = longestSide;

		// Calculate the hypotenuse by using the pythagorean theorm
		calculatedHypotenuse = pow((shortestSide*shortestSide) + (middleSide*middleSide), 0.5);

		// Display the expected hypotenuse based on the two shortest sides
		cout << "!!! Based off the two sides the Hypotenuse will be:  " << apparantHypotenuse << " !!!" << '\n' << endl;

		// Will not accept any combination of length sides in which the sum of the two shorter sides is less than the length of the longest side after sorting
		// Diplays message to use of invalid input combination
		if (longestSide > (shortestSide + middleSide))
		{
			cout << "Bruh... these sides don't form a Triangle...(Iso) \n" << endl;

		}

		// If the difference of the absolute value of the longest side squared from the sum of the two shorter sides squared
		// is less than the tolerance then declare a Right Triangle that is also Isosceles
		//
		// @param = double of a difference among variables below a threshold
		else if (abs(pow(longestSide, 2) - (pow(shortestSide, 2) + pow(middleSide, 2))) < tolerance)
		{
			cout << "The three sides you entered were:  " << sideOne << " ,  " << sideTwo << " ,and " << sideThree << '\n' << endl;
			cout << "Those measurement of the two same length sides is:  " << sameSides << '\n' << endl;
			cout << "Those measurement of the not same length side is:  " << oddSideOut << '\n' << endl;
			cout << "!!! According to my calculatations the Hypotenuse is: " << calculatedHypotenuse << " !!!" << '\n' << endl;
			cout << "Right-On!" << '\n' << endl;
			cout << "The expected Hypotenuse(" << apparantHypotenuse << ") and the calculated Hypotenuse(" << calculatedHypotenuse << ") are the same(or close enough)!!!" << endl;
			cout << "The differentce between the expected hypotenuse and the calculated hypotenuse is: " << abs(apparantHypotenuse - calculatedHypotenuse) << '\n' << endl;
			cout << "You have a Right Isosceles Triangle" << '\n' << endl;
		}

		// If it only the top level parameters are met
		// declare an Isosceles Triangle
		//
		// @param = doubles where two are the same and one is not
		else
		{
			cout << '\n' << endl;
			cout << "This is probs an Isosceles Triangle" << '\n' << endl;
			cout << "Not Right!" << '\n' << endl;
			cout << "The three sides you entered were:  " << sideOne << " ,  " << sideTwo << " ,and " << sideThree << '\n' << endl;
			cout << "Those measurement of the two same length sides is:  " << sameSides << '\n' << endl;
			cout << "Those measurement of the not same length side is:  " << oddSideOut << '\n' << endl;
		}
	}

	// Ask to repeat program
	// If anything but 'y' or 'Y' are input then the program
	// displays a closing message and exits
	//
	// @param = char as 'y' or 'Y'
	cout << "Would you like to Tri again?  Yes (y)  or  No (n) ???\n" << endl;
	cin >> again;

	} while ((again == 'y') || (again == 'Y'));

	// Display closing message
	cout << '\n' << "Thanks for Tri-ing out my program!!\n" << endl;
	system("PAUSE");
	return 0;
}