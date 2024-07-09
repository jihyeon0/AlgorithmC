#define EASYINPUT ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <vector>


using namespace std;

/* ������ ��, ���� ��, ����*/

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
		v[i]= v[i - 1] + num; //������
	}

	for (int i = 1; i <= N; ++i)
	{
		int remain = v[i] % M;
		if (remain == 0)
		{
			res++; //�������� ������ == 0 => �̹� ������ �������� ���
		}
		re[remain]++; //�������� ���� ������i�� ����
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

