#include "ode_solver.h"

std::vector<double> euler_solver(std::function<double(double, double)> f, double x0, double y0, double h, int steps) {
    std::vector<double> y_vals = { y0 };
    double x = x0, y = y0;
    for (int i = 0; i < steps; ++i) {
        y += h * f(x, y);
        x += h;
        y_vals.push_back(y);
    }
    return y_vals;
}

std::vector<double> heun_solver(std::function<double(double, double)> f, double x0, double y0, double h, int steps) {
    std::vector<double> y_vals = { y0 };
    double x = x0, y = y0;
    for (int i = 0; i < steps; ++i) {
        double k1 = f(x, y);
        double k2 = f(x + h, y + h * k1);
        y += h * 0.5 * (k1 + k2);
        x += h;
        y_vals.push_back(y);
    }
    return y_vals;
}

std::vector<double> midpoint_solver(std::function<double(double, double)> f, double x0, double y0, double h, int steps) {
    std::vector<double> y_vals = { y0 };
    double x = x0, y = y0;
    for (int i = 0; i < steps; ++i) {
        double k1 = f(x, y);
        double k2 = f(x + h / 2.0, y + h / 2.0 * k1);
        y += h * k2;
        x += h;
        y_vals.push_back(y);
    }
    return y_vals;
}

std::vector<double> runge_kutta_solver(std::function<double(double, double)> f, double x0, double y0, double h, int steps) {
    std::vector<double> y_vals = { y0 };
    double x = x0, y = y0;
    for (int i = 0; i < steps; ++i) {
        double k1 = f(x, y);
        double k2 = f(x + h / 2.0, y + h * k1 / 2.0);
        double k3 = f(x + h / 2.0, y + h * k2 / 2.0);
        double k4 = f(x + h, y + h * k3);
        y += (h / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        x += h;
        y_vals.push_back(y);
    }
    return y_vals;
}
