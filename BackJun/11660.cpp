#define EASYINPUT ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>


using namespace std;

/* ���� �� ���ϱ�,  2D prefix sum, ���̳��� ���α׷���
x1, y1, x2, y2 �̿��ؼ� ������ ����, ���ؾ��� ���� ���ϴ� ��
�׷��� ����� �ʴ��� ��ȿ�˻� ���ص� �ǵ��� x,y 0�� �ε����� ����ΰ� ������*/

int arr[1025][1025] = { 0 };
int sum[1025][1025] = { 0 };

int main(void)
{
	EASYINPUT;

	int N; // ǥ ũ��
	int M; //���� ���ؾ� �ϴ� Ƚ��
	int x1, y1, x2, y2;

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> arr[i][j];
			
			//sumä���
			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j];
		}
	}

	for (int i = 0; i < M; ++i)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		//������ ���ϱ�
		long long res = sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
		cout << res<<"\n";
	}

	return 0;
}

