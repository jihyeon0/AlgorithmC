#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
// vector�� ��尴ü ��Ƽ� ���
// Ʈ�� ����, ����, ���� ����, ��ͻ��
// char�� ���ĺ��� int�� ��ȯ�Ͽ� �������� ���

struct Node
{
	char left;
	char right;
};

int N;
vector<Node>v(26);

//�湮üũ
void front(int start) // �ο޿� ABDCEFG
{
	int vecindex = start - 65;

	cout << (char)start; // �θ� ���

	if (v[vecindex].left != '.') //�����ڽ��������� ����
	{
		int next = (int)v[vecindex].left;
		front(next);
	}
	if (v[vecindex].right != '.') //�������ڽ��������� ����
	{
		int right = (int)v[vecindex].right;
		front(right);
	}
}

void mid(int start) // �޺ο� DBAECFG
{
	//�����ڽ�Ž��
	// ��� -> ���� �ڽ� ���ٸ� ����ϰ� ����
	//���ƿͼ� ���
	//�����ڽ� Ž��
	//�ִٸ� ���ڽ� Ž��

	int vecindex = start - 65;
	
	if (v[vecindex].left != '.') //�����ڽ��������� ����
	{
		int next = (int)v[vecindex].left;
		mid(next);
	}
	// ���̻� ���� �ڽ��� ���� �� �������ͼ� �θ� ���
	cout << (char)start;

	if (v[vecindex].right != '.') //�����ڽ����ִٸ�
	{
		int next = (int)v[vecindex].right;
		mid(next); // �����ڽ��� ���ʺ��� Ž��
	}
}

void back(int start) // �޿��� DBEGFCA
{
	int vecindex = start - 65;

	if (v[vecindex].left != '.') //�����ڽ��������� ����
	{
		int next = (int)v[vecindex].left;
		back(next);
	}

	if (v[vecindex].right != '.') //�����ڽ����ִٸ�
	{
		int next = (int)v[vecindex].right;
		back(next); // �����ڽ��� ���ʺ��� Ž��
	}

	// ���̻� ���� �ڽ��� ���� �� �������ͼ� �θ� ���
	cout << (char)start;

}


int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	char _value, _left, _right;

	for (int i = 0; i < N; i++)
	{
		cin >> _value >> _left >> _right;
		v[(int)_value - 65].left = _left;
		v[(int)_value - 65].right = _right;
	}
	
	front((int)'A'); 
	cout << '\n';
	mid((int)'A');
	cout << '\n';
	back((int)'A');

	return 0;
}