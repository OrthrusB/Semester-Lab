#include<iostream>
#define size 3
using namespace std;

class array {
    int top;

public:
    int n;
    int a[size];

    array() {
        top = -1;
        for (int i = 0; i < size; i++) {
            a[i] = 0;
        }
    }

    bool isempty() {
        return (top == -1);
    }

    bool isfull() {
        return (top == size - 1);
    }

    void insert(int pos, int ele) {
        if (isfull()) {
            cout << "Error: Array is full. Cannot insert more elements." << endl;
        }
        else if (pos < 0 || pos > top + 1) {
            cout << "Error: Invalid position for insertion." << endl;
        }
        else {
            for (int i = top; i >= pos; i--) {
                a[i + 1] = a[i];
            }
            a[pos] = ele;
            top++;
            cout << "Element " << ele << " inserted at position " << pos << "." << endl;
            cout << "Now, the elements are: ";
            display();
        }
    }

    void deletion(int pos) {
        if (isempty()) {
            cout << "Error: The array is empty. Cannot perform deletion." << endl;
        }
        else if (pos < 0 || pos > top) {
            cout << "Error: Invalid position for deletion." << endl;
        }
        else {
            cout << "Element " << a[pos] << " at position " << pos << " deleted." << endl;
            a[pos] = 0;
            for (int i = pos; i < top; i++) {
                a[i] = a[i + 1];
            }
            top--;
            cout << "After deletion, the elements are: ";
            display();
        }
    }

    void makeempty() {
        if (isempty()) {
            cout << "The array is already empty." << endl;
        }
        else {
            top = -1;
            for (int i = 0; i < size; i++) {
                a[i] = 0;
            }
            cout << "The array is now empty." << endl;
        }
    }

    void display() {
        if (isempty()) {
            cout << "The array is empty." << endl;
        }
        else {
            cout << "[ ";
            for (int i = 0; i <= top; i++) {
                cout << a[i] << " ";
            }
            cout << "]" << endl;
        }
    }
};

int main() {
    array a1;
    int pos, ele, option;
    do {
        cout << "\nEnter the preferred option: " << endl;
        cout << "1. Insertion" << endl;
        cout << "2. Deletion" << endl;
        cout << "3. Check if empty" << endl;
        cout << "4. Check if full" << endl;
        cout << "5. Make empty" << endl;
        cout << "6. Display" << endl;
        cout << "7. Exit" << endl;
        cout << "Choose option (1-7): ";
        cin >> option;

        switch (option) {
            case 1:
                if (a1.isfull()) {
                    cout << "Error: Array is full. Cannot insert more elements." << endl;
                }
                else {
                    cout << "Enter the position to be inserted at: ";
                    cin >> pos;
                    cout << "Enter the element to be inserted: ";
                    cin >> ele;
                    a1.insert(pos, ele);
                }
                break;

            case 2:
                if (a1.isempty()) {
                    cout << "Error: The array is empty. Cannot perform deletion." << endl;
                }
                else {
                    cout << "Enter the position to be deleted: ";
                    cin >> pos;
                    a1.deletion(pos);
                }
                break;

            case 3:
                if (a1.isempty()) {
                    cout << "The array is empty." << endl;
                }
                else {
                    cout << "The array is not empty." << endl;
                }
                break;

            case 4:
                if (a1.isfull()) {
                    cout << "The array is full." << endl;
                }
                else {
                    cout << "The array is not full." << endl;
                }
                break;

            case 5:
                a1.makeempty();
                break;

            case 6:
                a1.display();
                break;

            case 7:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Error: Invalid option. Please choose a number from 1 to 7." << endl;
        }
    } while (option != 7);

    return 0;
}
