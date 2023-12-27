#include <iostream>
#include <vector>


using namespace std;

vector<int> findArrayQuadruplet(const vector<int> &arr, int s, int index, int count, vector<int>& quadruplet) {
 
  if(count == 4) {
    if(s == 0) {
      return quadruplet;
    } else {
      return {};
    }
  }
  
  if(index >= arr.size()) {
    return {};
  }
  
  quadruplet.push_back(arr[index]);
  vector<int> result = findArrayQuadruplet(arr, s-arr[index], index+1, count+1, quadruplet);
  quadruplet.pop_back();
  
  if(!result.empty()) {
    return result;
  }
  
  result = findArrayQuadruplet(arr, s, index+1, count, quadruplet);
  
  return result;
}

vector<int> findArrayQuadruplet(const vector<int> &arr, int s) 
{
  // your code goes here
  vector<int> quadruplet;
  vector<int> result;
  vector<int> arrN = arr;
  sort(arrN.begin(), arrN.end());
  return findArrayQuadruplet(arrN, s, 0, 0, quadruplet);
}

int main() {
  vector<int> quadruplet;
  vector<int> result = findArrayQuadruplet({2,7,4,0,9,5,1,3}, 20, 0, 0, quadruplet);
  for (int n : result) {
    cout << n << " ";
  }
  return 0;
}

// Approach 1 BruteForce/Naive 
// 4 nested for loop
// TC - O(n^4), SC - O(1)

// Approach 2 - HashMap<arr[index], index>, 3 nested for loop
// TC - (n^3), SC - O(n)
// Map<int, int> = {{2, 0}, {7, 1}, {4, 2}, {0, 3}, {9, 4}}
// 3 for loop,
// track 3 indices 
// compliment_value = (target - sumOfThreeIndices)

// x1 + x2 + x3 + x4 = target
// x4 = (target - x1 - x2 - x3)
// <target - x4> = x1 + x2 + x3

// Appraoch 3- Recursion 
// TC - O(n^3), SC - O(n)


