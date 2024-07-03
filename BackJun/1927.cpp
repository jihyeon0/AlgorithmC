#include <iostream>
#include <queue>
using namespace std;

//우선순위 큐  최소힙
/*
		1
	2		7
  5   10
*/
priority_queue<int, vector<int>, greater<int>> q;
int N, x;

int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> x;
		if (x == 0)
		{
			if (q.empty())
			{
				cout << 0 << '\n';
			}
			else
			{
				cout << q.top() << '\n';
				q.pop();
			}
		}
		else
		{
			q.push(x);
		}
	}

	return 0;
}