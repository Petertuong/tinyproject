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

    int& operator()(int index);        // 1-based index access
    int operator()(int index) const;   // Const version for read-only access
    bool operator[](int index) const;        // Range checking
    int getSize() const;                       // Get size of the vector
    // Vector operations
    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Vector operator*(int scalar) const;
    int operator*(const Vector& other) const; // Dot product

    Vector& operator++();                    // Prefix increment
    Vector operator++(int);                  // Postfix increment
    Vector& operator--();                    // Prefix decrement
    Vector operator--(int);                  // Postfix decrement
};

class Matrix {
private:
    int mNumRows;
    int mNumCols;
    int** mData;
public:
    //Default constructor
    Matrix();
    //Paremetirized constructor
    Matrix(int numRows, int numCols);
    //Copy constructor
    Matrix(const Matrix& original);
    //Destructor
    ~Matrix();
    //getter
    int getRows() const;
    int getCols() const;
    //() overriden [data accessing]
    int& operator()(int i, int j);
    //Const version of () operator for read-only access
    int operator()(int i, int j) const;
    //addition
    Matrix operator+(const Matrix& other) const;
    //substraction
    Matrix operator-(const Matrix& other) const;
    //Matrix Multiplication 
    Matrix operator*(const Matrix& other) const;
    //Scalar multiplication
    Matrix operator*(int scalar) const;
    //Prefix increment
    Matrix& operator++();
    //Postfix increment
    Matrix operator++(int);
    //Prefix decrement
    Matrix& operator--();
    //Postfix decrement
    Matrix operator--(int);
    //Determinant
    double det() const;
    //Inverse
    Matrix inv() const;
    //Pseudo-inverse
    Matrix pseudo_inv() const;
    //Transpose
    Matrix transpose() const;
    //Define new matrix that excludes row i and column j
    Matrix getMinor(int row, int col) const;
};


class LinearSystem{
protected:
    int mSize;
    Matrix* mpA;
    Vector* mpb;

public: 
    LinearSystem(const Matrix& mMatrix, const Vector& mVector);
    virtual Vector solve() const;
};

class PosSymLinSystem:LinearSystem{
    PosSymLinSystem(const Matrix& A, const Vector& b);
    Vector solve() const override;
    bool isSymmetric();
};

class OverDeterminedLinSystem:LinearSystem{
    double mRegularizationParam; // Lambda for Tikhonov regularization
public:
    OverDeterminedLinSystem(Matrix& rA, Vector& rb, double lambda);
    Vector solve() const override;
    struct Solutionspace;
    double computeResidualNorm(const Vector& x) const;
    Vector solvePositiveDefinite(const Matrix& A, const Vector& b) const;
};

