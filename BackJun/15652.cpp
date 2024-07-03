#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
// 백트래킹

int N, M, cnt{ 0 };

int v[8] = { 0, };
//bool visited[8] = { false, };

vector<int> numbers;

void recursion(int cnt)
{
	//탈출 조건
	if (M == cnt) // 다 골랐으면 수열 출력하고 리턴
	{
		int cnt2 = 0;

		for (int i = 0; i < M; ++i)
		{
			if (i != 0 && v[i - 1] <= v[i])
			{
				cnt2 += 1;
			}
		}
		if (M - 1 == cnt2)
		{
			for (int i = 0; i < M; ++i)
			{
				cout << v[i] << " ";
			}
			cout << '\n';
			cnt2 = 0;
		}
	}
	else
	{
		for (auto& it : numbers)
		{
			v[cnt] = numbers[it - 1];
			recursion(cnt + 1);
		}

	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;


	for (int i = 0; i < N; ++i)
	{
		numbers.push_back(i + 1);
	}
	recursion(0);


	return 0;
}