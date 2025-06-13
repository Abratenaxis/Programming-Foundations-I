#pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

class LargeInt
{
private:
	// Instance Variables
	string mLargeInterger;

	// Class "Variables"
	static const int kZero = 0;
	static const int kTen = 10;

public:
	// Constructor
	LargeInt();

	// Destructor
	~LargeInt();

	// Setters
	void setLargeInt(string newLargeInt);

	// Getters
	string bigInterger();
	int sizeOfBigInterger();

	// Do-ers
	string findSum(string str1, string str2);
	bool isNumeric(string number);
};

