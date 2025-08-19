#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;

    for (int i = n; n != 0; n--)
    {
        if (n % 2 != 0)
        {
            answer.push_back(n);
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}