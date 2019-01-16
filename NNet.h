#ifndef NNET_H
#define NNET_H

#include <iostream>
#include <vector>
#include "Matrix.h"

using namespace std;
class NNet
{
    public:
        NNet();
        NNet(vector<int>);
        FeedForward();
    private:
         int m_numOfLayers;
         Matrix m_weights;
         Matrix m_layers;
};

#endif // NNET_H
