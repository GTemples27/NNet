#include "NNet.h"

NNet::NNet()
{
    //ctor
}

// Ex: NNet({3, 4, 5})
// this would make a nnet with 3 layers, each having 3, 4, and 5 perceptrons in each respective layer
// so m_numOfLayers = 3
//
//    THESE ARE THE PERCEPTRON VALUES, NOT WEIGHTS
//    NOTE: DOESN'T INCLUDE BIAS NODE, BUT IT SHOULD
//    m_layers = { {0.5, 0.5, 0.5, 0.0, 0.0},
//                 {0.5, 0.5, 0.5, 0.5, 0.0},
//                 {0.5, 0.5, 0.5, 0.5, 0.5} }
//
//    THESE ARE THE WEIGHTS
//    NOTE: ROWS ARE THE NUMBER OF OUTPUTS, COLS ARE THE NUMBER OF INPUTS
//          SO THE EXAMPLE NNET SHOULD BE OF SIZE 4x3 FOR I->H, AND 5x4 FOR H->O
//          ALSO, m_weights[0] IS A MATRIX THAT CORRESPONDS TO I->H1, m_weights[1] = H1->H2... m_weights[n] = H_n->O
//    m_weights[0] = { {1, 1, 1}, AND SO ON
//                     {1, 1, 1},
//                     {1, 1, 1},
//                     {1, 1, 1} }
NNet::NNet(vector<int> layers)
{
    m_numOfLayers = layers.size();

    // Weights are initially randomized; for testing, they'll all start at 0.5
    vector<float> weightVector;
    m_weights.clear();
    for (unsigned i = 0; i < m_layers; ++i)
    {
        weightVector.clear();
        for (unsigned j = 0; j < layers[i]; ++j)
        {
            weightVector.push_back(0.5f);
        }
        m_weights.push_back(weightVector);
    }
}
