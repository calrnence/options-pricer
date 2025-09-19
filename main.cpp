#include "montecarlopricer.h"
#include <iostream>

using namespace std;

int main() {
    MonteCarloPricer monteCarlo(100, 100, 1, 0.05, 0.02); // S_0, K, T, r, sigma

    double price  = monteCarlo.simulate(1.0/12.0, 10000);

    cout << price << endl;
}
