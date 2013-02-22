#ifndef ELMANNETWORK_H
#define ELMANNETWORK_H

#include "neurallayer.h"
#include "neuralnetwork.h"

namespace NeuralNET
{
  class ElmanNetwork : public NeuralNetwork
  {
    vector<vector<vector<float> > > net, y;
    vector<vector<vector<vector<vector<vector<float> > > > > > d;
    float der(int t, int k);
    int time;    
  protected:    
    vector<float> hiddenCopy;    
    void setHiddenCopy(vector<float> values);
    float der(int t, int lk, int k, int li, int i, int j);
  public:
      ElmanNetwork(unsigned hiddensize, unsigned outsize, unsigned dimension, float alpha);
      void resetHiddenCopy();
      float train(vector<float>, vector<int>);
      vector<float> classify(vector<float> input, bool silent = false);
      vector<int> discreteClassify(vector<float> input, bool silent = false);
  };
}
#endif // ELMANNETWORK_H
