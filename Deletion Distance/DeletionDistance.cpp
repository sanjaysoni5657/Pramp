#include <iostream>
#include <string>
using namespace std;

int deletionDistance(string &s1, string &s2, int i, int j) {
    
    // base case
    int count = 0;
    int n1 = s1.size(), n2 = s2.size();
  
    if(i == n1 && j < n2) {
      return n2 - j;
    }
  
    if(j == n2 && i < n1) {
      return n1 - i;
    }
  
    if(i >= n1 && j >= n2) {
      return 0;
    }
  
    if(s1 == s2) {
      return 0;
    }
    
    if(s1[i] == s2[j]) {
      count = deletionDistance(s1, s2, i+1, j+1);
    } else { 
        count = 1 + min(deletionDistance(s1, s2, i+1, j), deletionDistance(s1, s2, i, j+1));
    }
  
  return count;
  
}

int deletionDistance( const string& str1, const string& str2 ) 
{
  // your code goes here
  string s1 = str1, s2 = str2;
  return deletionDistance(s1, s2, 0, 0);
  
}

int main() {
  return 0;
}
