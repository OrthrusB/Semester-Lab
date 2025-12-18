#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char destination, char auxiliary, int &steps);

int main() {
    int n;

    cout << "Enter the number of disks: ";
    cin >> n;

    if (n < 3) {
        cout << "You can't play with " << n << " disks." << endl;
        return 1;
    }

    cout << "The algorithm to solve the game is:" << endl;
    int steps = 0;
    towerOfHanoi(n, 'A', 'C', 'B', steps);
    cout << "Total steps required: " << steps << endl;

    return 0;
}

void towerOfHanoi(int n, char source, char destination, char auxiliary, int &steps) {
    if (n == 1) {
        cout << "Move the disk 1 from " << source << " to " << destination << endl;
        steps++;
        return;
    }
    
    towerOfHanoi(n - 1, source, auxiliary, destination, steps);
    cout << "Move the disk " << n << " from " << source << " to " << destination << endl;
    steps++;
    towerOfHanoi(n - 1, auxiliary, destination, source, steps);
}
