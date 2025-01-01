#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> answer1 = {1, 2, 3, 4, 5};
    vector<int> answer2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> answer3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
     vector<int> cnt = {0,0,0};
    int imax = -1;
    for(int i=1; i<=answers.size(); i++)
    {
        if(answers[i-1] == answer1[(i-1)%answer1.size()])
            cnt[0] +=1;
         if(answers[i-1] == answer2[(i-1)%answer2.size()])
            cnt[1] +=1;
         if(answers[i-1] == answer3[(i-1)%answer3.size()])
            cnt[2] +=1;
    }
    for(int i=0;i<cnt.size(); i++)
    {
        imax = max(imax,cnt[i]);
    }
    for(int i=0;i<cnt.size(); i++)
    {
        if(cnt[i] == imax)
            answer.push_back(i+1);
    }
    
    return answer;
}