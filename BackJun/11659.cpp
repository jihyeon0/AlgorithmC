#define EASYINPUT ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>

using namespace std;

/* ���� �� ���ϱ�, �ܼ� ����*/


int main(void)
{
	EASYINPUT;

	int N; //�� ����
	int M; // �� ���� Ƚ��
	
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
		int i, j; //����
		cin >> i >>j;
		cout << sum[j] - sum[i - 1] << "\n";
	}

	return 0;
}

