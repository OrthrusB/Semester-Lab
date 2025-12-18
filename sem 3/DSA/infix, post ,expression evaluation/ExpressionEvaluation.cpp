#include <iostream>
#include <cmath>
#include <cctype>
#include <cstring>

using namespace std;

class ExpressionEvaluation {
    double stack[20];  // Changed the stack to hold doubles
    double op1, op2;   // Changed op1 and op2 to doubles
    int top;

public:
    ExpressionEvaluation() {
        top = -1;
    }

    void push(double x) {
        top++;
        stack[top] = x;
    }

    double pop() {
        return stack[top--];
    }

    void evaluation() {
        char postfix[20];
        double res;  // Changed res to a double
        cout << "Enter the postfix expression: ";
        cin >> postfix;

        for (int i = 0; postfix[i] != '\0'; i++) {
            if (isdigit(postfix[i]))
                push(postfix[i] - '0');
            else {
                op2 = pop();
                op1 = pop();
                switch (postfix[i]) {
                    case '+':
                        push(op1 + op2);
                        break;
                    case '-':
                        push(op1 - op2);
                        break;
                    case '*':
                        push(op1 * op2);
                        break;
                    case '/':
                        if (op2 != 0)  // Check for division by zero
                            push(op1 / op2);
                        else {
                            cerr << "Error: Division by zero." << endl;
                            return;
                        }
                        break;
                    case '^':
                        res = pow(op1, op2);
                        push(res);
                        break;
                }
            }
        }
        cout << "The result is " << pop() << endl;
    }
};

int main() {
    ExpressionEvaluation e;
    e.evaluation();
    return 0;
}

//PostEvaluation
