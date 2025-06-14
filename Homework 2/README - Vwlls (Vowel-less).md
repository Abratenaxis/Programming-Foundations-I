# Vwlls (Vowel-less)

## Overview

This program takes user input in the form of a string and allows the user to selectively remove specific types of characters:

- **Vowels**
- **Consonants**
- **Digits**
- **Punctuation Marks**

The program continues to prompt the user until they choose to exit.

---

## Features

- Accepts a full line of text from the user
- Allows removal of specific character categories
- Validates menu input to prevent invalid options
- Loops until the user decides to exit

---

## How It Works

### 1. **Character Type Detection Functions**

The program defines helper functions to determine if a character is:

- A **vowel** (`isVowel`) – e.g., 'a', 'E'
- A **consonant** (`isConsonant`) – e.g., 'b', 'Z'
- A **digit** (`isDigit`) – e.g., '3', '9'
- A **punctuation mark** (`isPunctuation`) – e.g., '.', '!', ','

These use arrays of characters and `std::find` to check for inclusion.

### 2. **Removal Functions**

Each category has a corresponding `remove*` function:

- `removeVowel(string)`
- `removeConsonant(string)`
- `removeDigit(string)`
- `removePunctuation(string)`

They use `std::remove_if` with the helper checkers to eliminate the specified characters.

### 3. **Main Menu (**``**)**

- Prompts the user for a string
- Asks the user which type of character to remove
- Applies the relevant function
- Displays the modified string
- Asks if the user wants to repeat

### 4. **Program Entry (**``**)**

The `main()` function simply loops through `processMenu()` until the user opts to quit.

---

## Example Run

```
please enter a string of words or numbers or punctuation marks!
> Hello, World! 123

what do you want to leave out?
 1: vowels
 2: consonants
 3: digits
 4: punctuation marks
> 1

Hello, World! 123
Hll, Wrld! 123

want to try again? y or n
> n

thanks for playing!
```

---

## Potential Improvements

- Improve menu readability and input prompts
- Support for upper/lower case toggle
- Option to remove multiple categories at once
- GUI interface or web-based version
- Unit tests for each character filter function

---

## License

MIT License – Free to use, modify, and distribute.

---

## Author

Developed by Julio Bonilla

