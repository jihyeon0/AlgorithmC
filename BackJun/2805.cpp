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
		v.push_back(h); //���� ����ŭ ���� �Է�
	}
	//����
	sort(v.begin(), v.end());
	low = 0;
	high = v[N - 1];
	
	while (low <= high)
	{
		mid = (low + high) / 2;
		calculate(mid);

		if (result == M)
		{
			//�ּ����� ������ ��ǥ�̹Ƿ� ��ǥ���� ���ٸ� �ٷ� Ż��
			_max = mid;
			break;
		}
		else if (result < M) //��ǥ�� ���� ������
		{
			high = mid-1; //�ڸ��� ���̸� �����
		}
		else if (result > M) //��ǥ�� ���� ������
		{
			_max = mid; 
			//_max = mid �ʿ�������
			//4 8
			//1 3 3 10
			// mid == 3, max ==2
			/*
				mid�� Ž���ϸ鼭 Ż�������� ������ ������ �����
				��ǥ�� �ʰ� �޼��ص� Ż�������� �������� �ʾ�����
				low,high,mid�� ��� ����Ǹ鼭 ���� => Ż��� mid�� �� ������ �ƴ�
				�̴�->�̴�->�ʰ�->�̴�-> low>high Ż��
				������ ��ǥ�� �ʰ� �޼� �Ǵ� �����Ҷ� max = mid�� �����ؾ���
			*/
			low = mid +1; //�ڸ��� ���̸� ���δ�
		}
	}
	cout << _max << "\n";
	return 0;
}