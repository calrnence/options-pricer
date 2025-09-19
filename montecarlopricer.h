#ifndef MONTECARLOPRICER_H
#define MONTECARLOPRICER_H

class MonteCarloPricer {
    private:
        double S_0; // stock price
        double K; // strike price
        double T; // time to maturity
        double r; // risk free interest rate
        double sigma; // volatility

    public:
        MonteCarloPricer();
        MonteCarloPricer(double S_0, double K, double T, double r, double sigma);

        double simulate(double dt, int interations);
};

#endif