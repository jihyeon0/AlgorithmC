#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string N;
	cin >> N;

	sort(N.begin(), N.end(), greater<>());

	for (const auto& i : N)
	{
		cout << i;
	}
	return 0;
}