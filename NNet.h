#ifndef NNET_H
#define NNET_H

#include <iostream>
#include <vector>
using namespace std;
class NNet
{
    public:
        NNet();
        NNet(vector<int>);
        NNet(int[]);
    private:
         int m_layers;
         vector< vector<float> > m_weights;
};

#endif // NNET_H
