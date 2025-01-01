#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> v;
    for(int i=0; i<score.size(); i++) //프로그램이 진행된 날들
    {
        v.push_back(score[i]);
        sort(v.begin(), v.end(), greater<int>());
        if(i<k) //k번째 날까지 중에는 가장 작은 수 리턴
        {
            answer.push_back(v[i]);
        }
        else //k번째 날 이후는 k-1번째 리턴
        {
            answer.push_back(v[k-1]);
        }
        
    }
    return answer;
}