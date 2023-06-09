#include "OptionData.hpp"

// Constructors & destructor
OptionData::OptionData()
{

}

OptionData::OptionData(double S_, double K_, double T_, double sig_, double r_)
{
    S = S_;
    K = K_;
    T = T_;
    sig = sig_;
    r = r_;
    b = r_;  // in the Black-Scholes model b=r
}

OptionData::OptionData(double S_, double K_, double T_, double sig_, double r_, double b_)
{
    S = S_;
    K = K_;
    T = T_;
    sig = sig_;
    r = r_;
    b = b_;
}

OptionData::OptionData(const OptionData& src)
{
    S = src.S;
    K = src.K;
    T = src.T;
    sig = src.sig;
    r = src.r;
    b = src.r;
}

OptionData::~OptionData()
{
    
}

// Operators
OptionData& OptionData::operator = (const OptionData& src)
{
    S = src.S;
    K = src.K;
    T = src.T;
    sig = src.sig;
    r = src.r;
    b = src.r;

    return *this;
}