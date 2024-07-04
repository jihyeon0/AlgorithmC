#define EASYINPUT ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>

using namespace std;

/*
* 평균 구하기, 단순 수학*/


int main(void)
{
	EASYINPUT;

	int N; //과목 개수
	float arr[1001] = { 0.f ,};
	int M = { -1 };
	float sum = { 0.f };
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
		sum += arr[i];
		if (M < arr[i])
			M = arr[i];
	}

	/*첫번째 풀이과정에서 작성(불필요),평균 이용하므로 총합만 필요
	for (int i = 0; i < N; ++i)
	{
		sum += arr[i] / M * 100;
	}*/

	cout << sum / M * 100 /N;

	return 0;
}

