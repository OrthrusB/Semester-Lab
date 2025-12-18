#include <iostream>
#include <string>

using namespace std;

bool isAccepted(string s) {
    int state = 0;
    for (char c : s) {
        if (state == 0 && c == '1') state = 1;
        else if (state == 1 && c == '0') state = 2;
        else if (state == 2 && c == '1') state = 3;
        else if (state == 3 && c == '0') state = 4;
        else return false;
    }
    return state == 4;
}

int main() {
    string input;
    cout << "Enter string: ";
    cin >> input;
    cout << (isAccepted(input) ? "ACCEPTED" : "REJECTED") << endl;
    return 0;
}
