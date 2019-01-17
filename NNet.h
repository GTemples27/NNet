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
        NNet(const vector<int>&);
        void FeedForward();
        void Display();
        float Activate(float);
        float CalculateCost(float, float);
    private:
         int m_numOfLayers;
         vector<Matrix> m_weights;
         vector<Matrix> m_layers;
};

#endif // NNET_H
