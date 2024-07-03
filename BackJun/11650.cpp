#include <iostream>
#include <vector>
#include<utility>
#include <algorithm>
#include <functional>
using namespace std;

bool compare(pair<int, int> XY1, pair<int, int> XY2)
{
	if (XY1.first < XY2.first) { return true; }
	if (XY1.first == XY2.first)
	{
		if (XY1.second < XY2.second) { return true; }
		return false;
	}
	return false;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N,x,y;
	cin >> N;

	pair<int, int> XY;
	vector<pair<int,int>> arr;

	for (int i = 0; i < N; ++i)
	{
		cin >> x >> y;
		XY.first = x;
		XY.second = y;
		arr.push_back(XY);
	}

	sort(arr.begin(), arr.end(), compare);

	for (const auto& iter : arr)
	{
		cout << iter.first << ' ' << iter.second << '\n';
	}

	return 0;
}