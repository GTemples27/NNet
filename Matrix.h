#ifndef MATRIX_H
#define MATRIX_H


class Matrix
{
    public:
        Matrix();
        virtual ~Matrix();
        Matrix(const Matrix& other);
        Matrix& operator=(const Matrix& other);

    protected:

    private:
};

#endif // MATRIX_H
