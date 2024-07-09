#define EASYINPUT ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>


using namespace std;

/* 구간 합 구하기,  2D prefix sum, 다이나믹 프로그래밍
x1, y1, x2, y2 이용해서 빼야할 구간, 더해야할 구간 구하는 것
그래프 벗어나지 않는지 유효검사 안해도 되도록 x,y 0번 인덱스를 비워두고 시작함*/

int arr[1025][1025] = { 0 };
int sum[1025][1025] = { 0 };

int main(void)
{
	EASYINPUT;

	int N; // 표 크기
	int M; //합을 구해야 하는 횟수
	int x1, y1, x2, y2;

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> arr[i][j];
			
			//sum채우기
			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j];
		}
	}

	for (int i = 0; i < M; ++i)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		//구간합 구하기
		long long res = sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
		cout << res<<"\n";
	}

	return 0;
}

