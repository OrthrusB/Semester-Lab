#include <iostream>
#include <cmath>

using namespace std;

double factorial(int n) {
    double fact = 1;
    for(int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

void mm1_queue(int lambda, int mu, int n) {
    double rho = lambda / (double)mu;              // Server utilization (traffic intensity)
    double Lq = pow(rho, 2) / (1 - rho);          // Average number of customers in queue
    double Wq = (1 / (double)(mu - lambda)) * (lambda / mu);  // Average time in queue
    double L = lambda / (double)(mu - lambda);    // Average number of customers in system
    double W = 1 / (double)(mu - lambda);         // Average time in system
    double P0 = 1 - rho;                          // Probability of zero customers in system
    double Pn = P0 * pow(rho, n);                 // Probability of n customers in system
    double Utilization = rho;                      // Server utilization

    cout << "Rho (Traffic Intensity) = " << rho << endl;
    cout << "Expected Number of Jobs in the Queue (Lq) = " << Lq << endl;
    cout << "Expected Time in the Queue (Wq) = " << Wq << endl;
    cout << "Expected Number of Jobs in the System (L) = " << L << endl;
    cout << "Expected Time in the System (W) = " << W << endl;
    cout << "Probability of Zero Jobs in the System (P0) = " << P0 << endl;
    cout << "Probability of " << n << " Jobs in the System (Pn) = " << Pn << endl;
    cout << "Utilization = " << Utilization << endl;
}

int main() {
    int lambda, mu, n;
    cout << "Enter the Arrival Rate: ";
    cin >> lambda;
    cout << "Enter the Service Rate: ";
    cin >> mu;
    cout << "Enter the number of jobs in the system (n): ";
    cin >> n;

    cout << endl;
    mm1_queue(lambda, mu, n);

    return 0;
}