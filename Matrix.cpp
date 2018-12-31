#include "Matrix.h"

Matrix::Matrix()
{
    // If default, the matrix will be a 1x1 matrix
    // with only a 0

    m_data.clear();
    vector< vector<float> > temp;
    temp.clear();
    vector<float> tempRow(1, 0);
    temp.push_back(tempRow);

    m_data = temp;
    m_rows = 1;
    m_cols = 1;
}

Matrix::Matrix(int rows, int cols)
{
    //Make sure m_data is empty
    m_data.clear();

    //this will be a vector of size cols, filled with 0s
    vector<float> rowTemp(cols, 0.0f);

    // at the end of this loop, m_data will be a 2D array
    // that has the specified number of rows and cols
    // and be filled with 0s
    for (unsigned i = 0; i < rows; ++i)
        m_data.push_back(rowTemp);

    // finally update members
    m_rows = rows;
    m_cols = cols;
}

Matrix::Matrix(const vector< vector<float> >& data)
{
    //cannot be an empty array
    if (data.size() == 0)
        return;

    //if the array is jagged, iterate through and get the max column size
    //...not sure if this is needed, but might as well implement it
    int maxCols = 0;
    for (unsigned i = 0; i < data.size(); ++i)
    {
        if (data[i].size() > maxCols)
            maxCols = data[i].size();
    }

    //set data members
    m_data = data;
    m_rows = m_data.size();
    m_cols = m_data[0].size();
}

/*
Matrix::Matrix(const Matrix& other)
{
    //copy ctor
}

Matrix& Matrix::operator=(const Matrix& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
*/

// accessors
int Matrix::GetRows() {return m_rows;}
int Matrix::GetCols() {return m_cols;}
float Matrix::GetDataAt(int row, int col){return m_data[row][col];}
void Matrix::SetDataAt(int row, int col, float data){m_data[row][col] = data;}

//Arithmetic
Matrix Matrix::Add(Matrix& other)
{
    // must be equally sized matrices
    if (this->GetCols() != other.GetCols() || this->GetRows() != other.GetCols())
        throw;

    int rows = this->GetRows();
    int cols = this->GetCols();

    Matrix result(rows, cols);
    for(unsigned i = 0; i < rows; ++i)
    {
        for (unsigned j = 0; j < cols; ++j)
        {
            float a = this->GetDataAt(i, j);
            float b = other.GetDataAt(i, j);
            result.SetDataAt(i, j, a + b);
        }
    }

    return result;
}

Matrix Matrix::Subtract(Matrix& other)
{
    Matrix sub;
    sub = other.Multiply(-1);
    return this->Add(sub);
}

//this returns a new matrix, doesn't modify the current one
Matrix Matrix::Multiply(int scalar)
{
    int rows = this->GetRows();
    int cols = this->GetCols();

    Matrix result(rows, cols);
    for(unsigned i = 0; i < rows; ++i)
    {
        for (unsigned j = 0; j < cols; ++j)
        {
            float a = this->GetDataAt(i, j);
            result.SetDataAt(i, j, a * scalar);
        }
    }

    return result;
}

// FIGURE OUT EXIT CONDITIONS
Matrix Matrix::Dot(Matrix& other)
{
    // Must multiply a mxn by a nxp matrix
    if (this->GetCols() != other.GetRows())
        return;

    int rows = this->GetRows();
    int cols = other.GetCols();

    //n will be used to get the cells' values
    int n = this->GetCols();

    Matrix result(rows, cols);

    for(unsigned i = 0; i < rows; ++i)
    {
        for (unsigned j = 0; j < cols; ++j)
        {
            float sum = 0;
            for (unsigned q = 0; q < n; ++q)
            {
                float a = this->GetDataAt(i, q);
                float b = other.GetDataAt(q, j);
                sum += a * b;
            }
            result.SetDataAt(i, j, sum);
        }
    }

    return result;
}

void Matrix::Print()
{
    for (unsigned i = 0; i < m_rows; ++i)
    {
        for (unsigned j = 0; j < m_cols; ++j)
            cout << m_data[i][j] << " ";
        cout << "\n";
    }
}
