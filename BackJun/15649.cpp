#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
// ��Ʈ��ŷ
// ������ ���� ���ϱ�, dfs�̿�

int N, M;
bool visited[10001] = { false, };
int arr[10001] = { 0, }; //�ߺ��˻� �� ���庤��

void dfs(int cnt)
{
	if (cnt == M) //Ż�� ����, cnt==M==2 ���� 2�� �� �̾����� Ż��
	{
		for (int i = 0; i < M; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; ++i)
	{
		if (!visited[i]) //���ǰ˻�
		{
			visited[i] = true;
			arr[cnt] = i; 
			dfs(cnt + 1);
			visited[i] = false; // 1,2 ��� ,return �� 2 = false ó��, arr�� [1][2]..., i++�ϸ� [1][3]
		}
	}
}

int main() {
	cin >> N >> M;
	
	dfs(0);
	
	return 0;
}