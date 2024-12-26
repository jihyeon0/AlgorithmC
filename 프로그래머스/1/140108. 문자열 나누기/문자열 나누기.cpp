#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    char x;
    int match=0;
    int mismatch=0;
    vector<string> arr;
    
    
    while(s.length()>0)
    {
        string a;
        x = s[0];
        match = mismatch = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(x==s[i])
            {
                match++;
            }
            else
            {
                mismatch++;
            }
            
           a += s[i];
            
            if(match == mismatch)
            {
                arr.push_back(a);
                s = s.substr(a.length());
                break;
            }
            
             if(match != mismatch && i == s.length()-1) 
            {
                arr.push_back(a);
                s = s.substr(a.length());
            }
        }
       
    }
    answer = arr.size();
    return answer;
}