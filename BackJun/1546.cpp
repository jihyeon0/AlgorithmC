#define EASYINPUT ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>

using namespace std;

/*
* ��� ���ϱ�, �ܼ� ����*/


int main(void)
{
	EASYINPUT;

	int N; //���� ����
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

	/*ù��° Ǯ�̰������� �ۼ�(���ʿ�),��� �̿��ϹǷ� ���ո� �ʿ�
	for (int i = 0; i < N; ++i)
	{
		sum += arr[i] / M * 100;
	}*/

	cout << sum / M * 100 /N;

	return 0;
}

