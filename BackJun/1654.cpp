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
	//����
	sort(v.begin(), v.end());
	low = 1;
	high = v[K - 1];

	while (low <= high)
	{
		mid = (low + high) / 2; //��ȣ ����
		calculate(mid);

		if (cnt >= N) 
		{
			//�� �� ���̷ε� 11���� ���� �� �ִ��� �˻� ��
			// ���� ������ �� �� ���̷� ���� �� �ִ��� �����ؾ��ϹǷ�
			// cnt == N�� �����Ѵٰ� �ٷ� Ż���ϸ� �ȵ�
			_max = max(_max, mid);
			low = mid + 1; //�ڸ��� ���̸� ���δ�
		}
		else //��ǥ�� ���� ������
		{
			high = mid - 1; //�ڸ��� ���̸� �����
		}
	}
	cout << _max << "\n";
	return 0;
}