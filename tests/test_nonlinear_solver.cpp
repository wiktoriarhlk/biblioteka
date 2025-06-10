#include "nonlinear_solver.h"
#include <cassert>
#include <cmath>
#include <iostream>

double func(double x) {
    return x * x - 2;  
}

double dfunc(double x) {
    return 2 * x;
}

int main() {
    double root_newton = newton_method(func, dfunc, 1.0);
    double root_secant = secant_method(func, 1.0, 2.0);

    std::cout << "Newton: " << root_newton << std::endl;
    std::cout << "Secant: " << root_secant << std::endl;

    assert(std::abs(root_newton - std::sqrt(2)) < 1e-6);
    assert(std::abs(root_secant - std::sqrt(2)) < 1e-6);

    return 0;
}
