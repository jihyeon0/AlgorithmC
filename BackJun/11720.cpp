#define EASYINPUT ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <string>
#include <string.h>
using namespace std;



int main(void)
{
	EASYINPUT;	

	int N;
	string str;

	cin >> N;
	cin >> str;

	int res = { 0 };

	for (int i = 0; i < N; ++i)
	{
		res += str[i] - '0'; //char -> int
	}
	cout << res;

	return 0;
}

