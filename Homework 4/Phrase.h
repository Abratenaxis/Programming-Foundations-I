#pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

class Phrase
{
private:
    // Instance Variables
    string mPhrase;

    // Class "Variables"
    static const int kZero = 0;
    static const int kOne = 1;
    static const int kTwo = 2;
    static const int kThree = 3;
    static const int kFour = 4;
    static const int kFive = 5;
    static const int kSix = 6;
    static const int kTen = 10;
    static const int kTwelve = 12;
    static const int kThirteen = 13;
    static const int kFourteen = 14;

public:
    // Constructor
    Phrase();

    // Destructor
    ~Phrase();

    // Setters
    void setPhrase(string newPhrase);

    // Getters
    string phrase();

    // Do-ers
    bool processMenu(int menuOption);
    string reversePhrase(string mPhrase);
    string ascendingAlphaSortPhrase(string mPhrase);
    string descendingAlphaSortPhrase(string mPhrase);
    string encryptPhrase(string mPhrase);

    // Ig-pay Atin-lay
    bool isVowel(char character);
    string rotate(string pigString);
    string pigLatinString(string pigString);
    string pigPhrase(string mPhrase);
};

