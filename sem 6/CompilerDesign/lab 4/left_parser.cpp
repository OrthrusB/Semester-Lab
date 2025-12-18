#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// Structure to represent grammar rules
struct Rule {
    char left;
    string right;
};

// Function to check if character is a terminal
bool isTerminal(char c) {
    return (c == 'i' || c == '+' || c == '*');
}

// Function to perform shift-reduce parsing
void shiftReduceParser(string input, vector<Rule>& rules) {
    stack<char> parserStack;
    string buffer = input + "$"; // Add end marker
    int ip = 0; // Input pointer
    
    cout << "Stack\t\tInput\t\tAction\n";
    cout << "----------------------------------------\n";
    
    parserStack.push('$'); // Push end marker to stack
    
    while (true) {
        // Print current state
        string stackContent;
        stack<char> temp = parserStack;
        while (!temp.empty()) {
            stackContent = temp.top() + stackContent;
            temp.pop();
        }
        
        cout << stackContent << "\t\t" << buffer.substr(ip) << "\t\t";
        
        // Check for reduction
        bool reduced = false;
        for (const auto& rule : rules) {
            string stackTop;
            stack<char> tempStack = parserStack;
            for (int i = rule.right.length() - 1; i >= 0 && !tempStack.empty(); i--) {
                stackTop = tempStack.top() + stackTop;
                tempStack.pop();
            }
            
            if (stackTop == rule.right) {
                // Perform reduction
                for (char c : rule.right) {
                    parserStack.pop();
                }
                parserStack.push(rule.left);
                cout << "Reduce by " << rule.left << "->" << rule.right << endl;
                reduced = true;
                break;
            }
        }
        
        if (!reduced) {
            if (ip < buffer.length()) {
                // Perform shift
                parserStack.push(buffer[ip]);
                cout << "Shift " << buffer[ip] << endl;
                ip++;
            } else if (parserStack.top() == 'E' && buffer[ip] == '$') {
                cout << "Accept" << endl;
                break;
            } else {
                cout << "Error" << endl;
                break;
            }
        }
    }
}

int main() {
    // Define grammar rules
    vector<Rule> rules = {
        {'E', "E+T"},
        {'E', "T"},
        {'T', "T*F"},
        {'T', "F"},
        {'F', "i"}
    };
    
    // Input string: id+id*id
    string input = "i+i*i"; // Using 'i' to represent 'id'
    
    cout << "Shift-Reduce Parsing for string: " << input << "\n\n";
    cout << "Grammar:\n";
    for (const auto& rule : rules) {
        cout << rule.left << " -> " << rule.right << endl;
    }
    cout << "\nParsing process:\n";
    
    shiftReduceParser(input, rules);
    
    return 0;
}