#include "classes.h"
#include <cassert>
#include <cmath>
#include <stdexcept>
#include <iostream>


//default constructor
Vector::Vector() : mSize(0), mData(nullptr) {}
//Parameterized constructor
Vector::Vector(int size, int val){ //val: initial value, default is 0
    mSize = size;
    mData = new int[mSize];
    for(int i = 0; i < mSize; ++i){
        mData[i] = val;
    }
}
//Copy constructor
Vector::Vector(const Vector& original){
    mSize = original.mSize;
    mData = new int[mSize];
    for(int i = 0; i < mSize; ++i){
        mData[i] = original.mData[i];
    }
}
//Destructor
Vector::~Vector() {delete [] mData;}
//Assignement 
Vector& Vector::operator=(const Vector& other){
    if(this != &other){
        delete [] mData; 
        mSize = other.mSize;
        mData = new int[mSize];
        for(int i = 0; i < mSize; ++i){
            mData[i] = other.mData[i];
        }
    }
    return *this;
}
//accessing vector, 1-Based indexing
int& Vector::operator()(int index) {
    if(index > 0 && index <= mSize){
        return (mData[index-1]);
    }
    throw std::out_of_range("Vector index out of bounds");
}

// Const version for read-only access
int Vector::operator()(int index) const {
    if(index > 0 && index <= mSize){
        return mData[index-1];
    }
    throw std::out_of_range("Vector index out of bounds");
}
//check within range
bool Vector::operator[](int index) const{
    if(index >= 0 && index < mSize){
        return true;
    }
    return false;
}

//get size
int Vector::getSize() const {
    return mSize;
}

//Addition
Vector Vector::operator+(const Vector& other) const{
    Vector temp(mSize);
    for(int i = 0; i < mSize; i++){
        temp.mData[i] = mData[i] + other.mData[i];
    }
    return temp;
}
//Substraction
Vector Vector::operator-(const Vector& other) const{
    Vector temp(mSize);
    for(int i = 0; i < mSize; i++){
        temp.mData[i] = mData[i] + other.mData[i];
    }
    return temp;
}
//Scalar multiplication
Vector Vector::operator*(int scalar) const{
    Vector temp(mSize);
    for(int i = 0; i < mSize; i++){
        temp.mData[i] = mData[i] * scalar;
    }

    return temp;
}    
// Dot product
int Vector::operator*(const Vector& other) const {
    int dot_product = 0;
    for(int i = 0; i < mSize; i++){
        dot_product += mData[i] * other.mData[i];
    }

    return dot_product;
}    
//Prefix increment
Vector& Vector::operator++(){
    for(int i = 0; i < mSize; i++){
        ++(mData[i]);
    }
    return *this;
}
//Postfix increment
Vector Vector::operator++(int){
    Vector temp(*this);
    for(int i = 0; i < mSize; i++){
        ++(*this);
    }
    return temp;
}
//Prefix decrement
Vector& Vector::operator--(){
    for(int i = 0; i < mSize; i++){
        --(mData[i]);
    }
    return *this;
}
//Postfix decrement
Vector Vector::operator--(int){ //dummy int to distinguish from prefix
    Vector temp(*this);
    for(int i = 0; i < mSize; i++){
        --(*this);
    }
    return temp;
}

//Default constructor
Matrix::Matrix() : mNumRows(0), mNumCols(0), mData(nullptr) {}
//Paremetirized Constructor
Matrix::Matrix(int numRows, int numCols){
    mNumRows = numRows;
    mNumCols = numCols;
    mData = new int*[mNumRows];
    for(int i = 0; i < mNumRows; i++){
        mData[i] = new int[mNumCols];
    }
    for(int i = 0; i < mNumRows; i++){
        for(int j = 0; j < mNumCols; j++){
            mData[i][j] = 0;
        }
    }
}
//Copy constructor
Matrix::Matrix(const Matrix& original){
    mNumCols = original.mNumCols;
    mNumRows = original.mNumRows;
    mData = new int*[mNumRows];
    for(int i = 0; i < mNumRows; i++){
        mData[i] = new int[mNumCols];
    }
    for(int i = 0; i < mNumRows; i++){
        for(int j = 0; j < mNumCols; j++){
            mData[i][j] = original.mData[i][j];
        }
    }
}
//Destructor
Matrix::~Matrix(){
    for(int i = 0; i < mNumRows; i++){
        delete [] mData[i];
    }
    delete [] mData;
}
//getter
int Matrix::getRows() const{
    return mNumRows;
}
int Matrix::getCols() const{
    return mNumCols;
}
//() overriden [accesing data]
int& Matrix::operator()(int i, int j) {
    if(i <= 0 || j <= 0){
        throw std::out_of_range("Matrix index out of bounds");
    }
    if(i > mNumRows || j > mNumCols){
        throw std::out_of_range("Vector index out of bounds");
    }
    return mData[i-1][j-1];
}

