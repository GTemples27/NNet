#include <iostream>
#include "Matrix.h"
using namespace std;

int main()
{

    vector<vector<float> > a{ {1, 2}, {3, 4} };
    Matrix A(a);
    vector<vector<float> > b{ {1, 2}, {3, 4} };
    Matrix B(b);

    cout << (A == B) << endl;

    Matrix C = A.Dot(B);
    cout << C;
}
