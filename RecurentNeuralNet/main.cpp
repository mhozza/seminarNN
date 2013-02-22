#include <iostream>
#include "continuous_perceptron.h"
#include "neuralnetwork.h"
#include "elmannetwork.h"
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <csignal>

using namespace std;
using namespace NeuralNET;

#define FOR(i,n)      for(int i=0;i<(n);i++)
#define N 2
#define OUT_N 1

volatile int stop = 0;

void ctrlc(int signal __attribute__((unused)))
{
    stop = 1;
}

float getError(vector<float> out,vector<int> target)
{
  float e = 0;
  for(unsigned i = 0;i<out.size();i++)
  {
    e+=abs(out[i]-target[i]);
  }
  return e;
}

int main(int argc, char *argv[])
{  

   srand (time(NULL) );
   float alpha = 0.2;
   /*if(argc>1)
   {
     alpha = atof(argv[1]);
   } */

   int verbose = 0;
   int mode = 0;
   if(argc>1)
   {
     mode = atoi(argv[1]);
   }

   //unsigned sizes[] = {5,OUT_N};
   ElmanNetwork *net = new ElmanNetwork(2,OUT_N,N,0.1);
   //NeuralNetwork *net = new NeuralNetwork(2,sizes,2,0.05);

   //signal(SIGINT, ctrlc);

   if(argc>2)
   {
     verbose = atoi(argv[2]);
   }

   vector<pair<vector<float>,vector<int> > > tests;   
   //vector<pair<vector<float>,vector<int> > > verify;
   int testCount = 800;

   //istream& ifs = cin;

   ifstream ifs("p1.in");

   ifs >> testCount;
   tests.resize(testCount);   

   FOR(i,testCount)
   {    
     FOR(j,N)
     {
       float t;
       ifs >> t;
       tests[i].first.push_back(t);       
     }
     FOR(j,OUT_N)
     {
       int t;
       ifs >> t;
       tests[i].second.push_back(t);
     }     
   }

   if(mode==0)
   {
     float E = 100;
     int epoche = 0;
     //FOR(fn,600)
     int ok = 0;
     float sumVAE = 0;
     //while((sumVAE/verifyCount > 0.02 && epoche<1200) || epoche <10)
     while(epoche<500)
     {
       float sumAE = 0;
       sumVAE = 0;
       //net->resetHiddenCopy();
       epoche++;
       cerr << epoche << endl;
       E=0;

       FOR(i,testCount)
       {
         //if(verbose>1)
         {
           cout << i << ": ";
           FOR(j,N)
           {
              cout << tests[i].first[j] << " ";
           }
           //cout << endl;
           FOR(j,OUT_N)
           {
              cout << tests[i].second[j] << " ";
           }
           /*if(tests[i].first[0]) cout << "A"; else cout << "B";
           if(tests[i].second[0]) cout << "a"; else cout << "b";*/
           cout << ":";
           //vector<int> dc = net->discreteClassify(tests[i].first, true);
           vector<float> c = net->classify(tests[i].first,true);
           //vector<float> c = net->classify(tests[i].first);
           /*if (c[0]>c[1])  cout << "a"; else cout << "b";
           /*FOR(j,OUT_N)
           {
              cout << dc[j] << " ";
           }
           cout << endl;*/
           FOR(j,OUT_N)
           {
              cout << " " << c[j];
           }

           cout << endl;
         }

         float e = net->train(tests[i].first,tests[i].second);
         cout << e << endl;
         //sumAE += getError(net->classify(tests[i].first),tests[i].second);
         E += e;
       }
     }
     net->saveWeights("vahy");
   }
   else if(mode == 1)
   {
     net->loadWeights("vahy");
     int validacnaChyba = 0;
     float sumVAE = 0;
     FOR(i,testCount)
     {
       if(verbose>1)
       {
         cout << i << ": ";
         FOR(j,N)
         {
            cout << tests[i].first[j] << " ";
         }
         cout << endl;
       }
       if(verbose)
       {
         FOR(j,OUT_N)
         {
            cout << tests[i].second[j] << " ";
         }
         cout << endl;
       }
       vector<int> dc = net->discreteClassify(tests[i].first);
       vector<float> c = net->classify(tests[i].first);
       if(verbose>0)
       {
         FOR(j,OUT_N)
         {
            cout << dc[j] << " ";
         }
         cout << endl;
         FOR(j,OUT_N)
         {
            cout << c[j] << " ";
         }
         cout << endl;
       }

       if(tests[i].second[0]!=dc[0] || tests[i].second[1]!=dc[1]) validacnaChyba++;
       sumVAE += getError(c,tests[i].second);
     }
     if(verbose) cout <<  "Validacna chyba: ";
     cout << validacnaChyba;
     if(verbose) cout << " = " << 100*validacnaChyba/(float)testCount << "%" << endl << "Odchylka: ";
     cout << " " << sumVAE/testCount;
     cout << endl;
   }
}

