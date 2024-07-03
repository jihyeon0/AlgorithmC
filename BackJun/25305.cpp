#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	
	int N{ 0 };
	int K{ 0 };
	int X{ 0 };
	cin >> N >> K;

	vector<int> num;

	for (int i = 0; i < N; ++i)
	{
		cin >> X;
		num.push_back(X);
	}

	sort(num.begin(), num.end(), greater<>());

	
	cout << num.at(K-1) << endl;
	

	return 0;
}