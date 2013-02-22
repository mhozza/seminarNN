#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define FOR(i,n)      for(int i=0;i<(n);i++)

int main(int argc, char *argv[])
{
    srand (time(NULL) );
    int n;//dlzka postupnosti
    cin >> n;
    cout << n << endl;
    int state = 0;    
    FOR(i,n)
    {
      bool minca = rand()%2;
     /* cout <<  (minca ? "1 0 " : "0 1 ");
      //cout << minca << " ";
      switch(state)
      {
        case 0:
          state += 1-minca;          
          cout <<  (minca ? "1 0" : "0 1");
          //cout << minca << " ";
          break;
        case 1:
          state += minca;          
          cout <<  (1-minca ? "1 0" : "0 1");
          //cout << 1-minca << " ";
          break;
        case 2:
          state -= minca;
          cout <<  (minca ? "1 0" : "0 1");
          //cout << minca << " ";
          break;
        default:
          cout << "?";
      }
      cout << endl;*/
      cout << minca << " " << 1- minca << " " << minca << endl;
    }
}
