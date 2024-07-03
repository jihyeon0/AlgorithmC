#include <iostream>
#include <vector>
#include<queue>
#include <string.h>
#include <algorithm>
using namespace std;

int N, M;
string str;
vector<vector<bool>> map; 
vector<vector<bool>> discovered; //무한루프 방지에 쓰임
queue<pair<int,int>> q; //예약시스템
vector<vector<pair<int, int>>> parents; // 벡터 인덱스에 해당하는 좌표를 pair<int,int>가 찾았다는 의미
int cnt{ 0 };

int ud[4] = { -1,0,1,0 };
int rl[4] = { 0,1,0,-1 };

void Reverse(pair<int, int> XY)
{
    cnt++;
    if (XY.first == 0 && XY.second == 0)
    {
        return;
    }
    pair<int, int> preXY;

    preXY = parents[XY.first][XY.second];
    Reverse(preXY);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    //첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 
    cin >> N >> M;

    map.resize(N);
    discovered.resize(N);
    parents.resize(N, vector<pair<int, int>>(M, { -1,-1 }));

    // 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        for (int j = 0; j < str.length(); ++j)
        {
            if(str[j]=='0') //문자열로 받았으므로 숫자에 '' 붙여줌
                map[i].push_back(0);
            else
                map[i].push_back(1);

            discovered[i].push_back(false);
        }
    }

    //탐색
    pair<int, int> start = { 0,0 };
    parents[0][0] = start;
    discovered[start.first][start.second] = true;
    q.push(start);

    while (q.empty() == false)
    {
        pair<int, int> here = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int NextX = here.first + ud[i];
            int NextY = here.second + rl[i];

            if (NextX < 0 || NextX >= N || NextY<0|| NextY>=M) continue;
                if (map[NextX][NextY] ==1 && discovered[NextX][NextY]==false)
                { 
                    parents[NextX][NextY] = here;
                    discovered[NextX][NextY] = true;
                    q.push({ NextX ,NextY });
                }
        }

    }
    Reverse({ N - 1 ,M - 1 }); //시작점에서 도착점까지 한번 쭉 탐색하고
                               //도착점에서부터 발견한 지점으로 거꾸로 탐색하면서 cnt++ => 최단거리 
    



    cout << cnt;

    return 0;
}