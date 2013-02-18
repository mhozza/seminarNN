#include "continuous_perceptron.h"
#include <iostream>

using namespace NeuralNET;
using namespace std;

#define MATH_E 2.7182818284590451


float ContinuousPerceptron::derivativeFunction(float x)
{
  return x*(1-x);
}

float ContinuousPerceptron::activationFunction(const vector<float>* input)
{
  float sum = weightSum(input->begin(),input->end(),weights.begin(),weights.end());
  return (1./(1.+exp(-sum)));
}

