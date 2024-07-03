#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
// ��Ʈ��ŷ

int N, M, cnt{ 0 };

int v[7] = { 0, };
//bool visited[7] = { false, };

vector<int> numbers;

void recursion(int cnt)
{
	//Ż�� ����
	if (M == cnt) // �� ������� ���� ����ϰ� ����
	{
		for (int i = 0; i < M; ++i)
		{
			cout << v[i] << " ";
		}
		cout << '\n';
	}
	else
	{
		for (auto& it : numbers)
		{
				v[cnt] = numbers[it - 1];
				recursion(cnt + 1);
		}

	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;

	/*
	�ڿ��� N�� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
	1���� N���� �ڿ��� �߿��� M���� �� ����
	���� ���� ���� �� ��� �ȴ�..
	*/

	for (int i = 0; i < N; ++i)
	{
		numbers.push_back(i + 1);
	}
	recursion(0);


	return 0;
}