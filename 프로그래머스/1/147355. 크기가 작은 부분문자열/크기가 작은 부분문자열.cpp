#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    int left= 0;
    int right = p.length();
    
    while(right <= t.length())
    {
        string s;
        for(int i = left; i<right; i++)
            s+=t[i];
        if(stoll(s)<=stoll(p)) answer++;
        
        left++; right++;
    }
    
    return answer;
}