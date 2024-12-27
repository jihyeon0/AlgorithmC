#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i =0; i<s.length(); i++)
    {
        if(s[i] == ' ') continue;
       
        if(isupper(s[i]))
        {
            s[i] = (s[i] -'A' + n)%26 + 'A';
        }
       else if(islower(s[i]))
        {
            s[i] = (s[i] -'a' + n)%26 + 'a';
        }
         
    }
    answer = s;
    return answer;
}