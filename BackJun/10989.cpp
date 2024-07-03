#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N{ 0 }, M{ 0 };
	cin >> N;

	int arr[10001]{ 0, };

	for (int i = 0; i < N; ++i)
	{
		cin >> M;
		arr[M] += 1;
	}

	for (int i = 1; i < 10001; ++i)
	{
		for (int j = 0; j < arr[i]; ++j)
		{
			cout << i << '\n';
		}
	}
	return 0;
}