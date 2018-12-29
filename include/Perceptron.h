#ifndef PERCEPTRON_H
#define PERCEPTRON_H


class Perceptron
{
    public:
        Perceptron();
        virtual ~Perceptron();
        Perceptron(const Perceptron& other);
        Perceptron& operator=(const Perceptron& other);

    protected:

    private:
};

#endif // PERCEPTRON_H
