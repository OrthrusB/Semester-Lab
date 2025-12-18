#include <iostream>
#define size 5
using namespace std;

class stack {
    int arr[size];
    int top;

public:
    stack() {
        top = -1;
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }

    bool isempty() {
        return (top == -1);
    }

    bool isfull() {
        return (top == size - 1);
    }

    void push(int val) {
        if (isfull()) {
            cout << "Error: Stack overflow. Cannot push more elements." << endl;
        } else {
            top++;
            arr[top] = val;
            cout << val << " pushed onto the stack." << endl;
        }
    }

    int pop() {
        if (isempty()) {
            cout << "Error: Stack underflow. Cannot pop from an empty stack." << endl;
            return 0;
        } else {
            int popvalue = arr[top];
            arr[top] = 0;
            top--;
            cout << "Popped value: " << popvalue << endl;
            return popvalue;
        }
    }

    int count() {
        return (top + 1);
    }

    int peek(int pos) {
        if (pos < 0 || pos > top) {
            cout << "Error: Invalid position for peek." << endl;
            return 0;
        } else {
            return arr[pos];
        }
    }

    void change(int pos, int val) {
        if (pos < 0 || pos > top) {
            cout << "Error: Invalid position for change." << endl;
        } else {
            arr[pos] = val;
            cout << "Value changed at position " << pos << endl;
        }
    }

    void display() {
        if (isempty()) {
            cout << "The stack is empty." << endl;
        } else {
            cout << "Stack elements (from top to bottom): ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    stack s1;
    int option, position, value;

    do {
        cout << "\nWhat operation do you want to perform? If you want to exit, press 0." << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Check if empty" << endl;
        cout << "4. Check if full" << endl;
        cout << "5. Peek" << endl;
        cout << "6. Count" << endl;
        cout << "7. Change" << endl;
        cout << "8. Display" << endl;
        cout << "9. Clear screen" << endl;
        cout << "Choose option (0-9): ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter the element to push: ";
                cin >> value;
                s1.push(value);
                break;

            case 2:
                s1.pop();
                break;

            case 3:
                if (s1.isempty())
                    cout << "The stack is empty." << endl;
                else
                    cout << "The stack is not empty." << endl;
                break;

            case 4:
                if (s1.isfull())
                    cout << "The stack is full." << endl;
                else
                    cout << "The stack is not full." << endl;
                break;

            case 5:
                cout << "Enter the position to peek: ";
                cin >> position;
                cout << "Peek value at position " << position << ": " << s1.peek(position) << endl;
                break;

            case 6:
                cout << "Number of items in the stack: " << s1.count() << endl;
                break;

            case 7:
                cout << "Enter the position to change: ";
                cin >> position;
                cout << "Enter the new value: ";
                cin >> value;
                s1.change(position, value);
                break;

            case 8:
                s1.display();
                break;

            case 9:
                system("cls");
                break;

            case 0:
                cout << "Exiting the program. Bye!" << endl;
                break;

            default:
                cout << "Error: Invalid option. Please choose a number from 0 to 9." << endl;
        }

    } while (option != 0);

    return 0;
}
