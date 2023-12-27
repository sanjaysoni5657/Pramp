#include <iostream>
#include <vector>

using namespace std;

int findBusiestPeriod( const vector<vector<int> >& data ) 
{
  // your code goes here
  int gMax = 0;
  int max_so_far = 0;
  int lMax = 0;
  int n = data.size();
  
for(int i = 0; i < n; i++) {   
  
    if(data[i][2] == 1) {
        lMax += data[i][1];
      } else {
        lMax -= data[i][1];
      }
  
    if(i < n -1 && data[i][0] == data[i+1][0]) {
      continue;
    }

    if(lMax > gMax) {
      gMax = lMax;
      max_so_far = data[i][0];
    }
}
  return max_so_far;
}

int main() {
  return 0;
}
