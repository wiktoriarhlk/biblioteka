#include "nonlinear_solver.h"
#include <cmath>
#include <stdexcept>

double newton_method(std::function<double(double)> f,
    std::function<double(double)> df,
    double x0, double epsilon, int max_iter) {
    for (int i = 0; i < max_iter; ++i) {
        double fx = f(x0);
        double dfx = df(x0);
        if (std::abs(dfx) < 1e-12) throw std::runtime_error("Pochodna bliska zeru.");
        double x1 = x0 - fx / dfx;
        if (std::abs(x1 - x0) < epsilon) return x1;
        x0 = x1;
    }
    throw std::runtime_error("Newton: Przekroczono maksymaln¹ liczbê iteracji.");
}

double secant_method(std::function<double(double)> f,
    double x0, double x1,
    double epsilon, int max_iter) {
    for (int i = 0; i < max_iter; ++i) {
        double f0 = f(x0);
        double f1 = f(x1);
        if (std::abs(f1 - f0) < 1e-12) throw std::runtime_error("Dzielenie przez zero w metodzie siecznych.");
        double x2 = x1 - f1 * (x1 - x0) / (f1 - f0);
        if (std::abs(x2 - x1) < epsilon) return x2;
        x0 = x1;
        x1 = x2;
    }
    throw std::runtime_error("Secant: Przekroczono maksymaln¹ liczbê iteracji.");
}
