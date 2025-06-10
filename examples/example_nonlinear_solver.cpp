#include "nonlinear_solver.h"
#include <iostream>
#include <cmath>

int main() {
    auto f = [](double x) { return std::cos(x) - x; };
    auto df = [](double x) { return -std::sin(x) - 1; };

    double root = newton_method(f, df, 1.0);
    std::cout << "Pierwiastek rownania cos(x) = x: " << root << std::endl;

    double root2 = secant_method(f, 0.5, 1.0);
    std::cout << "Metoda siecznych: " << root2 << std::endl;

    return 0;
}
