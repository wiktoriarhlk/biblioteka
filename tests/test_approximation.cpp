#include "approximation.h"
#include <cassert>
#include <cmath>

void test_least_squares() {
    std::vector<double> x = { 1, 2, 3 };
    std::vector<double> y = { 2, 4, 6 };

    auto result = least_squares_approximation(x, y);
    double a = result.first;
    double b = result.second;

    assert(std::abs(a - 2.0) < 0.01);
    assert(std::abs(b - 0.0) < 0.01);
}

int main() {
    test_least_squares();
    return 0;
}