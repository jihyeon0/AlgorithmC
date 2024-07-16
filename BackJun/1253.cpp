#define EASYINPUT ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
	투포인터, a + b = c, 
	1. 배열 안에 c가 있는지 체크
	2. 수의 범위가 음수, 0, 양수 이므로
	=> 0+3=3 처럼 자기자신을 포함하는지 체크
*/
int main(void)
{
	EASYINPUT;


	int N;
	vector<int> v;
	int cnt = 0;

	cin >> N;
	v.resize(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int startindex = 0;
	int endindex = N - 1;

	for(int i=0; i<N; ++i)
	{
		startindex = 0;
		endindex = N - 1;

		while(startindex < endindex)
		{
			if (v[startindex] + v[endindex] < v[i])
			{
				startindex++;
			}
			else if (v[startindex] + v[endindex] > v[i])
			{
				endindex--;
			}
			else //  a + b = c 일 때
			{
				if (startindex != i && endindex != i) //a, b 둘 다 c가 아니다
				{
					cnt++;
					break;
				}
				else if (startindex == i) // 둘 중 하나가 c인경우
				{
					startindex++;
				}
				else if (endindex == i)
				{
					endindex--;
				}
			}
		}
	}

	cout << cnt;

	return 0;
}