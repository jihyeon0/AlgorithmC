#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool myfind(const string& a, const string& b, int n)
{
    if(a[n] == b[n])
        return a<b;
    
    return a[n] < b[n];
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    sort(strings.begin(), strings.end(),[n](const string& a, const string& b)
    {
        return myfind(a,b,n);
    });
    
    answer = strings;
    return answer;
}