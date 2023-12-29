#include <iostream>;
#include <string>;
#include <vector>;

using namespace std;

bool validateIP(const string & ip) {
  if (ip.size() < 7) {
    return 0;
  }
  
  string str = "";
  vector<string> ips;
  for (int i = 0; i < ip.size(); i++) {
    if(ip[i] == '.') {
      // cout << str << " ";
      ips.push_back(str);
      str = "";
      continue;
    }
    str += ip[i];
  }
  // cout << str << " ";
  ips.push_back(str);
  
  if(ips.size() != 4) {
    return false;
  }
  
  for(auto &it : ips) {
    // cout << "it " << it << " ";
    if(it.size() < 1) {
      return false;
    }
    if(it.size() > 1 && it[0] == '0') {
      return false;
    }
    
   for(int j = 0; j < it.size(); j++) {
     cout << it << " ";
      if(it[j] < '0' || it[j] > '9') {
        return false;
      }
    }
    
    if(stoi(it) < 0 || stoi(it) > 255) {
      cout << it << " ";
      return false;
    }
  }
  
  return true;
}

int main() {
  cout << validateIP("0.0.0.0") << endl;
  return 0;
}
