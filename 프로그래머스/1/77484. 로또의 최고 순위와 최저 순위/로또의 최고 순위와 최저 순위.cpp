#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer; //오름차순 1등 2등...
    vector<int> rank = { 6,5,4,3,2,1 };
    int cnt = 0;
    int blank = 0;
    for (int i = 0; i < lottos.size(); i++)
    {
        if (lottos[i] == 0)
        {
            blank++;
            continue;
        }
        for (int j = 0; j < win_nums.size(); j++)
        {
            if (lottos[i] == win_nums[j]) //일치하는 번호가 있으면
            {
                cnt++;
                break;
            }
        }
    }
    //for문 다 돌고나면 0의 개수와 일치하는 숫자 개수가 나옴
    
    // 0의 개수 + 일치하는 숫자 개수 는 당첨 가능한 최고 순위

    //일치하는 숫자 개수는 당첨 가능한 최하 순위
    for (int i = 0; i < rank.size(); i++)
    {
        if (cnt <= 1) //그외 순위에 대한 예외처리
        {
            answer.push_back(6);
            break;
        }
        if (cnt == rank[i])
        {
            answer.push_back(i+1);
        }
    }
    for (int i = 0; i < rank.size(); i++)
    {
        if (cnt + blank <= 1)
        {
            answer.push_back(6);
            break;
        }
        if (cnt + blank == rank[i])
        {
            answer.push_back(i + 1);
        }
    }
    sort(answer.begin(), answer.end());

    return answer;
}