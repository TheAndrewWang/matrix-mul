#include <gtest/gtest.h>
#include <Eigen/Dense>
#include "matrixm.h"

using Eigen::MatrixXd;

TEST(MatrixMultiplicationTest, KnownProduct) {
    MatrixXd A(2, 3);
    A << 1, 2, 3,
         4, 5, 6;

    MatrixXd B(3, 2);
    B << 7, 8,
         9, 10,
         11, 12;

    MatrixXd expected(2, 2);
    expected << 58, 64,
                139, 154;

    EXPECT_TRUE(matrixm(A, B).isApprox(expected));
}

TEST(MatrixMultiplicationTest, IdentityIsNoOp) {
    MatrixXd A(2, 2);
    A << 1, 2,
         3, 4;
    MatrixXd I = MatrixXd::Identity(2, 2);

    EXPECT_TRUE(matrixm(A, I).isApprox(A));
    EXPECT_TRUE(matrixm(I, A).isApprox(A));
}

TEST(MatrixMultiplicationTest, MultiplyByZeroMatrix) {
    MatrixXd A(2, 2);
    A << 1, 2,
         3, 4;
    MatrixXd Zero = MatrixXd::Zero(2, 2);

    EXPECT_TRUE(matrixm(A, Zero).isApprox(Zero));
}

TEST(MatrixMultiplicationTest, ResultDimensionsMatchOperands) {
    MatrixXd A = MatrixXd::Random(4, 3);
    MatrixXd B = MatrixXd::Random(3, 5);

    MatrixXd result = matrixm(A, B);

    EXPECT_EQ(result.rows(), 4);
    EXPECT_EQ(result.cols(), 5);
}

TEST(MatrixMultiplicationTest, SingleElementMatrices) {
    MatrixXd A(1, 1);
    A << 5;
    MatrixXd B(1, 1);
    B << 6;

    EXPECT_DOUBLE_EQ(matrixm(A, B)(0, 0), 30.0);
}

TEST(MatrixMultiplicationTest, NotCommutativeInGeneral) {
    MatrixXd A(2, 2);
    A << 1, 2,
         3, 4;
    MatrixXd B(2, 2);
    B << 5, 6,
         7, 8;

    EXPECT_FALSE(matrixm(A, B).isApprox(matrixm(B, A)));
}

TEST(MatrixMultiplicationTest, AssociativeProperty) {
    MatrixXd A = MatrixXd::Random(3, 3);
    MatrixXd B = MatrixXd::Random(3, 3);
    MatrixXd C = MatrixXd::Random(3, 3);

    MatrixXd left = matrixm(matrixm(A, B), C);
    MatrixXd right = matrixm(A, matrixm(B, C));

    EXPECT_TRUE(left.isApprox(right));
}
