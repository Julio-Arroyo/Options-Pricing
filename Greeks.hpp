#ifndef Greeks_hpp
#define Greeks_hpp

#include "OptionData.hpp"
#include "European.hpp"

double delta(const OptionData& data);

double gamma(const OptionData& data);

double vega(const OptionData& data);

double theta(const OptionData& data);

#endif