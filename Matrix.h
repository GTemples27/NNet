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
        //Matrix(const Matrix& other);

        //Assignment
        //Matrix& operator=(const Matrix& other);

        //Arithmetic
        Matrix Add(const Matrix& other) const;
        Matrix Subtract(const Matrix& other) const;
        Matrix Multiply(int) const;
        Matrix Dot(const Matrix& other) const;

        // Mutators and Accessors
        int GetRows() const;
        int GetCols() const;
        float GetDataAt(int, int) const;
        void SetDataAt(int, int, float);

        void Print() const;

        // overloads
        friend bool operator==(const Matrix& A, const Matrix& B);
        friend ostream& operator <<(ostream&, Matrix&);

    private:
        int m_rows;
        int m_cols;
        vector< vector<float> > m_data;
};

#endif // MATRIX_H
