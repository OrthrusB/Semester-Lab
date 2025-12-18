#include <iostream>
#include <string>

using namespace std;

// DFA states
enum State {
    Q0, // Initial state, also part of (a+b)*
    Q1, // After seeing 'a' (first char of 'abb')
    Q2, // After seeing 'ab' (first two chars of 'abb')
    Q3, // After seeing 'abb' (accepting state)
    Q4  // Trap state for invalid transitions
};

// Function to simulate DFA for (a+b)*abb
bool simulateDFA(const string& input) {
    State currentState = Q0; // Start at initial state

    for (char c : input) {
        switch (currentState) {
            case Q0:
                if (c == 'a')
                    currentState = Q1; // Start matching 'abb'
                else if (c == 'b')
                    currentState = Q0; // Stay in (a+b)* loop
                else
                    currentState = Q4; // Invalid input, go to trap state
                break;
            case Q1:
                if (c == 'b')
                    currentState = Q2; // Matched 'ab', expect 'b'
                else if (c == 'a')
                    currentState = Q1; // Start over for 'abb'
                else
                    currentState = Q4; // Invalid input
                break;
            case Q2:
                if (c == 'b')
                    currentState = Q3; // Matched 'abb', go to accepting state
                else if (c == 'a')
                    currentState = Q1; // Start over for 'abb'
                else
                    currentState = Q4; // Invalid input
                break;
            case Q3:
                if (c == 'a')
                    currentState = Q1; // Start over for another 'abb'
                else if (c == 'b')
                    currentState = Q0; // Back to (a+b)* loop
                else
                    currentState = Q4; // Invalid input
                break;
            case Q4:
                // Trap state: stay here for any input
                currentState = Q4;
                break;
        }
    }

    // Q3 is the accepting state
    return currentState == Q3;
}

int main() {
    string input;
    cout << "Enter a string to test (only 'a' and 'b' allowed): ";
    cin >> input;

    // Validate input to contain only 'a' and 'b'
    bool validInput = true;
    for (char c : input) {
        if (c != 'a' && c != 'b') {
            validInput = false;
            break;
        }
    }

    if (!validInput) {
        cout << "Invalid input! Please use only 'a' and 'b'.\n";
        return 1;
    }

    // Run DFA simulation
    if (simulateDFA(input)) {
        cout << "The string \"" << input << "\" is ACCEPTED by the DFA.\n";
    } else {
        cout << "The string \"" << input << "\" is REJECTED by the DFA.\n";
    }

    return 0;
}