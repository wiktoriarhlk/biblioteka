#include "approximation.h"
#include <numeric>

std::pair<double, double> least_squares_approximation(const std::vector<double>& x, const std::vector<double>& y) {
    int n = x.size();
    double sum_x = std::accumulate(x.begin(), x.end(), 0.0);
    double sum_y = std::accumulate(y.begin(), y.end(), 0.0);
    double sum_xy = 0.0, sum_x2 = 0.0;

    for (int i = 0; i < n; ++i) {
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
    }

    double a = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    double b = (sum_y - a * sum_x) / n;

    return { a, b }; // y = ax + b
}