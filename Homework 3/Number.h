#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

class Number
{
private:
    // Instance Variables
    int mNumber;
    int mReversed;
    bool mProcessMenu;
    //int mCount = kZero;

    // Class "Variables"
    static const int kNegOne = -1;
    static const int kZero = 0;
    static const int kOne = 1;
    static const int kTwo = 2;
    static const int kThree = 3;
    static const int kFour = 4;
    static const int kTen = 10;
    static const int kTwoK = 2000;
    static const bool kTrue = true;
public:
    // Constructor
    Number();

    // Destructor
    ~Number();

    // Setters
    void setOriginalNumber(int newNumberForwards);
    void setBackwardsNumber(int newNumberBackwards);

    // Getters
    bool processMenu(int menuOption);

    // Formatters
    int reverse(int input);
    int sortAscending(int input);
    int sortDescending(int input);
};

