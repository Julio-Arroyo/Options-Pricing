#include "European.hpp"

double getD1(const OptionData& data)
{
    double numerator = std::log(data.S / data.K) + (b + (data.sig*data.sig)/2)*data.T;
    double denominator = data.sig * std::sqrt(data.T);
    return numerator / denominator;
}

double getD2(const OptionData& data)
{
    return getD1(data) - data.sig*std::sqrt(T);
}

double priceOption(bool isCall, const OptionData& data)
{
    double d1 = getD1(data);
    double d2 = getD2(data);

    if (isCall) {
        // TODO: calculate CDF with boost
        return S*
    }
}
