#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for (auto& num : numbers)
    {
        num *= 2;
    }
    answer = numbers;
    return answer;
}