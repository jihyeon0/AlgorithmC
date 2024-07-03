#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

//map �����̳� Ȱ��
map<int, int> mcnt;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int N, Nnum, M, Mnum;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> Nnum;
		if (mcnt.find(Nnum) == mcnt.end()) //�ߺ� �ƴ϶��
		{
			mcnt.insert({ Nnum ,1 });
		}
		else //�ߺ�o -> map�� key�� ã�� value ++1
		{
			mcnt[Nnum]++;
		}
	}

	cin >> M;
	//�̺�Ž��
	for (int i = 0; i < M; ++i)
	{
		cin >> Mnum;
		if (mcnt.find(Mnum) == mcnt.end()) // ã�� ���ڰ� ���ٸ�
			cout << "0 ";
		else
		{
			cout << mcnt[Mnum]<<" ";
		}
	}
	return 0;
}