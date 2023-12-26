#import <iostream>
#import <string>
#import <vector>

using namespace std;

// time complexity = state * transition = O(n)
// space complexity = O(n)
int nWays(const string& s, int i, vector<int>& dp) {  
  if(i >= s.size()) {
    return 1;
  }
  
  int count = 0;
  int first = s[i];
  
  if(dp[i] > -1) {
    return dp[i];
  }
  
  if(first > '0' && first <= '9') { // "111111111"
    count += nWays(s, i+1, dp);
  }
 
  if(i+1 < s.size() && s[i] != '0') {
    int second = stoi(s.substr(i,2)); // (stoi(s[i])*10 + stoi(s[i+1])); // 02
    if(second > 0 && second <= 26) {
      count += nWays(s, i+2, dp);
    }
  }
  
  return dp[i] = count;
  
}


int decodeVariations(const string& S)
{
  if(S.size() == 0) {
    return 0;
  }
	// your code goes here
  if(S[0] == '0') {
    return 0;
  }
  
  vector<int> dp(S.size(), -1);
  
  string s = S;
  
  return nWays(s, 0, dp);
}


int main() 
{
 	return 0;
}
