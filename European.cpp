#include "European.hpp"

double getD1(const OptionData& data)
{
    double numerator = std::log(data.S / data.K) + (data.b + (data.sig*data.sig)/2)*data.T;
    double denominator = data.sig * std::sqrt(data.T);
    return numerator / denominator;
}

double getD2(const OptionData& data)
{
    return getD1(data) - data.sig*std::sqrt(data.T);
}

double priceOption(const bool isCall, const OptionData& data)
{
    double d1 = getD1(data);
    double d2 = getD2(data);

    if (isCall) {
        double N_d1 = boost::math::cdf(NormalDist, d1);
        double N_d2 = boost::math::cdf(NormalDist, d2);
        return data.S*N_d1 - data.K*std::exp(-data.r*data.T)*N_d2;
    } else {
        double N_neg_d1 = boost::math::cdf(NormalDist, -d1);
        double N_neg_d2 = boost::math::cdf(NormalDist, -d2);
        return data.K*std::exp(-data.r*data.T)*N_neg_d2 - data.S*N_neg_d1;
    }
}
