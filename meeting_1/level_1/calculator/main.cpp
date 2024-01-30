// Solution code for calculator_starter.cpp
#include <iostream>

using namespace std;

/**
 * Adds two numbers.
 * 
 * @param first The first number.
 * @param second The second number.
 * @return The sum of the two numbers.
 */
double addNumbers(double first, double second) {
  return first + second;
}

/**
 * Subtracts two numbers.
 * 
 * @param first The first number.
 * @param second The second number.
 * @return The difference of the two numbers.
 */
double subtractNumbers(double first, double second) {
  return first - second;
}

/**
 * Multiplies the two numbers together.
 * 
 * @param first The first number.
 * @param second The second number.
 * @return The product of the two numbers.
 */
double multiplyNumbers(double first, double second) {
  return first * second;
}

/**
 * Divides the dividend (first) by the divisor (second).
 * 
 * @param first The first number.
 * @param second The second number.
 * @return The quotient of the two numbers.
 */
double divideNumbers(double first, double second) {
  return first / second;
}

int main() {

  cout << "Welcome to Calculator\n";

  while (true) {
    double firstNumber, secondNumber;

    cout << "Enter your first number: ";

    // Get user input for the first number.
    cin >> firstNumber;

    cout << "Enter your second number: ";

    // Get user input for the second number.
    cin >> secondNumber;

    /**
     * Implement an if/else if/else condition that handles how the user chooses their desired
     * arithmetic operation. As per the pesudocode:
     * 
     * if arithmetic_operation is "add", then store the result of addNumbers() with the two numbers in the variable result.
     * if arithmetic_operation is "subtract", then store the result of subtractNumbers() with the two numbers in the variable result.
     * if arithmetic_operation is "multiply", then store the result of multiplyNumbers() with the two numbers in the variable result.
     * if arithmetic_operation is "divide", then store the result of divideNumbers() with the two numbers in the variable result.
     * otherwise, print an error message indicating that the user entered an invalid operation. Note that this should
     * not quit the program entirely. It should not also print the "final result" message as well.
     * 
     * Mini challenge: Can you think of an implementation without printing the "final result" message in each condition?
     */

    string arithmetic_operation;
    double result;


    cout << "Select an operation to perform on these two numbers (add/subtract/multiply/divide): ";

    cin >> arithmetic_operation;

    // Implement the above instructions here

    if (arithmetic_operation == "add") {
      result = addNumbers(firstNumber, secondNumber);
    } else if (arithmetic_operation == "subtract") {
      result = subtractNumbers(firstNumber, secondNumber);
    } else if (arithmetic_operation == "multiply") {
      result = multiplyNumbers(firstNumber, secondNumber);
    } else if (arithmetic_operation == "divide") {
      result = divideNumbers(firstNumber, secondNumber);
    } else {
      cout << "Invalid operation.\n";
      continue; // Mini challenge answer. Skip the below code and immediately go back to the start of the while loop
    }

    cout << "The final result is: " << result << ".\n";

  }



  return 0;
}