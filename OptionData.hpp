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
    OptionData(double S_, double K_, double T_, double sig_, double r_);
    OptionData(double S_, double K_, double T_, double sig_, double r_, double b_);
    OptionData(const OptionData& src);
    ~OptionData();
    OptionData& operator = (const OptionData& src);
};

#endif