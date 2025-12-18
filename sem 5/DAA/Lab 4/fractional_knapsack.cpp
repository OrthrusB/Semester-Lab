#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Item {
    int weight;
    int value;
    int index;
};

bool compare(Item a, Item b) {
    return (float)a.value / a.weight > (float)b.value / b.weight;
}

float fractionalKnapsack(int capacity, vector<Item> &items) {
    sort(items.begin(), items.end(), compare);

//    cout << "\nSorted Items (by Profit):\n";
//    cout << "--------------------------------------\n";
//    cout << setw(10) << "Item no." << setw(10) << "Weight" << setw(10) << "Value" << setw(15) << "Value/Weight\n";
//    cout << "--------------------------------------\n";
//    for (int i = 0; i < items.size(); i++) {
//        cout << setw(10) << items[i].index
//             << setw(10) << items[i].weight 
//             << setw(10) << items[i].value 
//             << setw(15) << fixed << setprecision(2) << (float)items[i].value / items[i].weight << endl;
//    }
//    cout << "--------------------------------------\n";

    float totalValue = 0.0f;
    
//    cout << "\nSelected Items:\n";
//    cout << "--------------------------------------\n";
//    cout << setw(10) << "Item no." << setw(10) << "Taken" << setw(15) << "Total Value\n";
//    cout << "--------------------------------------\n";
    
    for (int i = 0; i < items.size(); i++) {
        if (capacity >= items[i].weight) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
//            cout << setw(10) << items[i].index << setw(10) << items[i].weight << setw(15) << totalValue << endl;
        } else {
            float fraction = (float)capacity / items[i].weight;
            totalValue += items[i].value * fraction;
//            cout << setw(10) << items[i].index << setw(10) << capacity << setw(15) << totalValue << endl;
            break;
        }
    }
    
//    cout << "--------------------------------------\n";

    return totalValue;
}

int main() {
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);
    
    for (int i = 0; i < n; i++) {
        cout << "Enter weight and value of item " << i + 1 << ": ";
        cin >> items[i].weight >> items[i].value;
        items[i].index = i + 1;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    float maxValue = fractionalKnapsack(capacity, items);
    cout << "Maximum value in Knapsack = " << fixed << setprecision(2) << maxValue << endl;

    return 0;
}

