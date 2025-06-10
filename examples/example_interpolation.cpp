#include "interpolation.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<double> x_vals = { 0, 1, 2, 3 };
    std::vector<double> y_vals = { 1, 3, 2, 5 };

    double x_interp = 1.5;
    double y_interp = lagrange_interpolation(x_vals, y_vals, x_interp);

    std::cout << "Interpolated value at x = " << x_interp
        << " is y = " << y_interp << "\n";

    return 0;
}