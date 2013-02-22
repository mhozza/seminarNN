#include "elmannetwork.h"
#include "iostream"

using namespace std;

namespace NeuralNET
{

  ElmanNetwork::ElmanNetwork(unsigned hiddensize, unsigned outsize, unsigned dimension, float alpha) : NeuralNetwork(0,NULL,dimension,alpha)
  {
    layers.resize(2);
    layers[0] = new NeuralLayer(hiddensize, dimension+hiddensize ,alpha);
    hiddenCopy.resize(hiddensize,0.5);
    layers[1] = new NeuralLayer(outsize, hiddensize ,alpha);    
    time = 0;

    //init d, net, y, ones
    /*d.resize(layers.size()+1);
    for(int i=0;i<d.size();i++)
    {
      if(i==0)
        d[i].resize(dimension);
      else
        d[i].resize(layers[i-1]->neurons.size());
      for(int j=0;j<d[i].size();j++)
      {
        if(i==0)
          d[i][j].resize(dimension+1);
        else if(i==1)
          d[i][j].resize(dimension+hiddensize+1);
        else
          d[i][j].resize(layers[i-2]->neurons.size()+1);
        for(int k=0;k<d[i][j].size();k++)
        {
          d[i][j][k].resize(2);
          for(int l=0;l<d[i][j][k].size();l++)
          {
            d[i][j][k][l].resize(layers.size()+1);
            for(int m=0;m<d[i][j][k][l].size();m++)
            {
                if(l==0)
                  d[i][j][k][l][m].resize(dimension+1,0);
                else
                  d[i][j][k][l][m].resize(layers[l-1]->neurons.size()+1,0);
            }
          }
        }
      }
    }*/

    net.resize(2);y.resize(2);
    for(int i=0;i<y.size();i++)
    {
      y[i].resize(3);
      y[i][0].resize(dimension+hiddensize+1,0);
      y[i][1].resize(hiddensize+1,0);
      y[i][2].resize(outsize+1,0);
    }

    for(int i=0;i<net.size();i++)
    {
      net[i].resize(layers.size());
      for(int j=0;j<net[i].size();j++)
      {
        net[i][j].resize(layers[j]->neurons.size(),0);
      }
    }

  }

  void ElmanNetwork::resetHiddenCopy()
  {
    size_t sz = hiddenCopy.size();
    hiddenCopy.resize(0);
    hiddenCopy.resize(sz,0.5);
  }

  void ElmanNetwork::setHiddenCopy(vector<float> values)
  {
    if(values.size()==hiddenCopy.size())
    {
      for(unsigned i = 0;i<hiddenCopy.size();i++)
      {        
        hiddenCopy[i]=values[i];
      }
    }
  }

  float ElmanNetwork::der(int t, int lk, int k, int li, int i, int j)
  {
    if(t<=0) return 0;
    if(lk<0) return 0;
    if(k>=layers[lk]->neurons.size()) return 0;
    /*if(li>lk) return 0;
    if(lk==0)
    {
      if(i!=k) return 0;
      vector<float> weights = layers[lk]->neurons[k]->getWeights();
      float sum = 0;
      for(int l = 0;l<weights.size();l++)
      {
        sum += weights[l]*der(t-1,lk,l,li,i,j);
      }
      //cout << "i==k: " <<  y[t-1][li][j] << " " << layers[lk]->derivativeFunction(net[t-1][lk][k],k) << endl;
      return (y[t-1][li][j]+sum) * layers[lk]->derivativeFunction(net[t-1][lk][k],k);
    }

    if(li==1)
    {
      if(i!=k) return 0;
      return y[t-1][li][j] * layers[lk]->derivativeFunction(net[t-1][lk][k],k);
    }
*/
    vector<float> weights = layers[lk]->neurons[k]->getWeights();
    float sum = 0;
    for(int l = 0;l<weights.size();l++)
    {
      sum += weights[l]*der(t-1,lk-1,l,li,i,j);
    }
    if(li==lk && i==k) sum += y[t-1][li][j];
    /*cout << t << " " << lk << " " << k << " " << li << " " << i << " " << j << endl;
    cout << "SUM: " << sum << endl;*/
    return sum* layers[li]->derivativeFunction(net[t-1][lk][k],i);

  }

  float ElmanNetwork::train(vector<float> input,vector<int> target)
  {
    time++;
    vector<vector<float> > in;
    in.resize(layers.size()+1);
    in[0] = input;
    in[0].insert(in[0].end(),hiddenCopy.begin(),hiddenCopy.end());
    y.resize(y.size()+1);
    net.resize(net.size()+1);

    y.back().resize(3);
    for(int j=0;j<y.back().size();j++)
    {
      y.back()[j].resize(y[y.size()-2][j].size(),0);
    }

    net.back().resize(layers.size());
    for(int j=0;j<net.back().size();j++)
    {
      net.back()[j].resize(layers[j]->neurons.size(),0);
    }


    y[time][0] = in[0];
    y[time][0].push_back(1);

    for(unsigned i = 0;i<layers.size();i++)
    {     
      in[i+1] = layers[i]->classify(in[i]);
      net[time][i] = layers[i]->net(in[i]);
      y[time][i+1] = in[i+1];
      y[time][i+1].push_back(1);

      for(int j = 0;j<in[i+1].size();j++)
      {
        cout << in[i+1][j] << " ";
      }
      cout << endl;
    }

    //setHiddenCopy(in[1]);

    float err = layers.back()->getError(in.back(),target);
    if(err>0)
    {
      vector<float> e;
      e.resize(target.size());

      for(unsigned i = 0;i<layers.size();i++)
      {
        for(unsigned j = 0; j< layers[i]->neurons.size();j++)
        {
          for(unsigned k = 0; k<(layers[i]->neurons[j]->weights.size());k++)
          {
            float sum = 0;
            for(unsigned l = 0; l< target.size();l++)
            {
            /*  cout << "T:" << (target[l]-in.back()[l]) << endl;
              cout << "D:" << der(time,layers.size()-1,l,i,j,k) << endl;*/
              sum += (target[l]-in.back()[l]) * der(time,layers.size()-1,l,i,j,k);
            }
            layers[i]->neurons[j]->weights[k] = layers[i]->neurons[j]->weights[k] + layers[i]->neurons[j]->alpha*sum;
            cout << "Menim vahu: L: " << i << " N: " << j << " W: " << k << " o: " << layers[i]->neurons[j]->alpha*sum << endl;
          }
        }
      }
    }

    return err;
  }

  vector<float> ElmanNetwork::classify(vector<float> input, bool silent)
  {
    vector<float> in = input;
    in.insert(in.end(),hiddenCopy.begin(),hiddenCopy.end());

    for(unsigned i = 0;i<layers.size()-1;i++)
    {
      in = layers[i]->classify(in);
      if(i==0 && !silent) setHiddenCopy(in);
    }
    return layers[layers.size()-1]->classify(in);
  }

  vector<int> ElmanNetwork::discreteClassify(vector<float> input, bool silent)
  {
    vector<float> o = classify(input,silent);
    vector<int> r;
    r.resize(o.size());

    for(unsigned i = 0;i<o.size();i++)
    {
      r[i]=o[i]>.5;
    }
    return r;
  }

}
