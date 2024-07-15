#define EASYINPUT ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>

using namespace std;
/* 투포인터 */

int main(void)
{
	EASYINPUT;

	int N;
	int startindex = 1;
	int endindex = 1;
	int sum = 1;
	int cnt = 1;

	cin >> N;

	//while (endindex != N)
	//{
	//	if (sum < N)
	//	{
	//		sum = sum + endindex; endindex++; 
	//		//sum = 0 으로 시작 , endindex++ 가 뒤에 있음
	//		// 3인 경우 1+2 하고 바로 탈출해서 cnt 2가 아니라 1이됨
	//	}
	//	else if (sum > N)
	//	{
	//		sum -= startindex; startindex++;
	//	}
	//	else if (sum == N)
	//	{
	//		cnt++; 
	//		sum -= startindex; startindex++;
	//	}
	//}

	while (endindex != N)
	{
		if (sum == N)
		{
			cnt++;
			sum -= startindex; startindex++;
		}
		else if (sum < N)
		{
			endindex++;
			sum += endindex;
		}
		else
		{
			sum -= startindex; startindex++;
		}
	}

	cout << cnt;

	return 0;
}