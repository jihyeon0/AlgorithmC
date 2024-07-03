#include <iostream>
#include<queue>
#include <algorithm>
#include <functional>
using namespace std;

//다익스트라, 시작점->모든 정점 최단거리, 가중치 적용, 우선순위큐

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

vector<vector<int>> g; // 인덱스 == 정점, int == 가중치
priority_queue<_vertex, vector<_vertex>, greater<_vertex>> pq; //인덱스, 가중치

int V, E, K, u, v, w;
vector<int> best; //시작점부터 인덱스 번호의 정점까지 가는 베스트 비용

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //입력
    cin >> V >> E;//정점, 간선 수
    cin >> K; //시작점

    g.resize(V+1, vector<int>(V+1 , -1));
    best.resize(V+1,INT32_MAX);
    //그래프 그리기
    for (int i = 0; i < E; ++i)
    {
        cin >> u >> v >> w; //u->v 가중치w
        g[u][v] = w;
    }

    pq.push(_vertex(0,K)); //비용과 시작점 넣어줌
    best[K] = 0;

    while (!pq.empty())
    {
        _vertex top = pq.top();
        pq.pop();

        // 일반bfs와 다른점
        // best에 저장된 비용과 비교해서 갱신
        int cost = top.cost;
        int vertex = top.vertex;
        if (best[vertex] < cost) continue;

        for (int i = 1; i < V+1; ++i)
        {
            if (g[vertex][i] == -1) continue; //길이 없는 경우

            //다음 정점까지 비용을 구하고 best와 비교해서 갱신
            //베스트가 아닌 경우
            int nextcost = best[vertex] + g[vertex][i];
            if (nextcost >= best[i]) continue;

            //베스트인 경우
            if (nextcost < best[i])
            {
                //임시 베스트를 보관-> 진짜 베스트인지 아직 모름
                best[i] = nextcost;
                //실질적으로 베스트 결정
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