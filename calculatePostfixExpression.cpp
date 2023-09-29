#include <string>
#include <stack>
using namespace std;

//Calculates a postfix expression with integer operands using a stack
//The expression is represented using an array of strings
//Each string is either an operand or operator symbol
//Operator symbols:
//"+" addition
//"-" subtraction
//"*" multiplication
//"/" divison
//"%" remainder
//Example expression: "8", "5", "-" evaluates to a result of 3:
//1: push 8, 2: push 5,
//3: "-"-> pop top two values, earlier value is the left-side operand: 8 - 5
//The result of the operation (8-5) is 3, push 3 onto stack
//After evaluation of the expression, the final result should be
//the only value on the stack, return 0 if the stack is
//non-empty after popping the result
//Return 0 if expression is zero-length or if there are insufficient operands
//for an operation
//The STL Stack class can be used
//To easily convert a numeric string to an int you may use the stoi() function
//which takes a string as a parameter and returns a string


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
