#include <iostream>
#include<queue>
#include <algorithm>
#include <functional>
using namespace std;

//���ͽ�Ʈ��, ������->��� ���� �ִܰŸ�, ����ġ ����, �켱����ť

typedef struct _vertex
{
    _vertex(int _cost, int _vertex) : cost(_cost), vertex(_vertex) {}

    bool operator<(const _vertex& other) const
    {
        return cost < other.cost;
    }
    bool operator>(const _vertex& other) const
    {
        return cost > other.cost;
    }

    int cost;
    int vertex;

}_vertex;

vector<vector<int>> g; // �ε��� == ����, int == ����ġ
priority_queue<_vertex, vector<_vertex>, greater<_vertex>> pq; //�ε���, ����ġ

int V, E, K, u, v, w;
vector<int> best; //���������� �ε��� ��ȣ�� �������� ���� ����Ʈ ���

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //�Է�
    cin >> V >> E;//����, ���� ��
    cin >> K; //������

    g.resize(V+1, vector<int>(V+1 , -1));
    best.resize(V+1,INT32_MAX);
    //�׷��� �׸���
    for (int i = 0; i < E; ++i)
    {
        cin >> u >> v >> w; //u->v ����ġw
        g[u][v] = w;
    }

    pq.push(_vertex(0,K)); //���� ������ �־���
    best[K] = 0;

    while (!pq.empty())
    {
        _vertex top = pq.top();
        pq.pop();

        // �Ϲ�bfs�� �ٸ���
        // best�� ����� ���� ���ؼ� ����
        int cost = top.cost;
        int vertex = top.vertex;
        if (best[vertex] < cost) continue;

        for (int i = 1; i < V+1; ++i)
        {
            if (g[vertex][i] == -1) continue; //���� ���� ���

            //���� �������� ����� ���ϰ� best�� ���ؼ� ����
            //����Ʈ�� �ƴ� ���
            int nextcost = best[vertex] + g[vertex][i];
            if (nextcost >= best[i]) continue;

            //����Ʈ�� ���
            if (nextcost < best[i])
            {
                //�ӽ� ����Ʈ�� ����-> ��¥ ����Ʈ���� ���� ��
                best[i] = nextcost;
                //���������� ����Ʈ ����
                pq.push(_vertex{ nextcost, i });
            }

        }
    }

    for (int i = 1; i < best.size(); ++i)
    {
        if (i == K)
        {
            cout << 0 << '\n';
        }
        else if (best[i] == INT32_MAX)
        {
            cout << "INF" << '\n';
        }
        else
        {
            cout << best[i] << '\n';
        }
    }
    return 0;
}