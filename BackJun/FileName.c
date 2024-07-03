#include <stdio.h>
#include <stdbool.h>
int N, M;
bool visited[100] = { false, };
int arr[100] = { 0, }; 

void recursion(int cnt)
{
	if (cnt == M) //≈ª√‚ ¡∂∞«
	{
		for (int i = 0; i < M; ++i)
		{
			printf( "%d ",arr[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= N; ++i)
	{
		if (!visited[i])
		{
			visited[i] = true;
			arr[cnt] = i;
			recursion(cnt + 1);
			visited[i] = false; 
		}
	}
}

int main() {
	scanf_s("%d", &N);
	scanf_s("%d", &M);
	recursion(0);

	return 0;
}




