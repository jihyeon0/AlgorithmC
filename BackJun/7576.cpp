#include <iostream>
#include<queue>
using namespace std;

int box[1001][1001]{ -1, };
bool visited[1001][1001]{ false, };
queue<pair<int, int>> q; //�ε���
int dir_ud[4] = { -1,0,1,0 };
int dir_rl[4] = { 0,1,0,-1 };
int cnt{ 0 };
int M, N;
int good{ 0 }, blank{ 0 };
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    //�Է�
    cin >> M >> N;

    // �׷��� �׸���, ���� ���� �ε��� �� �����ϱ�
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
                visited[i][j] = true;  // �� ĭ�� �� Ž��x
                ++blank;
            }
        }
    }

    if (M * N == good + blank) //ó������ ��� ���� ����
    {
        cout << 0;
        return 0;
    }
    // 1 : ���� , 0 : �� ���� , -1 : �� ĭ

    while (!q.empty())
    {
        int qsize = q.size();
        for (int size = 0; size < qsize; ++size) //������ �;��� �丶��� Ž��
        {
            pair<int, int> index = q.front(); // ���� ����
            q.pop();
            visited[index.first][index.second] = true;
            
            for (int dir = 0; dir < 4; ++dir) //���� �丶�� �������� �����¿� Ž��
            {
                int nextY = index.first + dir_ud[dir];
                int nextX = index.second + dir_rl[dir];

                if (nextX <0 || nextX>=M || nextY<0 || nextY >=N)continue;
                if (box[nextY][nextX] == 0 && visited[nextY][nextX] == false) //���� �ʾҰ� �湮 ���� �ʾ�����
                {
                    box[nextY][nextX] = 1; //������ �丶�䰡 �Ͱ� Ż�� ���� ������ ���� q ���� �����
                    q.push(make_pair(nextY, nextX));
                }
            }
        }
        if(q.size() != 0) //������ �丶�䰡 �Ͱ� Ż�� ���� ������ ���� q ���� ������� �������
        {
            cnt++;
        }
    }

   
// �� ���� �� ������ ���� ����
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