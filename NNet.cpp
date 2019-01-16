#include "NNet.h"
#include <cmath>
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
//    m_layers = { {0.5, 0.5, 0.5} ,
//                 {0.5, 0.5, 0.5, 0.5},
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
NNet::NNet(const vector<int>& layers)
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
        weightMatrixData.clear();
        for (unsigned j = 0; j < layers[i + 1]; ++j)
        {
            weightVector.clear();
            for (unsigned k = 0; k < layers[i]; ++k)
            {
                // rand from -1 to 1 with step 0.1
                float init = ((float)(rand() % 21) - 10) / 10;
                weightVector.push_back(init);
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
        for (unsigned j = 0; j < layers[i]; ++j)
        {
            // These are initialized as 1s, but feed forward will override them with proper values
            layerVector.clear();
            layerVector.push_back(1);
            layerMatrixData.push_back(layerVector);
        }
        Matrix layerMatrix(layerMatrixData);
        layerMatrixData.clear();
        m_layers.push_back(layerMatrix);
    }

    cout << "weights\n--------------------------\n";
    for (unsigned i = 0; i < m_weights.size(); ++i)
        cout << m_weights[i] << "--------------------\n";
    cout << "layers\n--------------------------\n";
    for (unsigned i = 0; i < m_layers.size(); ++i)
        cout << m_layers[i] << "--------------------\n";
}

// Directly alters the net, doesn't return anything
void NNet::FeedForward()
{
    Matrix outputMatrix;
    for(unsigned i = 0; i < m_numOfLayers - 1; ++i)
    {
        outputMatrix = m_weights[i].Dot(m_layers[i]);
        for (unsigned j = 0; j < outputMatrix.GetRows(); ++j)
        {
            m_layers[i + 1].SetDataAt(j, 0, Activate(outputMatrix.GetDataAt(j, 0)));
        }
    }
}

// Display the net's data; mainly for testing
void NNet::Display()
{
    cout << "LAYERS:\n";
    for (unsigned i = 0; i < m_layers.size(); ++i)
        cout << "Layer " << i << "\n" << m_layers[i];

    cout << "\n\nWEIGHTS:\n";
    for (unsigned i = 0; i < m_weights.size(); ++i)
        cout << "Weight Matrix " << i << "\n" << m_weights[i];
}


// Returns the value of an activation function
float NNet::Activate(float x)
{
   float output = x / (1 + abs(x));
   return output;
}
