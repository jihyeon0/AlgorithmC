#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool isValid(string word)
{
  string prev = "";
  vector<string> can ={ "aya", "ye", "woo", "ma" };
  while(!word.empty())
  {
      bool found = false;
      for(string s: can)
      {
          if(word.find(s) == 0)
          {
              if(prev  ==s) return false;
              word = word.substr(s.length());
              prev = s;
              found  = true;
              break;
          }
      }
      if(!found) return false;
  }
    return true;
}
    
int solution(vector<string> babbling) {
 
    int answer = 0;
    
    for (string& word : babbling) 
    {
        if (isValid(word)) answer++;
    }
    
    return answer;
}