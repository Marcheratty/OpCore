#include <iostream>
#include <cassert>
#include "Matrix.h"

void testMatrixInitialization() {
    Matrix<float, 2, 2> m1 = {1, 2, 3, 4};
    assert(m1(0, 0) == 1);
    assert(m1(0, 1) == 2);
    assert(m1(1, 0) == 3);
    assert(m1(1, 1) == 4);
    std::cout << "Matrix initialization test passed." << std::endl;
}

void testZeros() {
    Matrix<float, 2, 3> zeroMatrix = Matrix<float, 2, 3>::zeros();
    for (std::size_t i = 0; i < 2; ++i) {
        for (std::size_t j = 0; j < 3; ++j) {
            assert(zeroMatrix(i, j) == 0);
        }
    }
    std::cout << "Zeros matrix test passed." << std::endl;
}

void testEye() {
    Matrix<float, 3, 3> identityMatrix = Matrix<float, 3, 3>::eye();
    for (std::size_t i = 0; i < 3; ++i) {
        for (std::size_t j = 0; j < 3; ++j) {
            if (i == j) {
                assert(identityMatrix(i, j) == 1);
            } else {
                assert(identityMatrix(i, j) == 0);
            }
        }
    }
    std::cout << "Identity matrix test passed." << std::endl;
}

void testMatrixAddition() {
    Matrix<float, 2, 2> m1 = {1, 2, 3, 4};
    Matrix<float, 2, 2> m2 = {4, 3, 2, 1};
    Matrix<float, 2, 2> result = m1 + m2;
    assert(result(0, 0) == 5);
    assert(result(0, 1) == 5);
    assert(result(1, 0) == 5);
    assert(result(1, 1) == 5);
    std::cout << "Matrix addition test passed." << std::endl;
}

void testMatrixSubtraction() {
    Matrix<float, 2, 2> m1 = {5, 5, 5, 5};
    Matrix<float, 2, 2> m2 = {1, 2, 3, 4};
    Matrix<float, 2, 2> result = m1 - m2;
    assert(result(0, 0) == 4);
    assert(result(0, 1) == 3);
    assert(result(1, 0) == 2);
    assert(result(1, 1) == 1);
    std::cout << "Matrix subtraction test passed." << std::endl;
}

void testScalarMultiplication() {
    Matrix<float, 2, 2> m1 = {1, 2, 3, 4};
    Matrix<float, 2, 2> result = m1 * 2.0f;
    assert(result(0, 0) == 2);
    assert(result(0, 1) == 4);
    assert(result(1, 0) == 6);
    assert(result(1, 1) == 8);
    std::cout << "Scalar multiplication test passed." << std::endl;
}

void testHConcat() {
    Matrix<float, 2, 2> m1 = {1, 2, 3, 4};
    Matrix<float, 2, 3> m2 = {5, 6, 7, 8, 9, 10};
    Matrix<float, 2, 5> result = m1.hconcat(m2);
    assert(result(0, 0) == 1);
    assert(result(0, 1) == 2);
    assert(result(0, 2) == 5);
    assert(result(0, 3) == 6);
    assert(result(0, 4) == 7);
    std::cout << "Horizontal concatenation test passed." << std::endl;
}

void testVConcat() {
    Matrix<float, 2, 2> m1 = {1, 2, 3, 4};
    Matrix<float, 1, 2> m2 = {5, 6};
    Matrix<float, 3, 2> result = m1.vconcat(m2);
    assert(result(0, 0) == 1);
    assert(result(0, 1) == 2);
    assert(result(2, 0) == 5);
    assert(result(2, 1) == 6);
    std::cout << "Vertical concatenation test passed." << std::endl;
}

void testMatrixMultiplication() {
    Matrix<float, 2, 2> m1 = {1, 2, 3, 4};
    Matrix<float, 2, 2> m2 = {2, 0, 1, 2};
    Matrix<float, 2, 2> result = m1 * m2;
    assert(result(0, 0) == 4);
    assert(result(0, 1) == 4);
    assert(result(1, 0) == 10);
    assert(result(1, 1) == 8);
    std::cout << "Matrix multiplication test passed." << std::endl;
}

int main() {
    testMatrixInitialization();
    testZeros();
    testEye();
    testMatrixAddition();
    testMatrixSubtraction();
    testScalarMultiplication();
    testHConcat();
    testVConcat();
    testMatrixMultiplication();
    
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
