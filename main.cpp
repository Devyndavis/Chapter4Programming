#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    char operation;

    // Ask the user for two numbers and the operation
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter an operator (+, -, *, /): ";
    cin >> operation;
    cout << "Enter second number: ";
    cin >> num2;

    // Use nested if statements to handle different operations
    if (operation == '+') {
        cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
    } else if (operation == '-') {
        cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
    } else if (operation == '*') {
        cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
    } else if (operation == '/') {
        if (num2 != 0) {
            cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
        } else {
            cout << "Error: Division by zero is not allowed." << endl;
        }
    } else {
        cout << "Error: Unsupported operation." << endl;
    }

    return 0;
}