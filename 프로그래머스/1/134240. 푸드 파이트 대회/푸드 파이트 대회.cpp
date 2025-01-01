#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    for (int i = 0; i < food.size(); i++)
    {
        int cnt = 0;
        if (food[i] / 2 < 1) continue;
        for (int j = 0; j < food[i] / 2; j++)
        {
            answer += to_string(i);
        }
    }
    string reverse;
    reverse = answer;
    std::reverse(reverse.begin(), reverse.end());
    answer += to_string(0);
    answer += reverse;
    return answer;
}