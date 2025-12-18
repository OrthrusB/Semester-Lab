#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>

using namespace std;

class Grammar {
private:
    map<char, vector<string>> productions; // Non-terminal -> list of productions
    map<char, set<char>> first; // FIRST sets

    // Compute FIRST set for a non-terminal
    void computeFirst(char symbol) {
        if (!first[symbol].empty()) return; // Already computed

        for (const string& prod : productions[symbol]) {
            if (prod.empty()) continue;

            // If production starts with a terminal or epsilon
            if (!isupper(prod[0])) {
                first[symbol].insert(prod[0]);
            } else {
                // If it starts with a non-terminal
                computeFirst(prod[0]);
                for (char c : first[prod[0]]) {
                    if (c != '$') first[symbol].insert(c);
                }
                // If the non-terminal can derive epsilon, check next symbol
                if (first[prod[0]].count('$')) {
                    if (prod.length() > 1 && !isupper(prod[1])) {
                        first[symbol].insert(prod[1]);
                    }
                }
            }
        }
    }

public:
    void addProduction(char nonTerminal, string production) {
        productions[nonTerminal].push_back(production);
    }

    void computeAllFirst() {
        for (auto& pair : productions) {
            computeFirst(pair.first);
        }
    }

    void printFirstSets() {
        for (auto& pair : first) {
            cout << "FIRST(" << pair.first << ") = { ";
            for (char c : pair.second) {
                cout << c << " ";
            }
            cout << "}" << endl;
        }
    }
};

int main() {
    Grammar grammar;

    // Grammar: S → Aa, A → b | $
    grammar.addProduction('S', "Aa");
    grammar.addProduction('A', "b");
    grammar.addProduction('A', "$");

    grammar.computeAllFirst();
    cout << "FIRST sets for the grammar:" << endl;
    grammar.printFirstSets();

    return 0;
}