#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};


/*
binaryMatrix = [ [0,    1,    0,    1,    0],
                 [0,    0,    1,    1,    1],
                 [1,    0,    0,    1,    0],
                 [0,    1,    1,    0,    0],
                 [1,    0,    1,    0,    1] ]
*/

int getNumberOfIslandsH(vector<vector<int>>& binaryMatrix, int i, int j) {

  queue<pair<int,int>> q;
  
  // boundary conditions
  int m = binaryMatrix.size(), n = binaryMatrix[0].size();
  
  if(i < 0 || j < 0 || i >= m || j >= n) {
    return 0;
  }
  
  // Base condition
  if(binaryMatrix[i][j] == 0) {
    return 0;
  }
  
  // mark matrix visited
  binaryMatrix[i][j] = 0;
  
  for(int k = 0; k < dir.size(); k++) {
    
    q.push({i+dir[k].first, j+dir[k].second});
    
  }
  
  while(!q.empty()) {
    pair<int,int> pos = q.front();
    q.pop();
    getNumberOfIslandsH(binaryMatrix, pos.first, pos.second);
  }
  
  return 1;
}

int getNumberOfIslands( const vector<vector<int>>& binaryMatrix ) 
{
  // your code goes here
  vector<vector<int>> binaryMatrixN = binaryMatrix;
  int m = binaryMatrix.size(), n = binaryMatrix[0].size();
  int count = 0;
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      count += getNumberOfIslandsH(binaryMatrixN, i, j);
    }
  }
  
  return count;
}

int main() {
  return 0;
}


