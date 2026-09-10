#include <iostream>
#include <string>
#include <Eigen/Dense>
#include "matrixm.h"

using Eigen::MatrixXd;

MatrixXd matrixm(MatrixXd A, MatrixXd B) {
    return A * B;
}

#ifndef MATRIXM_UNIT_TEST

namespace {

MatrixXd readMatrix(const std::string& name, int rows, int cols) {
    MatrixXd M(rows, cols);
    std::cout << "Enter " << rows * cols << " values for matrix " << name
               << " (row-major order):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> M(i, j);
        }
    }
    return M;
}

}  // namespace

int main() {
    int rowsA, colsA, rowsB, colsB;

    std::cout << "Enter number of rows and columns for matrix A: ";
    std::cin >> rowsA >> colsA;
    MatrixXd A = readMatrix("A", rowsA, colsA);

    std::cout << "Enter number of rows and columns for matrix B: ";
    std::cin >> rowsB >> colsB;

    if (colsA != rowsB) {
        std::cerr << "Error: number of columns of A (" << colsA
                   << ") must equal number of rows of B (" << rowsB << ").\n";
        return 1;
    }

    MatrixXd B = readMatrix("B", rowsB, colsB);

    MatrixXd C = matrixm(A, B);
    std::cout << "A * B =\n" << C << "\n";

    return 0;
}

#endif  // MATRIXM_UNIT_TEST
