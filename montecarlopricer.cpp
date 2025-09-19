#include "montecarlopricer.h"
#include <random>
#include <cmath>
#include <iostream>

using namespace std;

MonteCarloPricer::MonteCarloPricer() : S_0(100), K(100), T(1.0), r(0.05), sigma(0.2) {}

MonteCarloPricer::MonteCarloPricer(double S_0_, double K_, double T_, double r_, double sigma_) : S_0(S_0_), K(K_), T(T_), r(r_), sigma(sigma_) {} 

double MonteCarloPricer::simulate(double dt, int iterations) {
    double average = 0;

    int steps = (int) (T / dt);

    std::random_device seed;
    std::mt19937 rng(seed()); // Mersenne Twister generator
    std::normal_distribution<double> distribution(0.0, 1.0); // normal distribution

    for (int i = 0; i < iterations; ++i) {
        double S_t = this->S_0;
        for (int j = 0; j < steps; ++j) {
            double Z = distribution(rng);
            S_t = S_t * exp((this->r - 0.5 * pow(this->sigma, 2)) * dt  + this->sigma*sqrt(dt)*Z);
        }

        double payoff = max(S_t - this->K, (double) 0);

        average = average + payoff;
    }

    average =  average / iterations;

    double option_price = exp(-this->r * this->T) * average;

    return option_price;
}