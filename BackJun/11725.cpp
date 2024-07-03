#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, from, to;
vector<vector<int>> v;
vector<int> parent;

void dfs(int _from) // [1][0] ->6, [6][0]->1, [1][1]->4...
{
	for (int i = 0; i < v[_from].size(); ++i) // _from ���� ����� ����ŭ�� ����
	{
		int next = v[_from][i]; // 1���� 0��°���� == 6��
		if (parent[next] == 0) //�湮�� �� ���ٸ�, 6���� �θ� �������� �ʾҴٸ�
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
	
	// N x N ������ ǥ�� ����� �޸� �ʰ�
	// ���� �ִ� ����ŭ�� �߰�
	 
	//�׷��� �׸���
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