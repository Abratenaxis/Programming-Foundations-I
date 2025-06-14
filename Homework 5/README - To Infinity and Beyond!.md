# To Infinity and Beyond!

## Overview

**To Infinity and Beyond!** is a C++ console application that allows users to input large integer values as strings and calculates their sum. The program uses a custom `LargeInt` class to handle arbitrarily large numbers that exceed built-in data types, emphasizing input validation, custom addition logic, and clean formatting.

---

## Features

- Accepts user input for very large integers
- Validates input to ensure only digits are processed
- Dynamically calculates and formats results
- Custom string-based addition algorithm
- Clean and readable output with aligned formatting
- Repeats operation in a loop until the user enters "exit"

---

## File Structure

### `main.cpp`

- Program entry point
- Manages input/output operations
- Loops until user chooses to exit
- Calls `LargeInt` methods to validate input, set values, and calculate sum

### `LargeInt.h`

- Class declaration for `LargeInt`
- Contains:
    - Private member variable `mLargeInterger`
    - Constants `kZero`, `kTen`
    - Public methods for setting/getting values and performing operations

### `LargeInt.cpp`

- Implements `LargeInt` methods:
    - `setLargeInt()` – Sets the internal string
    - `bigInterger()` – Returns the current large integer as a string
    - `sizeOfBigInterger()` – Returns the string length
    - `findSum()` – Performs digit-by-digit addition with carry
    - `isNumeric()` – Checks if a string contains only numeric characters

---

## How It Works

1. Prompts user to enter two numbers
2. Validates input (only digits allowed)
3. Displays each number and their current state
4. Uses `findSum()` to calculate their sum
5. Displays the result with proper alignment
6. Resets the third number and prompts for new input or exit

---

## Example Run

```
What is the first number you want to enter?
> 12345678901234567890

What is the second number you want to enter?
> 98765432109876543210

First  Number:         12345678901234567890
Second Number:         98765432109876543210
Third  Number:         0
The Sum of numbers is: 111111111011111111100

Enter 'exit' to Exit
What is the first number you want to enter?
> exit
Thank you for using 'To Infinity and Beyond!' today!!
```

---

## Build Instructions

Ensure all three files (`main.cpp`, `LargeInt.cpp`, `LargeInt.h`) are in the same directory. Compile with a C++ compiler:

```bash
g++ -o ToInfinity main.cpp LargeInt.cpp
./ToInfinity
```

---

## Future Improvements

- Improve string validation to handle whitespace and other edge cases
- Add subtraction and multiplication support
- Enhance formatting for longer numbers
- Support input/output file streams
- Implement unit tests for LargeInt methods

---

## License

MIT License — Free to use, modify, and distribute.

---

## Author

Developed by [Your Name Here]

