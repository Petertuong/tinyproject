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


void testDefaultConstructor() {
    std::cout << "Test 1: Default constructor\n";
    Vector v1;
    std::cout << "Passed (no crash)\n";
}

void testParameterizedConstructor() {
    std::cout << "\nTest 2: Parameterized constructor\n";
    Vector v2(5, 10); // size=5, all elements=10
    std::cout << "Vector v2: ";
    for (int i = 1; i <= 5; ++i) {
        std::cout << v2(i) << " ";
    }
    std::cout << "\n";
}

void testCopyConstructor() {
    std::cout << "\nTest 3: Copy constructor\n";
    Vector v2(5, 10);
    Vector v3 = v2;
    std::cout << "Copied Vector v3: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << v3[i] << " ";
    }
    std::cout << "\n";
}

void testAssignmentOperator() {
    std::cout << "\nTest 4: Assignment operator\n";
    Vector v3(5, 10);
    Vector v4;
    v4 = v3;
    std::cout << "Assigned Vector v4: ";
    for (int i = 1; i <= 5; ++i) {
        std::cout << v4(i) << " ";
    }
    std::cout << "\n";
}

void testAddition() {
    std::cout << "\nTest 5: Vector addition\n";
    Vector v2(5, 10);
    Vector v5(5, 3);
    Vector v6 = v2 + v5;
    std::cout << "v2 + v5 = ";
    for (int i = 1; i <= 5; ++i) {
        std::cout << v6(i) << " ";
    }
    std::cout << "\n";
}

void testSubtraction() {
    std::cout << "\nTest 6: Vector subtraction\n";
    Vector v6(5, 13);
    Vector v5(5, 3);
    Vector v7 = v6 - v5;
    std::cout << "v6 - v5 = ";
    for (int i = 1; i <= 5; ++i) {
        std::cout << v7(i) << " ";
    }
    std::cout << "\n";
}

void testScalarMultiplication() {
    std::cout << "\nTest 7: Scalar multiplication\n";
    Vector v7(5, 10);
    Vector v8 = v7 * 2;
    std::cout << "v7 * 2 = ";
    for (int i = 1; i <= 5; ++i) {
        std::cout << v8(i) << " ";
    }
    std::cout << "\n";
}

void testDotProduct() {
    std::cout << "\nTest 8: Dot product\n";
    Vector v8(5, 20);
    Vector v5(5, 3);
    int dot = v8 * v5;
    std::cout << "v8 · v5 = " << dot << "\n";
}

void testIncrementDecrement() {
    std::cout << "\nTest 9: Increment / Decrement operators\n";
    Vector v8(5, 20);
    ++v8; // Prefix increment
    std::cout << "After ++v8: ";
    for (int i = 1; i <= 5; ++i) {
        std::cout << v8(i) << " ";
    }
    std::cout << "\n";
}

void testPostfixDecrement() {
    std::cout << "\nTest 10: Postfix Decrement\n";
    Vector v8(5, 21);       // [21, 21, 21, 21, 21]
    Vector v9 = v8--;       // v9 = [21, ...], v8 becomes [20, ...]
    std::cout << "v9 (copy before decrement): ";
    for (int i = 1; i <= 5; ++i) {
        std::cout << v9(i) << " ";
    }
    std::cout << "\n";
    std::cout << "v8 (after postfix decrement): ";
    for (int i = 1; i <= 5; ++i) {
        std::cout << v8(i) << " ";
    }
    std::cout << "\n";
}

void testBoundsChecking() {
    std::cout << "\nTest 11: Bounds Checking\n";
    Vector v8(5, 20);
    std::cout << "Trying v8(0): ";
    try {
        std::cout << v8(0); // Should throw exception (1-based index)
    } catch (const std::out_of_range& e) {
        std::cout << "Caught out-of-bounds access: " << e.what() << "\n";
    } catch (...) {
        std::cout << "Caught out-of-bounds access (unknown type)!\n";
    }
}

int main() {

    testDefaultConstructor();
    testParameterizedConstructor();
    testCopyConstructor();
    testAssignmentOperator();
    testAddition();
    testSubtraction();
    testScalarMultiplication();
    testDotProduct();
    testIncrementDecrement();
    testPostfixDecrement();
    testBoundsChecking();

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

