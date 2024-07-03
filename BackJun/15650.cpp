#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
// 백트래킹
/*
백트래킹은 알고리즘 기법 중 하나로, 재귀적으로 문제를 하나씩 풀어나가되 
현재 재귀를 통해 확인 중인 상태(노드)가 제한 조건에 위배되는지(유망하지 않은지) 판단하고
그러한 경우 해당 상태(노드)를 제외하고 다음 단계로 나아가는 방식이다.
여기서 알아둘 것은 특정 상태(노드)를 제외한다는 것이다.
*/
int N, M, cnt{ 0 };

int v[8] = { 0, };
bool visited[8] = { false, };

vector<int> numbers;

void recursion(int cnt)
{
	//탈출 조건
	if (M == cnt) // 다 골랐으면 수열 출력하고 리턴
	{
		int cnt2 = 0;

		for (int i = 0; i < M; ++i)
		{
			if (i != 0 && v[i - 1] < v[i])
			{
				cnt2 += 1;
			}
		}
		if (M-1 == cnt2)
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
			if (visited[it-1] == false)
			{
				v[cnt] = numbers[it - 1];
				visited[it - 1] = true;
				recursion(cnt + 1);
				visited[it - 1] = false;
			}
		}
		
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N>>M;

	/*
	자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
	1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
	고른 수열은 오름차순이어야 한다.
	*/

	for (int i = 0; i < N; ++i)
	{
		numbers.push_back(i + 1);
	}
	recursion(0);


	return 0;
}