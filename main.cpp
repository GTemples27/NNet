#include <iostream>
#include "Matrix.h"
#include "NNet.h"
#include <random>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    NNet Net({3, 2, 1});
    Net.FeedForward();
    Net.Display();
}
