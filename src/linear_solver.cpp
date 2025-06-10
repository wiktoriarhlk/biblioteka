#include "linear_solver.h"
#include <stdexcept>

std::vector<double> gauss_elimination(std::vector<std::vector<double>> A, std::vector<double> b) {
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        // Partial pivoting
        int max_row = i;
        for (int k = i + 1; k < n; ++k)
            if (abs(A[k][i]) > abs(A[max_row][i]))
                max_row = k;

        std::swap(A[i], A[max_row]);
        std::swap(b[i], b[max_row]);

        if (A[i][i] == 0) throw std::runtime_error("Matrix is singular");

        for (int k = i + 1; k < n; ++k) {
            double factor = A[k][i] / A[i][i];
            for (int j = i; j < n; ++j) {
                A[k][j] -= factor * A[i][j];
            }
            b[k] -= factor * b[i];
        }
    }

    std::vector<double> x(n);
    for (int i = n - 1; i >= 0; --i) {
        x[i] = b[i];
        for (int j = i + 1; j < n; ++j)
            x[i] -= A[i][j] * x[j];
        x[i] /= A[i][i];
    }
    return x;
}
