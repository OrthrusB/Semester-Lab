//validity wala
#include <iostream>
using namespace std;


bool implies(bool p, bool q) {
    return !p || q; 
}

int main() {
cout << "Truth Table for Validity Test of the Argument:" << endl;
    cout << "|  Hound Dog  |  Howl at the Moon  |  Conclusion  |" << endl;

    for (int houndDog = 0; houndDog <= 1; houndDog++) {
        for (int howlAtMoon = 0; howlAtMoon <= 1; howlAtMoon++) {
            bool premise1 = implies(houndDog, howlAtMoon); 
            bool premise2 = !howlAtMoon; 
            bool conclusion = !houndDog; 

            cout << "|      " << houndDog << "      |         " << howlAtMoon << "          |       " << conclusion << "      |" << std::endl;
        }
    }

    cout << "This is valid!." <<endl;

    return 0;
}
