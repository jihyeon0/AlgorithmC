#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
vector<int> v;
long long solution(long long n) {
    long long answer = 0;
    
    while(n>0)
    {
        v.push_back(n%10);
        n /= 10;
    }
    sort(v.begin(), v.end(),greater<int>());
    
    for(int i=0; i<v.size(); i++)
    {
       answer += v[i] * pow(10,v.size()-i-1);
    }
    
    return answer;
}