#include "integration.h"
#include <cassert>
#include <cmath>
#include <iostream>

double quadratic(double x) {
    return x * x;
}

double linear(double x) {
    return x;
}

int main() {
    // ∫_0^1 x dx = 0.5
    assert(std::abs(trapezoidal_rule(linear, 0, 1, 1000) - 0.5) < 1e-4);
    assert(std::abs(simpsons_rule(linear, 0, 1, 1000) - 0.5) < 1e-6);
    assert(std::abs(gauss_legendre(linear, 0, 1, 2) - 0.5) < 1e-6);
    assert(std::abs(gauss_legendre(linear, 0, 1, 3) - 0.5) < 1e-6);

    // ∫_0^1 x^2 dx = 1/3
    assert(std::abs(trapezoidal_rule(quadratic, 0, 1, 1000) - 1.0 / 3) < 1e-4);
    assert(std::abs(simpsons_rule(quadratic, 0, 1, 1000) - 1.0 / 3) < 1e-6);
    assert(std::abs(gauss_legendre(quadratic, 0, 1, 2) - 1.0 / 3) < 1e-6);
    assert(std::abs(gauss_legendre(quadratic, 0, 1, 3) - 1.0 / 3) < 1e-6);
    assert(std::abs(gauss_legendre(quadratic, 0, 1, 4) - 1.0 / 3) < 1e-6);
    assert(std::abs(gauss_legendre(quadratic, 0, 1, 5) - 1.0 / 3) < 1e-6);

    return 0;
}
