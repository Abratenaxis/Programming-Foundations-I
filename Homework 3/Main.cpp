//Julio Bonilla
//HW3
//Countdown
//Allen Baker
//PROG 1203

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include "Number.h"

using namespace std;

// Function that keeps processMenu looping as long as processMenu passes true
// Creates an instance object (original) of the class Number
// returns int
// @ param bool
int main()
{
    Number original;
    // if processMenu passes false then display closing statement
    // and breaks loop
    while (!original.processMenu(true))
    {
        cout << '\n' << "Thanks for using 'Countdown'!" << endl;
        break;
    }
    // once while loop breaks
    // execute system pause
    system("pause");
    return 0;
}