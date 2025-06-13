// Julio A. Bonilla
// HW4
// Say What?
// Allen Baker
// PROG 1203

#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>
#include "Phrase.h"

using namespace std;

// Function that keeps processMenu looping as long as processMenu passes true
// Creates an instance object (userPhrase) of the class Phrase
// returns int
// @ param bool
int main()
{
    Phrase userPhrase;
    cout << "Hi! Thank you for using 'Say What?' today." << endl;
    while (!userPhrase.processMenu(true))
    {
        cout << '\n' << "Thanks for using 'Say What?' today!!" << endl;
        break;
    }

    system("pause");
    return 0;
}