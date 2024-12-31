#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    for(int i=0; i<s.length(); i++)
    {
        int index = -1;
        for(int j=i-1; j>=0; j--)
        {
            if(s[j] == s[i])
            {
                index = i-j;
                break;
            }
        }
        answer.push_back(index);
    }
    return answer;
}