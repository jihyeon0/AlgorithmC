#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 //�̺�Ž�� �ȿ� ����Ž�������Ƿ� ->O(NlogN)
int N; //���� ����
int C; //������ ����
vector<int> v;
int pos, _max;
int _left, _mid, _right;

int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N>>C;
	v.reserve(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> pos;
		v.push_back(pos);
	}
	//����
	sort (v.begin(), v.end());

	//�� ������ ��ġ
	_left = 1; // �Ÿ�!!, pos���� �ƴ�!! ���� ȥ��
	_right = v[N - 1] - v[0]; 
	_mid = (_left + _right) / 2; //�߰� �Ÿ� 
	//mid�Ÿ� ������ �߶����� �����ϴ� ��
	
	
	//��ġ ���� "�Ÿ�"�� �̺�Ž���϶�
	
	while (_left <= _right)
	{
		int cnt = 1; // v[0]�� ������ ��ġ, ��ġ�� ������ ����
		int visited = 0;
		_mid = (_left + _right) / 2;
		for (int i = 1; i < N; ++i)
		{
			if (v[i] - v[visited] >= _mid) // �˻� ��ġ - ��ġ�� ��ġ >= ��ġ����
			{
				cnt += 1; //��ġ�ϰ�
				visited = i; // ��ġ�� ��ġ�� ����
			}
		}
		if (cnt >= C) // ��ġ ������ �����ߴٸ� �� �� �Ÿ��ε� ��������
		{
			_max = max(_max,_mid);
			_left = _mid + 1;
		}
		else // ��ġ������ �������� ���ߴٸ�
		{
			_right = _mid - 1;
		}
	}
	//���� ���� ���� ���� �� �Ÿ� ���ϱ�
	
	cout << _max;
	return 0;
}