#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cctype>

using namespace std;

void bucketSort(vector<vector<string>>& result) {
    int n = result.size();
    int maxVal = 0;
    for(int i = 0; i < n; i++) {
        maxVal = max(maxVal, stoi(result[i][1]));
    }
    vector<vector<vector<string>>> buckets(maxVal + 1);
    for(int i = 0; i < n; i++) {
        buckets[stoi(result[i][1])].push_back(result[i]);
    }
    int index = 0;
    for(int i = maxVal; i >= 0; i--) {
        for(int j = 0; j < buckets[i].size(); j++) {
            result[index++] = buckets[i][j];
        }
    }
}

vector<vector<string>> wordCountEngine( const string& document ) 
{
  string doc = document;
  transform(doc.begin(), doc.end(), doc.begin(), ::tolower);
  
  doc.erase(remove_if(doc.begin(), doc.end(), ::ispunct), doc.end());
   
  unordered_map<string, int> wordCount;
  vector<string> words;
  string word;
  
  for(char& c : doc){
    if(c == ' ') {
      if(!word.empty()){
        if(wordCount[word]++ == 0){
          words.push_back(word);
        }
      }
      word.clear();
    } else {
      word += c;
    }
  }
  
  if(!word.empty() && wordCount[word]++ == 0){
    words.push_back(word);
  }
  
  vector<vector<string>> result;
  
  for(string& word : words) {
    result.push_back({word, to_string(wordCount[word])});
  }
  
  bucketSort(result);
  
  return result;
}

int main() {
  string document = "Practice makes perfect. you'll only get Perfect by practice. just practice!";
    vector<vector<string>> result = wordCountEngine(document);
    for (auto& pair : result) {
        cout << pair[0] << ": " << pair[1] << endl;
    }
  return 0;
}
