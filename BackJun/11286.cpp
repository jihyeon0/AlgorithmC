#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

//우선순위 큐  절대값
// 비교함수정의

struct compare
{
	bool operator()(int num1, int num2)
	{
		int absnum1 = abs(num1);
		int absnum2 = abs(num2);

		if (absnum1 == absnum2)
		{
			return num1 > num2;
		}
		else
		{
			return absnum1 > absnum2;
		}
	}
};

priority_queue<int, vector<int>, compare> q;
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