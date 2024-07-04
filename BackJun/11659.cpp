#define EASYINPUT ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>

using namespace std;

/* 구간 합 구하기, 단순 수학*/


int main(void)
{
	EASYINPUT;

	int N; //수 개수
	int M; // 합 구할 횟수
	
	int sum[100001] = { 0, };

	cin >> N >>M;

	for (int i = 1; i <= N; ++i)
	{
		int num;
		cin >> num;
		sum[i] = sum[i - 1] + num; //sum[1] = sum[0](0)+num, sum[2] = sum[1]+num
	}

	for (int a = 0; a < M; ++a)
	{
		int i, j; //구간
		cin >> i >>j;
		cout << sum[j] - sum[i - 1] << "\n";
	}

	return 0;
}

