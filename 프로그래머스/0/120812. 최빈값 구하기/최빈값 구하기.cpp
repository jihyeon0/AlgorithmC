#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> array) {
    
    unordered_map <int, int> m;

    for (auto& num : array)
    {
        m[num]++;
    }
    
    int maxCount = 0;
    int answer = -1;

    for (auto& num : m) 
    {
        if (num.second > maxCount)
        {
            maxCount = num.second;
            answer = num.first;
        }
    }

    for (auto& num : m)
    {
        if (num.first != answer && num.second == maxCount)
        {
            return -1;
        }
    }

    return answer;
}