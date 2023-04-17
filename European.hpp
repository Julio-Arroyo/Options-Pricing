#ifndef European_hpp
#define European_hpp

#include <cmath>
#include "OptionData.hpp"

double PriceOption(const bool isCall, const OptionData& data);

#endif
