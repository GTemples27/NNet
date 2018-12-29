#include "Perceptron.h"

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
