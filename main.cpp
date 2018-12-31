#include <iostream>
#include "Matrix.h"
using namespace std;

int main()
{

    vector<vector<float> > a{ {1, 2}, {3, 4} };
    Matrix A(a);
    vector<vector<float> > b{ {5, 6}, {7, 8} };
    Matrix B(b);

    A = A.Multiply(2);
    A = A.Add(B);

    Matrix C = A.Dot(B);
    C.Print();
}
