#ifndef BINARY_PERCEPTRON_H
#define BINARY_PERCEPTRON_H

using namespace std;

#include "perceptron.h"


namespace NeuralNET
{
  class BinaryPerceptron : public Perceptron
  {
  protected:
    float activationFunction(const vector<float>*);
    float derivativeFunction(float);
  public:    
    BinaryPerceptron(unsigned dimension, float alpha = 0.25) : Perceptron(dimension,alpha) {  }
  };
}
#endif // PERCEPTRON_H
