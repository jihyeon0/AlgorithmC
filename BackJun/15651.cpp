#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
// 백트래킹

int N, M, cnt{ 0 };

int v[7] = { 0, };
//bool visited[7] = { false, };

vector<int> numbers;

void recursion(int cnt)
{
	//탈출 조건
	if (M == cnt) // 다 골랐으면 수열 출력하고 리턴
	{
		for (int i = 0; i < M; ++i)
		{
			cout << v[i] << " ";
		}
		cout << '\n';
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

	/*
	자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
	1부터 N까지 자연수 중에서 M개를 고른 수열
	같은 수를 여러 번 골라도 된다..
	*/

	for (int i = 0; i < N; ++i)
	{
		numbers.push_back(i + 1);
	}
	recursion(0);


	return 0;
}