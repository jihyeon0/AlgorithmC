#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, num;
	int value{ 0 };
	queue<int> q;

	cin >> N;

	while (N--)
	{
		++value;
		q.push(value);
	}
	
	while (q.size() != 1)
	{
		q.pop();
		num = q.front();
		q.pop();
		q.push(num);
	}
	cout << q.front();

	return 0;
}