#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
using namespace std;

class Matrix
{
    public:
        //Default constructor
        Matrix();

        //Overloaded cons; pass in rows and cols
        Matrix(int, int);

        //Overloaded cons; pass in nested array as data
        Matrix(const vector< vector<float> > &);

        //Destructor
        //virtual ~Matrix();

        //Copy
        Matrix(const Matrix& other);

        //Assignment
        Matrix& operator=(const Matrix& other);

        //Arithmetic
        Matrix Add(Matrix& other);
        Matrix Subtract(const Matrix& other);
        Matrix Multiply(int);
        Matrix Dot(const Matrix& other);

        // Mutators and Accessors
        int GetRows();
        int GetCols();
        float GetDataAt(int, int);
        void SetDataAt(int, int, float);

        void Print();

    private:
        int m_rows;
        int m_cols;
        vector< vector<float> > m_data;
};

#endif // MATRIX_H
