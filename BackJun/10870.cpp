#include <iostream>
using namespace std;



int Fibonacci(int N)
{
	if (N == 0) return 0;
	if (N == 1) return 1;
	return  Fibonacci(N-1) + Fibonacci(N - 2);
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	cout << Fibonacci(N);

	return 0;
}
