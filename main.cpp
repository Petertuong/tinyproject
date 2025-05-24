#include "classes.h"
#include <iostream>

//I asked AI to create test cases for the each class
// and it generated the following code. I will run this code to test.
#include <iostream>
#include <cassert>
#include "classes.h"

void test_default_constructor() {
    Matrix m;
    assert(m.getRows() == 0);
    assert(m.getCols() == 0);
}

void test_parameterized_constructor() {
    Matrix m(3, 4);
    assert(m.getRows() == 3);
    assert(m.getCols() == 4);
}

void test_copy_constructor() {
    Matrix m1(2, 2);
    Matrix m2(m1);
    assert(m2.getRows() == 2);
    assert(m2.getCols() == 2);
}

void test_operator_access() {
    Matrix m(2, 2);
    // Suppose mData is initialized to 0
    assert(m(1, 1) == 0);
}

void test_addition() {
    Matrix m1(2, 2), m2(2, 2);
    Matrix result = m1 + m2;
    assert(result.getRows() == 2 && result.getCols() == 2);
}

void test_subtraction() {
    Matrix m1(2, 2), m2(2, 2);
    Matrix result = m1 - m2;
    assert(result.getRows() == 2);
}

void test_matrix_multiplication() {
    Matrix m1(2, 3), m2(3, 2);
    Matrix result = m1 * m2;
    assert(result.getRows() == 2);
    assert(result.getCols() == 2);
}

void test_scalar_multiplication() {
    Matrix m(2, 2);
    Matrix result = m * 2;
    assert(result.getRows() == 2);
    assert(result.getCols() == 2);
}

void test_prefix_increment() {
    Matrix m(2, 2);
    Matrix& r = ++m;
    assert(&r == &m);
}

void test_postfix_increment() {
    Matrix m(2, 2);
    Matrix r = m++;
    assert(r.getRows() == 2);
}

void test_prefix_decrement() {
    Matrix m(2, 2);
    Matrix& r = --m;
    assert(&r == &m);
}

void test_postfix_decrement() {
    Matrix m(2, 2);
    Matrix r = m--;
    assert(r.getRows() == 2);
}

void test_determinant() {
    Matrix m(2, 2);
    double d = m.det();
    // Replace with correct expected value
    std::cout << "Det: " << d << '\n';
}

void test_inverse() {
    Matrix m(2, 2);
    Matrix inv = m.inv();
    assert(inv.getRows() == 2);
}

void test_pseudo_inverse() {
    Matrix m(2, 3);
    Matrix pinv = m.pseudo_inv();
    assert(pinv.getRows() == 3);
}

void test_transpose() {
    Matrix m(2, 3);
    Matrix t = m.transpose();
    assert(t.getRows() == 3 && t.getCols() == 2);
}

void test_get_minor() {
    Matrix m(3, 3);
    Matrix minor = m.getMinor(1, 1);
    assert(minor.getRows() == 2);
}




int main() {
    // Test 1: Default constructor
    Vector v1;
   
    // Test 2: Parameterized constructor
    Vector v2(5, 10); // size=5, all elements=10
    std::cout << "\nVector v2 (size=5, filled with 10): ";
    for (int i = 1; i <= 5; ++i) {
        std::cout << v2(i) << " "; // Using operator() (1-based indexing)
    }

    // Test 3: Copy constructor
    Vector v3 = v2;
    std::cout << "\n\nCopied Vector v3 (from v2): ";
    for (int i = 1; i <= 5; ++i) {
        std::cout << v3[i-1] << " "; // Using operator[] (0-based indexing)
    }

    // Test 4: Assignment operator
    Vector v4;
    v4 = v3;
    std::cout << "\n\nAssigned Vector v4 (from v3): ";
    for (int i = 1; i <= 5; ++i) {
        std::cout << v4(i) << " ";
    }

    // Test 5: Vector addition
    Vector v5(5, 3);
    Vector v6 = v2 + v5; // v2=[10,10,10,10,10], v5=[3,3,3,3,3]
    std::cout << "\n\nVector Addition (v2 + v5): ";
    for (int i = 1; i <= 5; ++i) {
        std::cout << v6(i) << " "; // Should print 13 13 13 13 13
    }

    // Test 6: Vector subtraction
    Vector v7 = v6 - v5;
    std::cout << "\n\nVector Subtraction (v6 - v5): ";
    for (int i = 1; i <= 5; ++i) {
        std::cout << v7(i) << " "; // Should print 10 10 10 10 10
    }

    // Test 7: Scalar multiplication
    Vector v8 = v7 * 2; // [10,10,10,10,10] * 2
    std::cout << "\n\nScalar Multiplication (v7 * 2): ";
    for (int i = 1; i <= 5; ++i) {
        std::cout << v8(i) << " "; // Should print 20 20 20 20 20
    }

    // Test 8: Dot product
    int dot = v8 * v5; // [20,20,20,20,20] · [3,3,3,3,3]
    std::cout << "\n\nDot Product (v8 · v5): " << dot << std::endl; // Should print 300

    // Test 9: Increment/Decrement operators
    std::cout << "\nPrefix Increment (++v8): ";
    ++v8; // [21,21,21,21,21]
    for (int i = 1; i <= 5; ++i) {
        std::cout << v8(i) << " ";
    }

    std::cout << "\nPostfix Decrement (v8--): ";
    Vector v9 = v8--; // v9=[21,...], v8=[20,...]
    for (int i = 1; i <= 5; ++i) {
        std::cout << v9(i) << " ";
    }

    // Test 10: Bounds checking
    std::cout << "\n\nBounds Checking (v8(0)): ";
    try {
        std::cout << v8(0); // Should throw an error (1-based indexing)
    } catch (...) {
        std::cout << "Caught out-of-bounds access!"; 
    }
    test_default_constructor();
    test_parameterized_constructor();
    test_copy_constructor();
    test_operator_access();
    test_addition();
    test_subtraction();
    test_matrix_multiplication();
    test_scalar_multiplication();
    test_prefix_increment();
    test_postfix_increment();
    test_prefix_decrement();
    test_postfix_decrement();
    test_determinant();
    test_inverse();
    test_pseudo_inverse();
    test_transpose();
    test_get_minor();
    std::cout << "All tests passed!\n";
    return 0;
}

