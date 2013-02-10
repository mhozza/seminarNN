#include <iostream>
#include "binary_perceptron.h"
#include "continuous_perceptron.h"
#include "neuralnetwork.h"
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <sys/types.h>
#include <dirent.h>
#include <cstdio>
#include <csignal>

#include "picture.cpp"

using namespace std;
using namespace NeuralNET;

#define FOR(i,n)      for(int i=0;i<(n);i++)
#define N 16384
#define N_SIDE 128
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


vector<string> listDirectory(string path)
{
   vector<string> files;
   if(path[path.size()-1]!='/') path+='/';
   DIR *dp;
   struct dirent *ep;

   dp = opendir(path.c_str());
   if (dp != NULL)
   {
     while ((ep = readdir (dp)))
     {
       string s = ep->d_name;
       if(s=="." || s == "..") continue;
       files.push_back(path+s);
     }
     closedir(dp);
   }
   else
     perror ("Couldn't open the directory");
   return files;
}

template<class T> vector<T> make_vector(T t)
{
  vector<T> vt;
  vt.push_back(t);
  return vt;
}

inline void print(string s)
{
  cout << s << endl;
}


vector<float> loadImage(string path)
{
  print(path);
  ifstream ifs(path.c_str());
  vector<float> res;
  res.resize(N,0);
  //ppm without comments
  //head
  string hdr = "P2";
  ifs >> hdr;
  if(hdr!="P2") throw 1;
  //w, h
  int w = N_SIDE,h=N_SIDE;
  int colors = 256;
  ifs >> w >> h >> colors;
  if(w!=N_SIDE || h!=N_SIDE) throw 1;

  FOR(i,N)
  {
      int a;
      ifs >> a;
      res[i] = 255-a;
  }
  ifs.close();
  return res;
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

   unsigned sizes[] = {12,OUT_N};
   //NeuralNetwork *net = new NeuralNetwork(2,sizes,N,alpha);

   NeuralNetwork *net = new NeuralNetwork(2,sizes,N,alpha);
   signal(SIGINT, ctrlc);

   vector<pair<vector<float>,vector<int > > > tests;

   //net->saveWeights("blabla");

   string hands_path, nonhands_path;
   if(mode==0)
   {
    hands_path = "../../rocnikac/handcontrol/hand_images/hands_img";
    nonhands_path = "../../rocnikac/handcontrol/hand_images/other_img";
   }
   else
   {
    hands_path = "../hand_images/test/hands";
    nonhands_path = "../hand_images/test/other";
    net->loadWeights("vahy");
   }


   //nacitaj
   //net->loadWeights("vahy");
   vector<string> hands = listDirectory(hands_path);
   vector<string> nonhands = listDirectory(nonhands_path);

   for(unsigned i = 0;i<hands.size();i++)
   {
     tests.push_back(make_pair(loadImage(hands[i]),make_vector(1)));
   }

   for(unsigned i = 0;i<nonhands.size();i++)
   {
     tests.push_back(make_pair(loadImage(nonhands[i]),make_vector(0)));
   }
/*
   if(mode == 2)
   {
     printPic(net);
     return 0;
   }

   signal(SIGINT, ctrlc);

   if(argc>2)
   {
     verbose = atoi(argv[2]);
   }   

   vector<pair<vector<float>,vector<int> > > tests;   
   vector<pair<vector<float>,vector<int> > > verify;
   int testCount = 800;

   istream& ifs = cin;

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
     random_shuffle(tests.begin(),tests.end());
     for(int i = testCount*0.9;i<testCount;i++)
     {
       verify.push_back(tests[i]);
     }
     tests.resize(testCount*.9);
     testCount*=.9;
   }
   int verifyCount = verify.size();
*/

   if(mode==0)
   {
     float E = 100;
     int epoche = 0;
     //cout << "a,b - vstupy c - pozadovany vystup, d - vystup neuronu"<< endl ;
     int validacnaChyba = 100;     

     //while(validacnaChyba>0)
     //FOR(fn,600)
     int ok = 0;
     float sumVAE = 0;
     //while((sumVAE/verifyCount > 0.02 && epoche<1200) || epoche <10)

     int testCount = tests.size();
     while(epoche<1000)
     {
       float sumAE = 0;
       sumVAE = 0;

       epoche++;
       cerr << epoche << endl;
       E=0;
       random_shuffle(tests.begin(),tests.end());
       //cout << "   a b c d" << endl;
       FOR(i,tests.size())
       {
         if(verbose>1)
         {
           cout << i << ": ";
           FOR(j,N)
           {
              cout << tests[i].first[j] << " ";
           }
           cout << endl;
           FOR(j,OUT_N)
           {
              cout << tests[i].second[j] << " ";
           }
           cout << endl;
           vector<int> dc = net->discreteClassify(tests[i].first);
           vector<float> c = net->classify(tests[i].first);
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
         float e = net->train(tests[i].first,tests[i].second);
         sumAE += getError(net->classify(tests[i].first),tests[i].second);
         E += e;
       }
       validacnaChyba = 0;
       /*if(verbose>1) cout << endl << "Validacia: " << endl;
       FOR(i,verifyCount)
       {
         if(verbose>1)
         {
           cout << i << ": ";
           FOR(j,N)
           {
              cout << verify[i].first[j] << " ";
           }
           cout << endl;
         }
         if(verbose)
         {
           FOR(j,OUT_N)
           {
              cout << verify[i].second[j] << " ";
           }
           cout << endl;
         }
         vector<int> dc = net->discreteClassify(verify[i].first);
         vector<float> c = net->classify(verify[i].first);
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

         if(verify[i].second[0]!=dc[0] || verify[i].second[1]!=dc[1]) validacnaChyba++;

         sumVAE += getError(c,verify[i].second);

       }
       if(verbose) cout <<  "Validacna chyba: ";
       cout << validacnaChyba;
       if(verbose) cout << " = " << 100*(float)validacnaChyba/verifyCount << "%" << endl;*/
       /*cout << "Vahy: ";
       pcn->printWeights();*/

       if(verbose) cout << "Priemerna chyba na trenovacej mnozine:" << sumAE/testCount << endl;
       //if(verbose) cout << "Priemerna chyba na validacnej mnozine:" << sumVAE/verifyCount << endl;

       if(!verbose) cout << "," << sumAE/testCount;// << "," << sumVAE/verifyCount;

       if(verbose) cout << "Chyba: ";
       else cout << ",";       
       cout << E << endl;

       if(validacnaChyba==0) ok++;
       else ok=0;
       //if(ok>=3 || epoche>1000) break;
       if(stop) break;
     }
     if(verbose)cout << epoche << endl;
     net->saveWeights("vahy");
   }
/*   else if(mode == 1)
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
   }*/
}
