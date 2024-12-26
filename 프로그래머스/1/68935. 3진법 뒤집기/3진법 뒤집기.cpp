#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    int v;
    vector<int> arr;
    while(n > 0)
    {
        v = n%3;
        arr.push_back(v);
        n = n/3;
    }
    reverse(arr.begin(), arr.end());
    for(int i=0; i< arr.size(); i++)
    {
        answer += arr[i] * pow(3,i);
    }
    return answer;
}