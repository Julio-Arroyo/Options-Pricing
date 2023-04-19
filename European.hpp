#ifndef European_hpp
#define European_hpp

#include <cmath>
#include <boost/math/distributions/normal.hpp>
#include "OptionData.hpp"


static boost::math::normal_distribution<> NormalDist;

double getD1(const OptionData& data);

double getD2(const OptionData& data);

double priceOption(const bool isCall, const OptionData& data);

#endif
