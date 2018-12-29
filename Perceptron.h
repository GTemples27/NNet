#ifndef PERCEPTRON_H
#define PERCEPTRON_H

// DON'T THINK THIS IS NEEDED?

class Perceptron
{
    public:
        Perceptron();
        virtual ~Perceptron();
        Perceptron(const Perceptron& other);
        Perceptron& operator=(const Perceptron& other);
        void FeedForward(float[]);
        float Activate(float);

    private:
        int numInputs;
        pair <float, float> m_inputs[];
        float m_output;
};

#endif // PERCEPTRON_H
