#include <iostream>
#include <vector>
#include<queue>
#include <string.h>
#include <algorithm>
using namespace std;

int N, M;
string str;
vector<vector<bool>> map; 
vector<vector<bool>> discovered; //���ѷ��� ������ ����
queue<pair<int,int>> q; //����ý���
vector<vector<pair<int, int>>> parents; // ���� �ε����� �ش��ϴ� ��ǥ�� pair<int,int>�� ã�Ҵٴ� �ǹ�
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

    //ù° �ٿ� �� ���� N, M(2 �� N, M �� 100)�� �־�����. 
    cin >> N >> M;

    map.resize(N);
    discovered.resize(N);
    parents.resize(N, vector<pair<int, int>>(M, { -1,-1 }));

    // ���� N���� �ٿ��� M���� ������ �̷ΰ� �־�����. ������ ������ �پ �Է����� �־�����.
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        for (int j = 0; j < str.length(); ++j)
        {
            if(str[j]=='0') //���ڿ��� �޾����Ƿ� ���ڿ� '' �ٿ���
                map[i].push_back(0);
            else
                map[i].push_back(1);

            discovered[i].push_back(false);
        }
    }

    //Ž��
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
    Reverse({ N - 1 ,M - 1 }); //���������� ���������� �ѹ� �� Ž���ϰ�
                               //�������������� �߰��� �������� �Ųٷ� Ž���ϸ鼭 cnt++ => �ִܰŸ� 
    



    cout << cnt;

    return 0;
}