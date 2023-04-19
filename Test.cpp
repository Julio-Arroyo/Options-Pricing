// g++ -std=c++14 -I /Users/jarroyo/boost_1_82_0 -o test Test.cpp European.cpp OptionData.cpp Greeks.cpp
#include "European.hpp"
#include "Greeks.hpp"
#include <iostream>
#include <vector>


struct Solution {
    double C;
    double P;
};

int main(int argc, char* argv[])
{
    OptionData batch1(60,
                      65,
                      0.25,
                      0.3,
                      0.08);
    OptionData batch2(100,
                      100,
                      1,
                      0.2,
                      0);
    OptionData batch3(5, 10, 1, 0.5, 0.12);
    OptionData batch4(100, 100, 30, 0.3, 0.08);
    std::vector<OptionData> batches{batch1, batch2, batch3, batch4};

    struct Solution sol1 = {2.13293,  5.84584};
    struct Solution sol2 = {7.96632,  7.96632};
    struct Solution sol3 = {0.204121, 4.0733};
    struct Solution sol4 = {92.1749,  1.24651};
    std::vector<struct Solution> solns{sol1, sol2, sol3, sol4};

    for (int i = 0; i < batches.size(); i++) {
        double C = priceOption(true, batches[i]);
        double P = priceOption(false, batches[i]);

        std::cout << "P -> Expected: " << P << " - " << solns[i].P << " Actual" << std::endl;
        std::cout << "C -> Expected: " << C << " - " << solns[i].C << " Actual" << std::endl << std::endl;
    }
    
    // Greeks tests
    OptionData greek1(105, 100, 0.5, 0.36, 0.1, 0.0);
    std::cout << "Expected delta call: " << 0.5946 << " vs Actual: " << delta(greek1) << std::endl;
}