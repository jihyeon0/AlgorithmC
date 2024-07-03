#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, num;

int arr[20][20]; // 능력치 저장 표
bool visited[20] = { false, }; //뽑혔는지 검사
int teamA[10] = { 0, }; // 뽑힌 팀원의 번호 저장
int teamB[10] = { 0, }; 

int _min = INT32_MAX; //능력치 차이 최솟값


void back(int cnt,//현재 팀원을 몇명 뽑았는지
          int num) // 선수 번호 
{
    //탈출 조건
    if (N / 2 == cnt) //번호 다 뽑았으면 팀에 넣어준다
    {
        int Acnt = 0;
        int Bcnt = 0;
        //teamA는 완성된 상태 teamA = { 0번 3번 5번...}
        
        //teamB 완성 시키기
        for (int i = 0; i < N; ++i) //0~N-1까지 돌면서 teamA[i] 가 아니면 teamB에 넣는다
        {
            if (!visited[i]) //방문한적이없으면
            {
                teamB[Bcnt] = i;
                Bcnt += 1;
            }
            else
            {
                teamA[Acnt] = i;
                Acnt += 1;
            }
        }
        //각 팀의 능력치 구하기
        int hapA={0}, hapB = { 0 };
        for (int i = 0; i < N / 2; ++i)
        {
            for (int j = i+1; j < N / 2; ++j)
            {
                hapA += arr[teamA[i]][teamA[j]] + arr[teamA[j]][teamA[i]];
                hapB += arr[teamB[i]][teamB[j]] + arr[teamB[j]][teamB[i]];
            }
        }

        // 각 팀의 능력치 절대값 뺴서 최소값 갱신
        _min = min(_min, abs(hapA - hapB));
        return;
    }
    // 선수 번호 뽑기
    for (int i = 0; i < N; ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;
            cnt += 1;
            back(cnt, i);
            visited[i] = false;
            cnt -= 1;
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    cin >> N;

    // 표 채우기 N개, 인덱스: 0 ~ N-1 까지
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> num;
            arr[i][j] = num;
        }
    }
    
    back(0,0); // 몇명, 선수 번호
    
    cout << _min;

    return 0;
}