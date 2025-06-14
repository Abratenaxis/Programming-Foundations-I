// Julio A. Bonilla
// HW5
// To Infinity and Beyond!
// Allen Baker
// Prog 1203

#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>
#include"LargeInt.h"

using namespace std;

// Function that initializes 3 LargeInt objects
// Stores fiat strings and checks string for validity
// returns int
// @ Param No parameters
int main()
{
	LargeInt Num1, Num2, Num3;
	string fiat1, fiat2;
	int setW;

	// Initialize Num3 to 0
	Num3.setLargeInt("0");
	cout << "What is the first number you want to enter?" << endl;
	getline(cin, fiat1, '\n');
	while (!Num1.isNumeric(fiat1))
	{
		cin.clear();
		cout << "\nInvalid input\nOnly digits please.\n" << endl;
		getline(cin, fiat1, '\n');
		Num1.setLargeInt(fiat1);
	}
	// Initialize Num1 to fiat1
	Num1.setLargeInt(fiat1);
	cout << "\nWhat is the second number you want to enter?" << endl;
	getline(cin, fiat2, '\n');
	while (!Num2.isNumeric(fiat2))
	{
		cin.clear();
		cout << "\nInvalid input\nOnly digits please.\n" << endl;
		getline(cin, fiat2, '\n');
		Num2.setLargeInt(fiat2);
	}
	// Initialize Num2 to fiat2
	Num2.setLargeInt(fiat2);

	while ( fiat1 != "exit" || fiat2 != "exit")
	{
		// setW is set to largest string size
		if (Num1.sizeOfBigInterger() > Num2.sizeOfBigInterger())
		{
			setW = Num1.sizeOfBigInterger();
		}
		else
		{
			setW = Num2.sizeOfBigInterger();
		}
		// Show original numbers
		cout << "First  Number:         " << right << setfill(' ') << setw(setW) << Num1.bigInterger() << '\n' << endl;
		cout << "Second Number:         " << right << setfill(' ') << setw(setW) << Num2.bigInterger() << '\n' << endl;
		cout << "Third  Number:         " << right << setfill(' ') << setw(setW) << Num3.bigInterger() << '\n' << endl;
		// Shows sum and numbers after calculations
		Num3.findSum(Num1.bigInterger(), Num2.bigInterger());
		cout << "The Sum of numbers is: "
			<< right << setw(Num3.sizeOfBigInterger()) << Num3.bigInterger() << '\n' << endl;
		cout << "First  Number remains: " << right << setfill(' ') << setw(Num3.sizeOfBigInterger()) << Num1.bigInterger() << '\n' << endl;
		cout << "Second Number remains: " << right << setfill(' ') << setw(Num3.sizeOfBigInterger()) << Num2.bigInterger() << '\n' << endl;
		cout << "Third  Number  is now: " << right << setfill(' ') << setw(Num3.sizeOfBigInterger()) << Num3.bigInterger() << '\n' << endl;
		cout << "\n" << endl;
		// Initialize Num3 to 0
		Num3.setLargeInt("0");
		cout << "Enter 'exit' to Exit" << endl;
		cout << "What is the first number you want to enter?" << endl;
		getline(cin, fiat1, '\n');
		if (fiat1 == "exit")
		{
			break;
		}
		/*else
		{
			Do Nothing;
		}*/
		while (!Num1.isNumeric(fiat1))
		{
			cin.clear();
			cout << "\nInvalid input\nOnly digits please.\n" << endl;
			getline(cin, fiat1, '\n');
			Num1.setLargeInt(fiat1);
		}
		cout << "\nWhat is the second number you want to enter?" << endl;
		getline(cin, fiat2, '\n');
		// Initialize Num1 to fiat1
		Num1.setLargeInt(fiat1);
		if (fiat2 == "exit")
		{
			break;
		}
		/*else
		{
			Do Nothing;
		}*/
		while (!Num2.isNumeric(fiat2))
		{
			cin.clear();
			cout << "\nInvalid input\nOnly digits please.\n" << endl;
			getline(cin, fiat2, '\n');
			Num2.setLargeInt(fiat2);
		}
		// Initialize Num2 to fiat2
		Num2.setLargeInt(fiat2);
		// setW is set to largest string size
		if (Num1.sizeOfBigInterger() > Num2.sizeOfBigInterger())
		{
			setW = Num1.sizeOfBigInterger();
		}
		else
		{
			setW = Num2.sizeOfBigInterger();
		}
	}
	//Num3 = Num1 + Num2;
	cout << "Thank you for using 'To Infinity and Beyond!' today!!" << endl;
	system("pause");
	return 0;
}