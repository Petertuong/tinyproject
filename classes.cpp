#include "classes.h"
#include <cassert>
#include <cmath>
#include <stdexcept>

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
int& Vector::operator()(int index) const {
    if(index > 0 && index <= mSize){
        return (mData[index-1]);
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
int Matrix::operator()(int i, int j) const{
    if(i == 0 || j == 0){
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


