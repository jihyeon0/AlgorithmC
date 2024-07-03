#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
// 백트래킹
// 조합의 개수 구하기, dfs이용

int N, M;
bool visited[10001] = { false, };
int arr[10001] = { 0, }; //중복검사 후 저장벡터

void dfs(int cnt)
{
	if (cnt == M) //탈출 조건, cnt==M==2 숫자 2개 다 뽑았으면 탈출
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
		if (!visited[i]) //조건검사
		{
			visited[i] = true;
			arr[cnt] = i; 
			dfs(cnt + 1);
			visited[i] = false; // 1,2 출력 ,return 후 2 = false 처리, arr은 [1][2]..., i++하면 [1][3]
		}
	}
}

int main() {
	cin >> N >> M;
	
	dfs(0);
	
	return 0;
}