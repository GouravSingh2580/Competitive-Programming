#pragma once
#include <stdlib.h>

#include <cmath>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

typedef double (*functioncall)(double args);

using std::tuple;
using std::vector;

class Matrix {
   private:
    unsigned rows;
    unsigned cols;
    vector<vector<double>> data;

   public:
    /**
    *   Create a Matrix and set an initial value to 
    *   every element in the matrix
    * 
    *  @param rows number of Rows
    *  @param cols number of Columns
    *  @param value An initial value to every element
    * 
    *  @returns Returns a matrix
    */
    Matrix(unsigned, unsigned, double);

    /**
    *   Create a Matrix
    * 
    *  @param rows number of Rows
    *  @param cols number of Columns
    * 
    *  @returns Returns a matrix
    */
    Matrix(unsigned, unsigned);

    /**
    *   Create a Matrix from a file
    * 
    *  @param filepath read a file and transform into a matrix
    * 
    *  @returns Returns a matrix
    */
    Matrix(const char *);

    /**
    *   Create a matrix from another matrix
    * 
    *  @param matrix an matrix to copy
    * 
    *  @returns Returns the copied matrix
    */
    Matrix(const Matrix &);

    /**
    *   Create a matrix from another matrix
    * 
    *  @param matrix an matrix to copy
    * 
    *  @returns Returns the copied matrix
    */
    Matrix(vector<double>);

    /**
    *   Create an empty matrix with no rows and no columns
    * 
    *  @returns Returns an empty matrix
    */
    Matrix();

    // Matrix Operations
    Matrix operator+(Matrix &);
    Matrix operator-(Matrix &);
    Matrix operator*(Matrix &);
    Matrix operator+=(Matrix &);
    Matrix operator-=(Matrix &);
    Matrix operator*=(Matrix &);
    Matrix transpose();
    Matrix hadamard(Matrix &);
    Matrix kronecker(Matrix &);
    Matrix horizontalConcatenation(Matrix &);

    // Scalar Operations
    Matrix operator+(double);
    Matrix operator-(double);
    Matrix operator*(double);
    Matrix operator/(double);
    Matrix operator+=(double);
    Matrix operator-=(double);
    Matrix operator*=(double);
    Matrix operator/=(double);

    // Aesthetic Methods
    double &operator()(const unsigned &, const unsigned &);
    void print() const;
    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);
    unsigned getRows() const;
    unsigned getCols() const;
    vector<double> toArray();

    // Power Iteration
    tuple<Matrix, double, int> powerIter(unsigned, double);

    // Deflation
    Matrix deflation(Matrix &, double &);

    //Randomize
    void randomize();

    //Activation Function
    Matrix sigmod();
    Matrix dSigmod();

    Matrix hyperbolicTangent();
    Matrix dHyperbolicTangent();

    // Map
    Matrix map(functioncall);
};