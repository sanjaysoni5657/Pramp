#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> getIndicesOfItemWeights( const vector<int>& arr, int limit)
{
  // your code goes here

  map<int, int> map;
  
  // [4,4,1]
  for(int i = 0; i < arr.size(); i++) {
    int comp = limit - arr[i];
    
    if(map.count(comp) > 0) {
      return {i, map[comp]};
    }
    
    map[arr[i]] = i;
  }
  
  return {};
}

int main() {
  return 0;
}

// Approach 1 - Bruteforce/naive
// Approach 2 - hashset TC - O(n), SC - O(n)
