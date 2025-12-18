#include <iostream>
using namespace std;

bool andOperator(bool p, bool q) {
    return p && q;
}

bool orOperator(bool p, bool q) {
    return p || q;
}

bool notOperator(bool p) {
    return !p;
}

int main() {
    cout << "Truth Table for Proposition A (p ᴧ ¬q ᴠ r) → (¬p ᴠ r)" << std::endl;
    cout << "|  p  |  q  |  r  |  Result  |" << std::endl;
    
    for (int p = 0; p <= 1; p++) {
        for (int q = 0; q <= 1; q++) {
            for (int r = 0; r <= 1; r++) {
                bool propA = orOperator(andOperator(p, notOperator(q)), r);
                bool result = orOperator(notOperator(p), r);
                cout << "|  " << p << "  |  " << q << "  |  " << r << "  |     " << propA << "     |" << std::endl;
            }
        }
    }

    cout << "\nTruth Table for Proposition B (p ᴧ ¬q ᴠ r) ↔ (¬p ᴠ r)" << std::endl;
    cout << "|  p  |  q  |  r  |  Result  |" << std::endl;
    
    for (int p = 0; p <= 1; p++) {
        for (int q = 0; q <= 1; q++) {
            for (int r = 0; r <= 1; r++) {
                bool propB = (andOperator(p, notOperator(q)) == orOperator(notOperator(p), r));
                cout << "|  " << p << "  |  " << q << "  |  " << r << "  |     " << propB << "     |" << std::endl;
            }
        }
    }

    return 0;
}
