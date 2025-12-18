#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define max 10

class Prefix {
public:
    char stack[max];
    string infix;
    char prefix[max];
    int i;
    int top = -1;

    bool Full() {
        if (top == max - 1) {
            cout << "Stack Overflow" << endl;
            return 1;
        } else
            return 0;
    }

    bool IsEmpty() {
        if (top == -1) {
            return 1;
        } else
            return 0;
    }

    void getExp() {
        if (Full()) {
        } else {
            cout << "Enter the infix:" << endl;
            cin >> infix;
        }
    }

    void push(char item) {
        if (Full()) {
        } else {
            top++;
            stack[top] = item;
        }
    }

    char pop() {
        char c;
        if (IsEmpty()) {
        } else
            c = stack[top];
        top--;
        return c;
    }

    int precedence(char symbol) {
        switch (symbol) {
        case '$':
            return 3;
        case '/':
        case '*':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
        }
    }

    void inToPre() {
        char symbol, next;
        int j = 0;

        for (i = infix.length() - 1; i >= 0; i--) {
            symbol = infix[i];
            if (!space(symbol)) {
                switch (symbol) {
                case ')':
                    push(symbol);
                    break;
                case '(':
                    while ((next = pop()) != ')')
                        prefix[j++] = next;
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '$':
                    while (!IsEmpty() && precedence(stack[top]) > precedence(symbol))
                        prefix[j++] = pop();
                    push(symbol);
                    break;
                default:
                    prefix[j++] = symbol;
                }
            }
        }

        while (!IsEmpty())
            prefix[j++] = pop();
        prefix[j] = '\0';

        // Reverse the obtained prefix expression
        reverse(prefix, prefix + j);
    }

    int space(char c) {
        if (c == ' ' || c == '\t')
            return 1;
        else
            return 0;
    }

    void traverse() {
        i = 0;
        cout << "Prefix is: " << endl;
        while (prefix[i]) {
            cout << prefix[i++];
        }

        cout << endl;
    }
};

int main() {
    Prefix P;
    P.getExp();
    P.inToPre();
    P.traverse();

    return 0;
}