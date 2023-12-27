#include <iostream>
#include <string>
#include <stack>

using namespace std;

int bracketMatch( const string& text ) 
{
  // your code goes here
  
  stack<char> char_stack;
  int count = 0;
  
  for(auto &it : text) {
    
    if(char_stack.empty()) {
        char_stack.push(it);
    }
    else if(it == ')' && char_stack.top() == '('){
        char_stack.pop();
    } else {
        char_stack.push(it);
    }
  }
  
  while(!char_stack.empty()) {
      char_stack.pop();
      count++;
  }
  
  // return char_stack.size();  
  return count;
}

int main() {
  return 0;
}
