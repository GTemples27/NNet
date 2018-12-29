#include "Perceptron.h"
#include <cstdlib>
Perceptron::Perceptron()
{
    //ctor
}

Perceptron::~Perceptron()
{
    //dtor
}

Perceptron::Perceptron(const Perceptron& other)
{
    //copy ctor
}

Perceptron& Perceptron::operator=(const Perceptron& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}


// inputs is an array of pair <float, float>
// first  = value of previous perceptron
// second = weight of connection
float Perceptron::FeedForward(float[] inputs, int numInputs)
{
    int value = 0;
    for (unsigned i = 0; i < numInputs; ++i)
    {
        value += inputs[i].first * inputs[i].second;
    }

    return Activate(value);
}

// returns the value of a sigmoidal function
// currently using "quick sigmoid" rather than a true sigmoid
float Perceptron::Activate(float sum)
{
    return sum / (1 + abs(sum));
}