// Const version for read-only access
int Matrix::operator()(int i, int j) const {
    if(i <= 0 || j <= 0){
        throw std::out_of_range("Matrix index out of bounds");
    }
    if(i > mNumRows || j > mNumCols){
        throw std::out_of_range("Vector index out of bounds");
    }
    return mData[i-1][j-1];
}

//addition
Matrix Matrix::operator+(const Matrix& other) const{
    assert(mNumCols == other.mNumCols && "different column size");
    assert(mNumRows == other.mNumRows && "different row size");
    Matrix temp(*this);
    for(int i = 0; i < mNumRows; ++i){
        for(int j = 0; j < mNumCols; ++j){
            temp.mData[i][j] = mData[i][j] + other.mData[i][j];
        }
    }
    return temp;
}
//substraction
Matrix Matrix::operator-(const Matrix& other) const{
    assert(mNumCols == other.mNumCols && "different column size");
    assert(mNumRows == other.mNumRows && "different row size");
    Matrix temp(*this);
    for(int i = 0; i < mNumRows; ++i){
        for(int j = 0; j < mNumCols; ++j){
            temp.mData[i][j] = mData[i][j] - other.mData[i][j];
        }
    }
    return temp; 
}
//Multiplication 
Matrix Matrix::operator*(const Matrix& other) const{
    Matrix temp(mNumCols, other.mNumRows);
    for(int i = 0; i < mNumCols; ++i){
        for(int j = 0; j < other.mNumRows; ++j){
            temp.mData[i][j] += mData[j][i]*other.mData[i][j];
        }
    }
    return temp;
}
//Scalar multiplication
Matrix Matrix::operator*(int scalar) const{
    Matrix temp(mNumRows, mNumCols);
    for(int i = 0; i < mNumRows; ++i){
        for(int j = 0; j < mNumCols; ++j){
            temp.mData[i][j] = mData[i][j] * scalar;
        }
    }
    return temp;
}
//Prefix increment
Matrix& Matrix::operator++(){
    for(int i = 0; i < mNumRows; ++i){
        for(int j = 0; j < mNumCols; ++j){
            ++mData[i][j];
        }
    }
    return *this;
}
//Postfix increment
Matrix Matrix::operator++(int){
    Matrix temp(*this);
    for(int i = 0; i < mNumRows; ++i){
        for(int j = 0; j < mNumCols; ++j){
            ++mData[i][j];
        }
    }
    return temp;
}
//Prefix decrement
Matrix& Matrix::operator--(){
    for(int i = 0; i < mNumRows; ++i){
        for(int j = 0; j < mNumCols; ++j){
            --mData[i][j];
        }
    }
    return *this;
}
//Postfix decrement
Matrix Matrix::operator--(int){
    Matrix temp(*this);
    for(int i = 0; i < mNumRows; ++i){
        for(int j = 0; j < mNumCols; ++j){
            --mData[i][j];
        }
    }
    return temp;
}
//Define new matrix that excludes row i and column j
Matrix Matrix::getMinor(int row, int col) const {
    Matrix minor(mNumRows - 1, mNumCols - 1);
    for (int i = 0, mi = 0; i < mNumRows; ++i) {
        if (i == row) continue;
        for (int j = 0, mj = 0; j < mNumCols; ++j) {
            if (j == col) continue;
            minor.mData[mi][mj] = mData[i][j];
            ++mj;
        }
        ++mi;
    }
    return minor;
}
//Determinant
double Matrix::det() const{
    //Must square matrix
    assert(mNumCols == mNumRows && "Not square matrix");
    //base case for 1x1 matrix
    if(mNumRows == 1){
        return mData[0][0];
    }
    //base case for 2x2 matrix
    if(mNumRows == 2){
        return mData[0][0] * mData[1][1] - mData[0][1] * mData[1][0];
    }
    double det = 0.0;
    for(int j = 0; j < mNumCols; ++j){
        Matrix minor = getMinor(0, j); //exclude row 0 and column j
        det += pow(-1, j) * mData[0][j] * minor.det();
    }
    return det;
}
//Inverse
Matrix Matrix::inv() const{
    //Must square matrix
    assert(mNumCols == mNumRows && "Not square matrix");
    //Calculate determinant
    double determinant = det();
    if (determinant == 0) {
        throw std::runtime_error("Matrix is singular and cannot be inverted.");
    }
    Matrix adjoint(mNumRows, mNumCols);
    for (int i = 0; i < mNumRows; ++i) {
        for (int j = 0; j < mNumCols; ++j) {
            Matrix minor = getMinor(i, j);
            adjoint.mData[j][i] = pow(-1, i + j) * minor.det(); // Transpose the cofactor
        }
    }
    return adjoint * (1.0 / determinant); // Multiply by 1/determinant
}
//Transpose
Matrix Matrix::transpose() const{
    Matrix transposed(mNumCols, mNumRows);
    for(int i = 0; i < mNumRows; ++i){
        for(int j = 0; j < mNumCols; ++j){
            transposed.mData[j][i] = mData[i][j];
        }
    }
    return transposed;
}

