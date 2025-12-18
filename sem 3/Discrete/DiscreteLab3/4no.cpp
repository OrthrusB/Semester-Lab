#include <iostream>
using namespace std;


bool implies(bool p, bool q) {
    return !p || q; 
}

int main() {
    cout << "Truth Table for Validity Test of the Argument:" << endl;
    cout << "|  Go to Mall  |  Buy New Jeans  |  Buy a Shirt|  Conclusion |" << endl;

    for (int goToMall = 0; goToMall <= 1; goToMall++) {
        for (int buyNewJeans = 0; buyNewJeans <= 1; buyNewJeans++) {
            for (int buyAShirt = 0; buyAShirt <= 1; buyAShirt++) {
                bool premise1 = implies(goToMall, buyNewJeans); 
                bool premise2 = implies(buyNewJeans, buyAShirt); 
                bool conclusion = implies(goToMall, buyAShirt); 

                cout << "|      " << goToMall << "      |        " << buyNewJeans << "         |      " << buyAShirt << "      |      " << conclusion << "      |" << endl;
            }
        }
    }

    cout << "This is a Valid Argument! " << endl;

    return 0;
}
