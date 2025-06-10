#include "linear_solver.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<double>> A = {
        {3, 2, -4},
        {2, 3, 3},
        {5, -3, 1}
    };
    std::vector<double> b = { 3, 15, 14 };

    try {
        std::vector<double> solution = gauss_elimination(A, b);
        std::cout << "Solution of the system:\n";
        for (size_t i = 0; i < solution.size(); ++i)
            std::cout << "x" << i + 1 << " = " << solution[i] << "\n";
    }
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}