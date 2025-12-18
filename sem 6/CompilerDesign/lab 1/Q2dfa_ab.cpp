#include <iostream>
#include <string>

using namespace std;

bool isAccepted(string s) {
    if (s.empty()) return false;
    int state = (s[0] == 'a') ? 1 : 0;
    for (int i = 1; i < s.length(); i++) {
        if (state == 0) return false; // Didn't start with 'a'
        state = (s[i] == 'b') ? 2 : 1; // 2 if ends with 'b', 1 otherwise
    }
    return state == 2;
}

int main() {
    string input;
    cout << "Enter string: ";
    cin >> input;
    cout << (isAccepted(input) ? "ACCEPTED" : "REJECTED") << endl;
    return 0;
}