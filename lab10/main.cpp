#include <iostream>
#include <iomanip>
#include "variant_utils.h"

int main() {
    
    int i1 = 42, i2 = 17;
    double d1 = 3.14, d2 = 2.718;

    std::cout << "Max: " << measurement::maxValue(i1, i2) << "\n";
    std::cout << "Min: " << measurement::minValue(i1, i2) << "\n";

    std::cout << "Clamp 50: " << measurement::clampValue(50, 10, 100) << "\n";

    int int_arr[] = {1, 2, 3, 4, 5};
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "Average int: " << measurement::average(int_arr, 5) << "\n";

    return 0;
}