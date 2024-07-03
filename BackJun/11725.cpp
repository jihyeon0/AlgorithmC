#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, from, to;
vector<vector<int>> v;
vector<int> parent;

void dfs(int _from) // [1][0] ->6, [6][0]->1, [1][1]->4...
{
	for (int i = 0; i < v[_from].size(); ++i) // _from 번과 연결된 수만큼만 돈다
	{
		int next = v[_from][i]; // 1번의 0번째원소 == 6번
		if (parent[next] == 0) //방문한 적 없다면, 6번의 부모가 정해지지 않았다면
		{
			parent[next] = _from;
			dfs(next);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	v.resize(N+1); //0~7
	parent.resize(N + 1,0);
	
	// N x N 사이즈 표로 만들면 메모리 초과
	// 길이 있는 수만큼만 추가
	 
	//그래프 그리기
	for (int i = 0; i < N-1; ++i)
	{
		cin >> from >> to;
		v[from].push_back(to); 
		v[to].push_back(from);
	}
	
	dfs(1);

	for (int i = 2; i < N + 1; ++i)
	{
		cout << parent[i] << '\n';
	}

	return 0;
}