//Pseudo-inverse
Matrix Matrix::pseudo_inv() const{
    Matrix At = this->transpose();
    Matrix result;

    if (mNumRows >= mNumCols) {
        // Tall matrix or square
        Matrix AtA = At * (*this); // A^T * A
        Matrix inv = AtA.inv(); // (A^T A)^-1
        result = inv * At; // (A^T A)^-1 * A^T
    } else {
        // Wide matrix
        Matrix AAt = (*this) * At; // A * A^T
        Matrix inv = AAt.inv(); // (A A^T)^-1
        result = At * inv; // A^T * (A A^T)^-1
    }

    return result;
}





LinearSystem::LinearSystem(const Matrix& mMatrix, const Vector& mVector){
    assert(mMatrix.getCols() == mMatrix.getRows() && "Not square matrix");
    mSize = mMatrix.getCols();
    mpA = new Matrix(mMatrix);
    mpb = new Vector(mVector);
}

Vector LinearSystem::solve() const{
    for(int i = 1; i <= mSize; ++i){
        for(int j = i + 1; j <= mSize; j++){
            int k = (*mpA)(i,i)/ (*mpA)(i,j);
            for(int l = i; l < mSize; l++){
                (*mpA)(l,i+1) = k*(*mpA)(l,i+1) - (*mpA)(l,i);
                (*mpb)(j+1) = k*(*mpb)(j+1) - (*mpb)(j);
            }

        }
        if((*mpA)(i,i) != 1){
            for(int m = i; m < mSize; ++m){
                (*mpA)(i,m) /= (*mpA)(i,i);
                (*mpb)(i) /= (*mpA)(i,i);
            }
        }
    }
    for(int j = mSize - 1; j >= 0; --j){
        for(int i = j; i < mSize; i++){
            if((*mpA)(i,j) != 0){
                (*mpb)(j) -= (*mpA)(i,j) * (*mpb)(i);
            }
        }
    }
    Vector result(mSize);
    for(int i = 0; i < mSize; ++i){
        result(i+1) = (*mpb)(i+1);
    }
    return result;
}



Vector PosSymLinSystem::solve() const {
    // Initialize solution vector (initial guess - zero vector)
    Vector x(mSize);
    for(int i = 1; i <= mSize; ++i) {
        x(i) = 0.0;
    }
    
    // Compute initial residual r = b - A*x (since x=0, r = b)
    Vector r(mSize);
    for(int i = 1; i <= mSize; ++i) {
        r(i) = (*mpb)(i);
    }
    
    // Initialize search direction p = r
    Vector p(mSize);
    for(int i = 1; i <= mSize; ++i) {
        p(i) = r(i);
    }
    
    // Compute initial residual squared norm
    double rsold = 0.0;
    for(int i = 1; i <= mSize; ++i) {
        rsold += r(i) * r(i);
    }
    
    // Tolerance for convergence
    double tolerance = 1e-10;
    int maxIterations = mSize; // Maximum iterations
    
    for(int iter = 0; iter < maxIterations; ++iter) {
        // Check convergence
        if(rsold < tolerance) {
            break;
        }
        
        // Compute Ap = A * p
        Vector Ap(mSize);
        for(int i = 1; i <= mSize; ++i) {
            Ap(i) = 0.0;
            for(int j = 1; j <= mSize; ++j) {
                Ap(i) += (*mpA)(i,j) * p(j);
            }
        }
        
        // Compute alpha = rsold / (p^T * Ap)
        double pAp = 0.0;
        for(int i = 1; i <= mSize; ++i) {
            pAp += p(i) * Ap(i);
        }
        double alpha = rsold / pAp;
        
        // Update solution: x = x + alpha * p
        for(int i = 1; i <= mSize; ++i) {
            x(i) += alpha * p(i);
        }
        
        // Update residual: r = r - alpha * Ap
        for(int i = 1; i <= mSize; ++i) {
            r(i) -= alpha * Ap(i);
        }
        
        // Compute new residual squared norm
        double rsnew = 0.0;
        for(int i = 1; i <= mSize; ++i) {
            rsnew += r(i) * r(i);
        }
        
        // Compute beta = rsnew / rsold
        double beta = rsnew / rsold;
        
        // Update search direction: p = r + beta * p
        for(int i = 1; i <= mSize; ++i) {
            p(i) = r(i) + beta * p(i);
        }
        
        // Update rsold for next iteration
        rsold = rsnew;
    }
    
    return x;
}

