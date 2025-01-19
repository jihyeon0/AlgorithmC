#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    //정렬
   sort(lost.begin(), lost.end());
   sort(reserve.begin(), reserve.end());

// 여분 있는 학생 중에 도둑 맞은 학생 있는지 검사
    for (auto n = lost.begin(); n != lost.end();)
    {
        auto it = find(reserve.begin(), reserve.end(), *n);
        if (it != reserve.end()) //여분중에 도둑맞았다면
        {
            reserve.erase(it); // 배열에서 삭제
            n = lost.erase(n);
        }
        else
            n++;
    }

// 여분 있는 학생이 확정되면 이웃 번호인지 검사
    for (auto n = reserve.begin(); n != reserve.end();)
    {
        auto iter = find(lost.begin(), lost.end(), *n - 1);
        if (iter != lost.end())
        {
            iter = lost.erase(iter); // 이웃 번호이면 분실 배열에서 삭제 
            n = reserve.erase(n);
            continue;
        }
        iter = find(lost.begin(), lost.end(), *n + 1);
        if (iter != lost.end())
        {
            iter = lost.erase(iter); // 이웃 번호이면 분실 배열에서 삭제 
            n = reserve.erase(n);
            continue;
        }
        n++;
    }
    answer = n - static_cast<int>(lost.size());

    return answer;
}