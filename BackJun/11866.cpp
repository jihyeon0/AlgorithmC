#include <iostream>
#include <queue>

//큐, 요세푸스 문제
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	queue<int> q;

	for(int i=1; i<=N; ++i)
	{
		q.push(i);
	}
	cout << "<";
	while (!q.empty())
	{
		for (int i = 0; i < K - 1; ++i)
		{
			q.push(q.front());
			q.pop();
		}
		if (q.size() == 1)
		{
			cout << q.front()<<">";
			q.pop();
		}
		else
		{
			cout << q.front()<<"," << " ";
			q.pop();
		}
	}

	return 0;
}