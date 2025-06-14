# Countdown Program

## Overview

This program allows a user to enter a number and then choose to perform one of three operations on it:

- **Reverse the digits**
- **Sort digits in ascending order**
- **Sort digits in descending order**

The program loops through input and menu selections until the user decides to quit.

---

## Features

- Input validation for integers
- Character-based menu system with input checking
- Reverse a number using arithmetic
- Sort digits using simple array sorting logic
- Removes leading/trailing zeroes intelligently

---

## File Structure

### `main.cpp`

- Instantiates a `Number` object
- Calls `processMenu()` repeatedly until the user exits
- Displays exit message and pauses before quitting

### `Number.h`

- Header file declaring the `Number` class
- Contains:
    - Constructor and destructor
    - Member variables for input and processed numbers
    - Constants used in logic
    - Public methods: `setOriginalNumber`, `setBackwardsNumber`, `processMenu`, `reverse`, `sortAscending`, `sortDescending`

### `Number.cpp`

- Implements all logic declared in `Number.h`
- **processMenu()**: Handles input, validates options, and dispatches to operations
- **reverse()**: Reverses the digits of a number
- **sortAscending()**: Sorts digits in increasing order
- **sortDescending()**: Sorts digits in decreasing order

---

## How It Works

1. **Input Handling**:

    - User is prompted to enter a number
    - Input is validated (rejects letters and invalid numbers)

2. **Operation Menu**:

    - Prompts user to choose:
        1. Reverse number
        2. Sort digits ascending
        3. Sort digits descending
        4. Return to input or exit

3. **Operations**:

    - `reverse()`: Uses modulus and division to rebuild the number backwards
    - `sortAscending()`: Extracts digits into array, sorts, converts back to int
    - `sortDescending()`: Same as ascending but sorts in reverse order

4. **Repeat Option**:

    - After each operation, user is asked if they want to continue

---

## Example Run

```
Please enter a number:
> 32910

What do you want to do to it?
 1: Reverse
 2: Sort(Ascending)
 3: Sort(Descending)
 4: BACK to Enter Number or Exit Program
> 2

The original number was: 32910
The number in Ascending order is: 1239

Would you like to try again?
 Yes: Y or y
 No: Any other key
> n

Thanks for using 'Countdown'!
```

---

## Notes & Potential Improvements

- Simplify sorting logic using STL containers (`std::vector` and `std::sort`)
- Add support for negative numbers and error edge cases
- Remove unnecessary global constants like `kTwoK`
- Add support for large integers (use `long long` or strings)
- Consider separating logic from UI for testability

---

## License

MIT License – Free to use, modify, and distribute.

---

## Author

Developed by Julio Bonilla

