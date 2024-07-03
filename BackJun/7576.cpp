#include <iostream>
#include<queue>
using namespace std;

int box[1001][1001]{ -1, };
bool visited[1001][1001]{ false, };
queue<pair<int, int>> q; //인덱스
int dir_ud[4] = { -1,0,1,0 };
int dir_rl[4] = { 0,1,0,-1 };
int cnt{ 0 };
int M, N;
int good{ 0 }, blank{ 0 };
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    //입력
    cin >> M >> N;

    // 그래프 그리기, 세로 가로 인덱스 잘 생각하기
    for (int i = 0; i < N; ++i) 
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> box[i][j];
            if (box[i][j] == 1)
            {
                q.push(make_pair(i, j));
                ++good;
            }
            if (box[i][j] == -1)
            {
                visited[i][j] = true;  // 빈 칸인 곳 탐색x
                ++blank;
            }
        }
    }

    if (M * N == good + blank) //처음부터 모두 익은 상태
    {
        cout << 0;
        return 0;
    }
    // 1 : 익음 , 0 : 안 익음 , -1 : 빈 칸

    while (!q.empty())
    {
        int qsize = q.size();
        for (int size = 0; size < qsize; ++size) //기존에 익었던 토마토들 탐색
        {
            pair<int, int> index = q.front(); // 세로 가로
            q.pop();
            visited[index.first][index.second] = true;
            
            for (int dir = 0; dir < 4; ++dir) //익은 토마토 기준으로 상하좌우 탐색
            {
                int nextY = index.first + dir_ud[dir];
                int nextX = index.second + dir_rl[dir];

                if (nextX <0 || nextX>=M || nextY<0 || nextY >=N)continue;
                if (box[nextY][nextX] == 0 && visited[nextY][nextX] == false) //익지 않았고 방문 하지 않았으면
                {
                    box[nextY][nextX] = 1; //마지막 토마토가 익고 탈출 하지 않으면 남은 q 마저 실행됨
                    q.push(make_pair(nextY, nextX));
                }
            }
        }
        if(q.size() != 0) //마지막 토마토가 익고 탈출 하지 않으면 남은 q 마저 실행됨의 방어조건
        {
            cnt++;
        }
    }

   
// 다 돌고 안 익은게 남은 상태
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (box[i][j] == 0)
            {
                cout << -1; 
                return 0;
            }
        }
    }
    cout << cnt;
    return 0;
}