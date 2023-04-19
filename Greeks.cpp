// Option sensitivities, aka the Greeks
#include <iostream>
#include "Greeks.hpp"

double delta(const OptionData& data)
{
    double discount = std::exp((data.b-data.r) * data.T);
    double term = boost::math::cdf(NormalDist, getD1(data));
    return discount * term;
}

double gamma(const OptionData& data)
{
    double num = boost::math::pdf(NormalDist, getD1(data)) * std::exp((data.b-data.r)*data.T);
    double den = data.S * data.sig * std::sqrt(data.T);
    return num / den;
}

double vega(const OptionData& data)
{
    return data.S * std::sqrt(data.T) * boost::math::pdf(NormalDist, getD1(data));
}

double theta(const OptionData& data)
{
    double N_d2 = boost::math::cdf(NormalDist, getD2(data));
    double first_term = data.S * data.sig * boost::math::pdf(NormalDist, getD1(data));
    double second_term = (data.b-data.r) * data.S * std::exp((data.b-data.r)*data.T) * N_d2;
    double third_term = data.r * data.K * N_d2;
    return -(first_term + second_term + third_term);
}