#include <iostream>
#include <vector>

using namespace std;

int calcDroneMinEnergy( const vector<vector<int>>& route ) 
{
  // your code goes here
  
  if(route.size() <= 1) {
    return 0;
  }
  
  int minEnergy = 0;
  
  int prevZ = route[0][2];
  int energy = 0;
  for(int i = 1; i < route.size(); i++) {
    int z = route[i][2];
    
    // ascending
    if(z > prevZ) {
      energy -= (z - prevZ);
    } else { // descending
     energy += (z + prevZ);
    }
    
    minEnergy = min(minEnergy, energy);
    prevZ = z;
  }
  
  return abs(minEnergy);
}

int main() {
  return 0;
}
