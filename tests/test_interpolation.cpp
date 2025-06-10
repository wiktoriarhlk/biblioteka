#include "interpolation.h"
#include <cassert>

void test_lagrange() {
    std::vector<double> x = { 1, 2, 3 };
    std::vector<double> y = { 2, 4, 6 };
    double res = lagrange_interpolation(x, y, 2.5);
    assert(std::abs(res - 5.0) < 0.01);
}
int main() {
    test_lagrange();
    return 0;
}