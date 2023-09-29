#include <string>
#include <stack>

using namespace std;

bool isOperator(string);
int returnOperator(int, int, string);

int calculatePostfixExpression(string expression[], int length) {
    if (length == 0) {
        return 0; // Empty expression
    }

    stack<int> shtack; // Stack of integers

    for (int i = 0; i < length; i++) {
        if (!isOperator(expression[i])) {
            // Operand, push onto the stack
            shtack.push(stoi(expression[i]));
        } else {
            // Operator, pop the top two values and perform the operation
            if (shtack.size() < 2) {
                return 0; // Not enough operands for the operation
            }
            int b = shtack.top();
            shtack.pop();
            int a = shtack.top();
            shtack.pop();
            int result = returnOperator(a, b, expression[i]);
            shtack.push(result);
        }
    }

    if (shtack.size() != 1) {
        cerr << "Error: Invalid expression or operators left on the stack" << endl;
        return 0; // Invalid expression or operators left on the stack
    }

    return shtack.top();
}

bool isOperator(string c) {
    return (c == "+" || c == "-" || c == "/" || c == "*" || c == "%");
}

int returnOperator(int a, int b, string val) {
    if (val == "+") {
        return a + b;
    } else if (val == "-") {
        return a - b;
    } else if (val == "/") {
        if (b == 0) {
            cerr << "Error: Division by zero" << endl;
            return 0; // Division by zero error
        }
        return a / b;
    } else if (val == "*") {
        return a * b;
    } else if (val == "%") {
        if (b == 0) {
            cerr << "Error: Modulo by zero" << endl;
            return 0; // Modulo by zero error
        }
        return a % b;
    }
    cerr << "Error: Invalid operator: " << val << endl;
    return 0; // Invalid operator error
}
