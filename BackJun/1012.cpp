#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory.h>
using namespace std;
//DFS , ���� ������
//�� �׽�Ʈ ���̽��� ���� �ʿ��� "�ּ�"�� ������������ ���� ���� ����Ѵ�.

int T, //���̽� ���� 
    M, //���� ����
    N, //���� ����
    K, //���߰� �ɾ��� ��ġ ����
    X,
    Y;

vector<vector<bool>> map;
vector<vector<bool>> visited;

//��,��,��,��
int ud[4] = { -1,0,1,0 };
int rl[4] = { 0,1,0,-1 };

void Dfs(int here, int there)
{
    for (int i = 0; i < 4; ++i) //�׹������� �ѹ��� dfs ����ϸ鼭 ���� ������ Ž��
    {
        //Ž���� �� ��ǥ
        int first = here + ud[i];
        int second = there + rl[i];

        if (first < 0 || first >= M || second < 0 || second >= N) continue; //ǥ ������ �����
        if (visited[first][second] == 0 && map[first][second] == 1)
        {
            visited[first][second] = true; // �湮ó��
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

        //�޸� �ʱ�ȭ
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

        //�׷��� �׸���
        for (int i = 0; i < K; ++i)
        {
            cin >> X >> Y;
            map[X][Y] = 1;
        }

        //Ž��
        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (visited[i][j] == 0 && map[i][j] == 1) // �湮�� ���� ��, ���� ���� ��
                {
                    visited[i][j] = true; //�湮����
                    Dfs(i, j);
                    res++;                 //���� ǥ��
                }
            }
        }
        cout << res << '\n';

        map.clear();
        visited.clear();
    }
    
    return 0;
}