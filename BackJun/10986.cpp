#define EASYINPUT ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <vector>


using namespace std;

/* 나머지 합, 누적 합, 수학*/

vector<long> v;
vector<long> re;

int main(void)
{
	EASYINPUT;

	int N; 
	int M; 
	long long res = { 0 };
	cin >> N >> M;

	v.resize(N+1, 0); // v[0] = 0
	re.resize(M, 0);

	for (int i = 1; i <= N; ++i)
	{
		int num;
		cin >> num; 
		v[i]= v[i - 1] + num; //누적합
	}

	for (int i = 1; i <= N; ++i)
	{
		int remain = v[i] % M;
		if (remain == 0)
		{
			res++; //누적합의 나머지 == 0 => 이미 나누어 떨어지는 경우
		}
		re[remain]++; //나머지가 같은 구간합i의 개수
	}

	for (int i = 0; i < M; ++i)
	{
		if (re[i] > 1)
		{
			res = res + ((re[i] * (re[i] - 1)) / 2);
		}
	}

	cout << res << "\n";
	return 0;
}

