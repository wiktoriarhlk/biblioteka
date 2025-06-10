#include "linear_solver.h"
#include <cassert>
#include <cmath>

void test_gauss_elimination() {
    std::vector<std::vector<double>> A = { {2, 1}, {5, 7} };
    std::vector<double> b = { 11, 13 };
    std::vector<double> x = gauss_elimination(A, b);
    assert(std::abs(x[0] - 7.1111) < 0.01);
    assert(std::abs(x[1] - -3.2222) < 0.01);
}
int main() {
    test_gauss_elimination();
    return 0;
}