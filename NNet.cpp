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

// ADD A BIAS NODE!
NNet::NNet(vector<int> layers)
{
    // Set numOfLayers
    m_numOfLayers = layers.size();

    // Set weight matrices
    // Weights are initially randomized; for testing, they'll all start at 0.5
    vector<float> weightVector;
    vector< vector<float> > weightMatrixData;
    m_weights.clear();
    for (unsigned i = 0; i < m_numOfLayers - 1; ++i)
    {
        weightVector.clear();
        for (unsigned j = 0; j < layers[i + 1]; ++j)
        {
            weightMatrixData.clear();
            for (unsigned k = 0; k < layers[i]; ++k)
            {
                // Change this to random weights later
                weightVector.push_back(0.5f);
            }
            weightMatrixData.push_back(weightVector);
        }
        Matrix weightMatrix(weightMatrixData);
        m_weights.push_back(weightMatrix);
    }

    // Set layer matrices
    vector<float> layerVector;
    // Note: This will always be a nx1 matrix that corresponds to the perceptron data in each layer
    vector< vector<float> > layerMatrixData;
    layerMatrixData.clear();
    for (unsigned i = 0; i < m_numOfLayers; ++i)
    {
        layerVector.clear();
        for (unsigned j = 0; j < layers[i]; ++j)
        {
            // Gonna initialize the data all as 1s... I think these should be random later
            layerVector.push_back(1);
        }
        layerMatrixData.push_back(layerVector);
        Matrix layerMatrix(layerMatrix);
        m_layers.push_back(layerMatrix);
    }
}

// Directly alters the net, doesn't return anything
void NNet::FeedForward()
{
    for(unsigned i = 0; i < m_numOfLayers - 1; ++i)
    {

    }
}

// Display the net's data; mainly for testing
void NNet::Display()
{

}
