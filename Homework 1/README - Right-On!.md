
# Triangle Analyzer

## Overview

This program determines the type of triangle based on three user-provided side lengths. It classifies triangles as:

- **Equilateral**: All sides are equal
- **Isosceles**: Exactly two sides are equal
- **Scalene**: All sides are different

It further evaluates whether the triangle is also a **Right Triangle** by using the Pythagorean theorem, with a small tolerance for floating-point comparison.

---

## Program Features

- Accepts input for three triangle sides from the user
- Validates input to ensure side lengths are within a range (0.1 to 100.0 inches)
- Sorts the side lengths to determine shortest, middle, and longest
- Verifies whether a triangle is valid based on side length rules
- Detects:
    - **Right Scalene Triangle**
    - **Right Isosceles Triangle**
    - **Equilateral Triangle**
    - **Non-right Isosceles or Scalene Triangle**
- Allows the user to repeat the program with new inputs

---

## Program Flow

1. **Input Collection**

    - User enters three side lengths (e.g., 3.0, 4.0, 5.0)
    - Invalid input (non-numeric or out-of-range values) prompts re-entry

2. **Triangle Type Determination**

    - If all sides are equal: Equilateral
    - If two sides are equal: Isosceles
    - If all sides are different: Scalene

3. **Right Triangle Check**

    - Sides are sorted, and the longest is assumed to be the hypotenuse
    - If `a² + b² ≈ c²` within a small tolerance: Triangle is right

4. **Output**

    - Type of triangle
    - Whether it's a right triangle
    - Details on side lengths and hypotenuse calculation (if applicable)

5. **Repeat Option**

    - User is asked if they want to analyze another triangle

---

## Input Constraints

- All side lengths must be between **0.1** and **100.0** inches
- Program loops until valid input is provided

---

## Example Output

```
Enter three sides of a triangle.
Enter first side: 3
Enter second side: 4
Enter third side: 5

!!! Based off the two shortest sides the Hypotenuse will be:  5 !!!
The three sides you entered were:  3 ,  4 ,and 5
!!! According to my calculatations the Hypotenuse is: 5 !!!
Right-On!
The expected Hypotenuse(5) and the calculated Hypotenuse(5) are the same(or close enough)!!!
The differentce between the expected hypotenuse and the calculated hypotenuse is: 0
You have a Right Scalene Triangle
```

---

## Possible Enhancements

- Refactor sorting logic into a reusable function
- Replace repetitive input code with a helper function
- Add input support for floating-point precision
- Provide graphical output or visualization of the triangle
- Add unit testing for various triangle classification cases

---

## License

MIT License – Open to use, modify, and distribute.

---

## Author

Developed by Julio Bonilla
