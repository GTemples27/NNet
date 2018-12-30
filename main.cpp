#include <iostream>
#include "Matrix.h"
using namespace std;

int main()
{

    vector< vector<float> > a(2, vector<float>(2, 3));
    Matrix A(a);
    vector< vector<float> > b(2, vector<float>(2, 5));
    Matrix B(b);

    Matrix C = A.Add(B);
    C.Print();
}
