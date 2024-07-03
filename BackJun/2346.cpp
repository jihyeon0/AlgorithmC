#include <iostream>
#include <deque>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	deque<pair<int,int>> deq;
	int N, value{ 0 }, index{1};
	cin >> N;

	while (N--)
	{
		cin >> value;
		deq.push_back({index,value});
		index++;
	}

	while (true)
	{
		cout << (deq.front().first) << " ";
		int cnt = deq.front().second;
		deq.pop_front();
		if (deq.empty()) break;
		if (cnt > 0)
		{
			for (int i = 0; i < cnt-1; ++i)
			{
				deq.push_back(deq.front());
				deq.pop_front();
			}
		}
		else
		{
			for (int i = cnt; i < 0; ++i)
			{
				deq.push_front(deq.back());
				deq.pop_back();
			}
		}


	}
	return 0;
}