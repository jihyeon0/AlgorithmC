#define EASYINPUT ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/* a + b = M 이 되는 조합 수, 투포인터 */

int main(void)
{
	EASYINPUT;

	int N; //재료의 개수
	int M; //갑옷을 만드는데 필요한 수
	int cnt = 0;
	vector<int> v;

	cin >> N;
	cin >> M;
	v.resize(N);
	
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int startindex = 0;
	int endindex = N-1;

	while (startindex < endindex)
	{
		if (v[startindex] + v[endindex] == M)
		{
			cnt++;
			endindex--;
			startindex++;
			//v[startindex] + v[endindex] == M 이미 짝을 이루었으므로
			// 현재 v[startindex] 또는 v[endindex] 로 나올 수 있는 경우의 수가 없음
			// 2+b =7 에서 b =5 뿐임 그러므로 두 개 다 이동
		}
		else if (v[startindex] + v[endindex] < M)
		{
			startindex++;
		}
		else
		{
			endindex--;
		}
	}

	cout << cnt;

	return 0;
}