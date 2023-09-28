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
int getPrecedence(string);
int calculatePostfixExpression(string expression[], int length)
{
    if(length < 3)
    {
        return 0;
    }
    int returnVal = 0;
    int op1,op2;
    stack<string> shtack;
    
    for(int i = 0; i < length; i++)
    {
        if(isOperator(expression[i]))//Checks if a value in the expression is an operator
        {
            shtack.push(expression[i]);
        }

        if(stoi(expression[i]) <= 9 && stoi(expression[i]) >= 0) 
        {
            op1 = stoi(expression[i]);
            if(i < length-1)
            {
                op2 = stoi(expression[1+i]);
            }
            
        }


    }
        if(shtack.top() == "+")
        {
            return op1 + op2;
        }
        else if(shtack.top() == "-")
        {
            return op2 - op1;
        }
        else if(shtack.top() == "*")
        {
            return op1 * op2;
        }
        else if(shtack.top() == "/")
        {
            if(op1!=0)
            return op2/op1;
        }
        
}
bool isOperator(string c) //Checks if infix expression is an operator
{
    return (c == "+" || c == "-" || c == "/" || c == "*" || c == "%");
}
