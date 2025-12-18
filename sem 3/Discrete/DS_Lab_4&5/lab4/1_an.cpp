#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a;
    int n;
    
    cout << "Enter the base ie a: ";
    cin >> a;
    
    cout << "Enter the exponent ie n: ";
    cin >> n;
    
    double result = pow(a, n);
    
    cout << a << " raised power " << n << " is " << result << endl;
    
    return 0;
}
