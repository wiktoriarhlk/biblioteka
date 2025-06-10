#include "interpolation.h"

double lagrange_interpolation(const std::vector<double>& x, const std::vector<double>& y, double x_interp) {
    double result = 0.0;
    int n = x.size();

    for (int i = 0; i < n; ++i) {
        double term = y[i];
        for (int j = 0; j < n; ++j) {
            if (i != j)
                term *= (x_interp - x[j]) / (x[i] - x[j]);
        }
        result += term;
    }
    return result;
}
