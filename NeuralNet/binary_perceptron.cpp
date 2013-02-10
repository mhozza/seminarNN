#include "binary_perceptron.h"

using namespace NeuralNET;

float BinaryPerceptron::derivativeFunction(float)
{
  return 1;
}

float BinaryPerceptron::activationFunction(const vector<float>* input)
{ 
  float sum = weightSum(input->begin(),input->end(),weights.begin(),weights.end());  
  return sum>=0;
}
