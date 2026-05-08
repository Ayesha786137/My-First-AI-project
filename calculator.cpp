// Calculator in C++
// Author: Ayesha
// Date: 2026
// Description: A simple calculator that performs +, -, *, /

#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    char op;
    
    cout << "\n========== SIMPLE CACULATOR ==========\n";
    cout << "Enter first number: ";
    cin >> num1;
    
    cout << "Enter operator (+, -, *, /): ";
    cin >> op;
    
    cout << "Enter second number: ";
    cin >> num2;
    
    // Perform calculation based on operator
    switch(op) {
        case '+':
            result = num1 + num2;
            cout << "\n✅ Result: " << num1 << " + " << num2 << " = " << result << endl;
            break;
            
        case '-':
            result = num1 - num2;
            cout << "\n✅ Result: " << num1 << " - " << num2 << " = " << result << endl;
            break;
            
        case '*':
            result = num1 * num2;
            cout << "\n✅ Result: " << num1 << " × " << num2 << " = " << result << endl;
            break;
            
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                cout << "\n✅ Result: " << num1 << " ÷ " << num2 << " = " << result << endl;
            } else {
                cout << "\n❌ Error: Cannot divide by zero!" << endl;
            }
            break;
            
        default:
            cout << "\n❌ Error: Invalid operator!" << endl;
    }
    
    cout << "\n=======================================\n";
    return 0;
}