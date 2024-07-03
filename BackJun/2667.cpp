#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
//DFS , 단지 나누기
vector<vector<int>> graph;
vector<vector<bool>> visited;
vector<int> cntlist;

int ud[4] = { -1,0,1,0 };
int lr[4] = { 0,1,0,-1 };
int N(0), cnt(0);

void Dfs(int i, int j)
{
    for (int num = 0; num < 4; ++num)
    {
        int first = i + ud[num];
        int second = j + lr[num];

        if (first < 0 || first >= N || second < 0 || second >= N) continue;

        if (graph[first][second] == 1 && visited[first][second] == false)
        {
            visited[first][second] = true;
            cnt+=1;
            Dfs(first, second);
        }
    }
}


int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

   // char cdata[25];
    string data;
    cin >> N;

    graph.resize(N);
    visited.resize(N);

    //그래프 그리기
    for (int i = 0; i < N; ++i)
    {
        cin >> data;

/* char 배열로 하면 틀림, 왜..
        for (int j = 0; j < strlen(cdata); ++j)
        {
            int z = (int(cdata[j]) - 48);
            graph[i][j] =z;
            visited[i][j] = false;
        }
*/

        for (int j = 0; j < data.length(); ++j)
        {
            int z = (int(data[j]) - 48);
            graph[i].push_back(z);
            visited[i].push_back(false);
        }
    }


    for (int i = 0; i < N; ++i) 
    {
        for (int j = 0; j < N; ++j)
        {
            if (graph[i][j] == 1 && visited[i][j] == false) //길이 있는지, 방문했었는지 체크
            {
                visited[i][j] = true;
                cnt = 1;
                Dfs(i, j);
                cntlist.push_back(cnt);
            }
        }
    }
   


    ////총 단지 수, 오름차순
    sort(cntlist.begin(), cntlist.end());
    cout << cntlist.size() << '\n';

    for (auto& it : cntlist)
    {
        cout << it << '\n';
    }
    return 0;
}