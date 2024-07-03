#include <iostream>
using namespace std;

long long int factorial(int n) {
	if (n == 0) return 1;
	return n * factorial(n-1);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	cout << factorial(N);

	return 0;
}
