#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory.h>
using namespace std;
//DFS , 단지 나누기
//각 테스트 케이스에 대해 필요한 "최소"의 배추흰지렁이 마리 수를 출력한다.

int T, //케이스 개수 
    M, //가로 길이
    N, //세로 길이
    K, //배추가 심어진 위치 개수
    X,
    Y;

vector<vector<bool>> map;
vector<vector<bool>> visited;

//위,오,아,왼
int ud[4] = { -1,0,1,0 };
int rl[4] = { 0,1,0,-1 };

void Dfs(int here, int there)
{
    for (int i = 0; i < 4; ++i) //네방향으로 한번씩 dfs 재귀하면서 막힐 때까지 탐색
    {
        //탐색할 새 좌표
        int first = here + ud[i];
        int second = there + rl[i];

        if (first < 0 || first >= M || second < 0 || second >= N) continue; //표 범위를 벗어나면
        if (visited[first][second] == 0 && map[first][second] == 1)
        {
            visited[first][second] = true; // 방문처리
            Dfs(first, second);
        }


    }
}

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
     
    int res{ 0 };
   
    cin >> T;

    while (T != 0)
    {
        T--;

        cin >> M >> N >> K;

        //메모리 초기화
        res = 0;
        map.resize(M);
        visited.resize(M);

        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                map[i].push_back(0);
                visited[i].push_back(false);
            }
        }

        //그래프 그리기
        for (int i = 0; i < K; ++i)
        {
            cin >> X >> Y;
            map[X][Y] = 1;
        }

        //탐색
        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (visited[i][j] == 0 && map[i][j] == 1) // 방문한 적이 없, 길이 있을 때
                {
                    visited[i][j] = true; //방문했음
                    Dfs(i, j);
                    res++;                 //구역 표시
                }
            }
        }
        cout << res << '\n';

        map.clear();
        visited.clear();
    }
    
    return 0;
}