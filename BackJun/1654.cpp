#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<long long> v;
int K, N;
long long len;
long long low, mid, high, _max, cnt;

void calculate(long long mid)
{
	cnt = 0;
	for (int i = 0; i < K; ++i)
	{
		if (v[i] / mid > 0)
			cnt += v[i] / mid;
	}
}

int main()
{

	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> K >> N;

	v.reserve(K);

	for (int i = 0; i < K; ++i)
	{
		cin >> len;
		v.push_back(len);
	}
	//정렬
	sort(v.begin(), v.end());
	low = 1;
	high = v[K - 1];

	while (low <= high)
	{
		mid = (low + high) / 2; //괄호 주의
		calculate(mid);

		if (cnt >= N) 
		{
			//더 긴 길이로도 11개를 만들 수 있는지 검사 등
			// 같은 개수를 더 긴 길이로 만들 수 있는지 생각해야하므로
			// cnt == N을 충족한다고 바로 탈출하면 안됨
			_max = max(_max, mid);
			low = mid + 1; //자르는 높이를 높인다
		}
		else //목표량 보다 적으면
		{
			high = mid - 1; //자르는 높이를 낮춘다
		}
	}
	cout << _max << "\n";
	return 0;
}