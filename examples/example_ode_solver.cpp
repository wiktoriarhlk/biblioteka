#include "ode_solver.h"
#include <iostream>
#include <cmath>

double derivative(double x, double y) {
    return x + y;
}

int main() {
    double x0 = 0.0, y0 = 1.0, h = 0.1;
    int steps = 10;

    auto euler = euler_solver(derivative, x0, y0, h, steps);
    auto heun = heun_solver(derivative, x0, y0, h, steps);
    auto midpoint = midpoint_solver(derivative, x0, y0, h, steps);
    auto rk = runge_kutta_solver(derivative, x0, y0, h, steps);

    std::cout << "Euler:       y(" << x0 + steps * h << ") = " << euler.back() << std::endl;
    std::cout << "Heun:       y(" << x0 + steps * h << ") = " << heun.back() << std::endl;
    std::cout << "Midpoint:   y(" << x0 + steps * h << ") = " << midpoint.back() << std::endl;
    std::cout << "Runge-Kutta: y(" << x0 + steps * h << ") = " << rk.back() << std::endl;

    return 0;
}
