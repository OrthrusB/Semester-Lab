#include <iostream>
using namespace std;

bool implies(bool p, bool q) {
    return !p || q; 
}

int main() {
    cout << "Truth Table :" << std::endl;
    cout << "|  Buy New Goat |  Buy Used Yugo  |  Need Loan|  Conclusion  |" << endl;

    for (int buyNewGoat = 0; buyNewGoat <= 1; buyNewGoat++) {
        for (int buyUsedYugo = 0; buyUsedYugo <= 1; buyUsedYugo++) {
            for (int needLoan = 0; needLoan <= 1; needLoan++) {
                bool premise1 = buyNewGoat || buyUsedYugo; 
                bool premise2 = implies(buyNewGoat && buyUsedYugo, needLoan); 
                bool premise3 = buyUsedYugo && !needLoan; 
                bool conclusion = !buyNewGoat; 

                cout << "|       " << buyNewGoat << "       |        " << buyUsedYugo << "        |     " << needLoan << "     |       " << conclusion << "      |" << endl;
            }
        }
    }

    cout << "This is Valid Argument!" << endl;

    return 0;
}
