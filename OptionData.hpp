#ifndef OptionData_hpp
#define OptionData_hpp

class OptionData
{
    public:
    double T;  // maturity
    double K;  // strike price
    double sig;  // volatility
    double r;  // risk-free interest rate
    double S;  // current stock price
    double b;  // cost of carry

    OptionData();
    OptionData(double S, double K, double T, double sig, double r);
    OptionData(const OptionData& src);
    ~OptionData();
    OptionData& operator = (const OptionData& src);
};

#endif