#pragma once
class Vector {
private:
    int mSize;
    int* mData;

public:
    Vector();                                // Default constructor
    Vector(int size, int val = 0);           // Parameterized constructor
    Vector(const Vector& original);          // Copy constructor
    ~Vector();                               // Destructor

    Vector& operator=(const Vector& other);  // Assignment operator

    int& operator()(int index) const;        // 1-based index access
    bool operator[](int index) const;        // Range checking

    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Vector operator*(int scalar) const;
    int operator*(const Vector& other) const; // Dot product

    Vector& operator++();                    // Prefix increment
    Vector operator++(int);                  // Postfix increment
    Vector& operator--();                    // Prefix decrement
    Vector operator--(int);                  // Postfix decrement
};

