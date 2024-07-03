#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

//map 컨테이너 활용
map<int, int> mcnt;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int N, Nnum, M, Mnum;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> Nnum;
		if (mcnt.find(Nnum) == mcnt.end()) //중복 아니라면
		{
			mcnt.insert({ Nnum ,1 });
		}
		else //중복o -> map에 key로 찾고 value ++1
		{
			mcnt[Nnum]++;
		}
	}

	cin >> M;
	//이분탐색
	for (int i = 0; i < M; ++i)
	{
		cin >> Mnum;
		if (mcnt.find(Mnum) == mcnt.end()) // 찾는 숫자가 없다면
			cout << "0 ";
		else
		{
			cout << mcnt[Mnum]<<" ";
		}
	}
	return 0;
}