#include "neuralnetwork.h"
#include <fstream>

using namespace std;
using namespace NeuralNET;

#define FOR(i,n)      for(int i=0;i<(n);i++)
#define N 2
#define OUT_N 2


void printPic(NeuralNetwork *net)
{
   int presnost = 10;
   net->loadWeights("vahy");

   //10x10 + presnost
   ofstream ofs("obrazok.ppm");
   ofs << "P3" << endl << 10*presnost << " " << 10*presnost << endl << 255 <<endl;

   FOR(i,10*presnost)
   {
     FOR(j,10*presnost)
     {
       vector<float> vstup;
       vstup.push_back((float)i/presnost-5);
       vstup.push_back((float)j/presnost-5);
       vector<int> c = net->discreteClassify(vstup);

       string o = "255 0 0 ";
       if(c[0]==1) o = "0 255 0 ";
       if(c[1]==1) o = "0 0 255 ";

       ofs << o;
     }
     ofs << endl;
   }
}
