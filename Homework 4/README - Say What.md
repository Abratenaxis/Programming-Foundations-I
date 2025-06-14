# Say What?

## Overview

**Say What?** is an interactive console-based program that allows users to enter a phrase and apply various transformations to it. This program demonstrates string manipulation techniques and menu-driven interaction using C++ classes and methods.

---

## Features

- User-friendly menu system
- Accepts and processes user-entered phrases
- Provides multiple phrase manipulation operations:
    - Reverse word order
    - Sort words in ascending alphabetical order
    - Sort words in descending alphabetical order
    - Encrypt using ROT13
    - Translate to Pig Latin
- Repeats menu until user chooses to exit
- Input validation and clear prompts

---

## File Structure

### `main.cpp`

- Entry point of the program
- Creates an instance of the `Phrase` class
- Calls `processMenu()` to handle user interaction and loop logic

### `Phrase.h`

- Header file declaring the `Phrase` class and its public/private members
- Contains utility constants (e.g., `kOne`, `kThirteen`) for internal logic
- Declares all methods used for phrase processing

### `Phrase.cpp`

- Implements the logic for each menu option
- Defines methods such as:
    - `reversePhrase()` – Reverses the word order in a phrase
    - `ascendingAlphaSortPhrase()` – Alphabetically sorts words
    - `descendingAlphaSortPhrase()` – Same as above but in reverse
    - `encryptPhrase()` – Applies ROT13 to each character
    - `pigPhrase()` – Translates the phrase into Pig Latin
    - Supporting methods like `isVowel()` and `rotate()`

---

## How It Works

1. **User Input**:

    - Prompts user to enter a phrase
    - Handles empty input validation

2. **Menu Options**: User selects from:

    1. Reverse phrase
    2. Sort words ascending
    3. Sort words descending
    4. ROT13 encrypt
    5. Pig Latin translation
    6. Re-enter phrase or exit

3. **Phrase Manipulation**:

    - The appropriate function processes the input string
    - Results are printed clearly for the user

4. **Loop Logic**:

    - The program continues until the user declines to enter a new phrase

---

## Example Run

```
Hi! Thank you for using 'Say What?' today.

Please enter a Phrase to manipulate:
> Hello world this is fun

What do you want to do to it?
 1: Reverse Phrase
 2: Sort(Alpha - Numerically[ASCENDING])
 3: Sort(Alpha - Numerically[DESCENDING])
 4: Rot13
 5: Pig Latin
 6: Enter a New Phrase OR Exit the Program
> 1

The original input is:................. Hello world this is fun
The result of function manipulation is: fun is this world Hello

Would you like to Enter a New Phrase?
Yes: Y or y
No: Any other key
> n

Thanks for using 'Say What?' today!!
```

---

## Build Instructions

This project uses standard C++ libraries. To compile and run:

```bash
g++ -o SayWhat main.cpp Phrase.cpp
./SayWhat
```

Ensure all three files (`main.cpp`, `Phrase.cpp`, and `Phrase.h`) are in the same directory.

---

## Future Improvements

- Trim whitespace and improve punctuation handling
- Add word/character count statistics
- Enhance ROT13 for full sentence capitalization
- Improve Pig Latin logic for punctuation and edge cases
- Add GUI or web interface

---

## License

MIT License — Free to use, modify, and distribute.

---

## Author

Developed by Julio Bonilla