bool PosSymLinSystem::isSymmetric(){
    for(int i = 0; i < mSize-1; i++){
        for(int j = i+1; j < mSize; j++){
            if ((*mpA)(i,j) != (*mpA)(j,i)){
                return false;
            }
        }
    }
    return true;
}

// Class for Over-determined Systems (m > n, more equations than unknowns)


OverDeterminedLinSystem::OverDeterminedLinSystem(Matrix& rA, Vector& rb, double lambda = 0.0) 
        : LinearSystem(rA, rb), mRegularizationParam(lambda) {
        // Ensure A is over-determined (m > n)
        assert(rA.getRows() > rA.getRows() && "Matrix A must be over-determined (m > n)");
    }
    
    // Solve using Moore-Penrose pseudoinverse: x = (A^T A)^(-1) A^T b
Vector OverDeterminedLinSystem::solve() const {
        int m = mpA->getRows();    // Number of equations
        int n = mpA->getCols(); // Number of unknowns
        
        // Compute A^T A (n x n matrix)
        Matrix AtA(n, n);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                double sum = 0.0;
                for(int k = 1; k <= m; ++k) {
                    sum += (*mpA)(k,i) * (*mpA)(k,j);
                }
                AtA(i,j) = sum;
            }
        }
        
        // Add Tikhonov regularization: (A^T A + λI)
        if(mRegularizationParam > 0.0) {
            for(int i = 1; i <= n; ++i) {
                AtA(i,i) += mRegularizationParam;
            }
        }
        
        // Compute A^T b (n x 1 vector)
        Vector Atb(n);
        for(int i = 1; i <= n; ++i) {
            double sum = 0.0;
            for(int k = 1; k <= m; ++k) {
                sum += (*mpA)(k,i) * (*mpb)(k);
            }
            Atb(i) = sum;
        }
        
        // Solve (A^T A + λI) x = A^T b using Cholesky decomposition
        return solvePositiveDefinite(AtA, Atb);
    }
    
    // Compute residual norm ||Ax - b||
double OverDeterminedLinSystem::computeResidualNorm(const Vector& x) const {
        int m = mpA->getRows();
        double norm = 0.0;
        
        for(int i = 1; i <= m; ++i) {
            double residual = -(*mpb)(i);
            for(int j = 1; j <= mpA->getCols(); ++j) {
                residual += (*mpA)(i,j) * x(j);
            }
            norm += residual * residual;
        }
        return sqrt(norm);
    }

    // Solve positive definite system using Cholesky decomposition
Vector OverDeterminedLinSystem::solvePositiveDefinite(const Matrix& A, const Vector& b) const {
        int n = A.getRows();
        
        // Cholesky decomposition: A = L L^T
        Matrix L(n, n);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= i; ++j) {
                if(i == j) {
                    double sum = 0.0;
                    for(int k = 1; k < i; ++k) {
                        sum += L(i,k) * L(i,k);
                    }
                    L(i,i) = sqrt(A(i,i) - sum);
                } else {
                    double sum = 0.0;
                    for(int k = 1; k < j; ++k) {
                        sum += L(i,k) * L(j,k);
                    }
                    L(i,j) = (A(i,j) - sum) / L(j,j);
                }
            }
        }
        
        // Forward substitution: L y = b
        Vector y(n);
        for(int i = 1; i <= n; ++i) {
            double sum = 0.0;
            for(int j = 1; j < i; ++j) {
                sum += L(i,j) * y(j);
            }
            y(i) = (b(i) - sum) / L(i,i);
        }
        
        // Backward substitution: L^T x = y
        Vector x(n);
        for(int i = n; i >= 1; --i) {
            double sum = 0.0;
            for(int j = i + 1; j <= n; ++j) {
                sum += L(j,i) * x(j);
            }
            x(i) = (y(i) - sum) / L(i,i);
        }
        
        return x;
    }



