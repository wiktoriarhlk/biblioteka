#include "ode_solver.h"
#include <iostream>
#include <cmath>
#include <cassert>

double derivative(double x, double y) {
    return y;  // rozwiązanie: y = e^x
}

int main() {
    double x0 = 0.0;
    double y0 = 1.0;
    double h = 0.1;
    int steps = 10;

    auto result = runge_kutta_solver(derivative, x0, y0, h, steps);
    double exact = std::exp(1.0);  // y(1) = e ≈ 2.718...

    assert(std::abs(result.back() - exact) < 0.01);

    return 0;
}
