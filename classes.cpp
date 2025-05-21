#include "classes.h"
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