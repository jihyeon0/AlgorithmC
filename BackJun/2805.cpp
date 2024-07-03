#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> v;
int N, M;
long long h;
long long mid, result;
long long _max;
long long low;
long long high;

void calculate(long long mid)
{
	result = 0;
	for (int i = 0; i < N; ++i)
	{
		if (v[i] - mid > 0)
			result += v[i] - mid;
	}
}

int main()
{

	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >>M;
	
	v.reserve(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> h;
		v.push_back(h); //나무 수만큼 높이 입력
	}
	//정렬
	sort(v.begin(), v.end());
	low = 0;
	high = v[N - 1];
	
	while (low <= high)
	{
		mid = (low + high) / 2;
		calculate(mid);

		if (result == M)
		{
			//최소한의 나무가 목표이므로 목표차와 같다면 바로 탈출
			_max = mid;
			break;
		}
		else if (result < M) //목표량 보다 적으면
		{
			high = mid-1; //자르는 높이를 낮춘다
		}
		else if (result > M) //목표량 보다 많으면
		{
			_max = mid; 
			//_max = mid 필요한이유
			//4 8
			//1 3 3 10
			// mid == 3, max ==2
			/*
				mid는 탐색하면서 탈출조건을 만족할 때까지 변경됨
				목표량 초과 달성해도 탈출조건을 만족하지 않았으면
				low,high,mid가 계속 변경되면서 루프 => 탈출시 mid가 꼭 정답이 아님
				미달->미달->초과->미달-> low>high 탈출
				때문에 목표량 초과 달성 또는 동일할때 max = mid로 저장해야함
			*/
			low = mid +1; //자르는 높이를 높인다
		}
	}
	cout << _max << "\n";
	return 0;
}