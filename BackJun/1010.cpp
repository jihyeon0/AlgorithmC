#include<stdio.h>

//다리 만들기 M개 중에 N개
int main(void)
{
	int k, n, m, dam;
	scanf("%d", &k);
	for (int z = 0; z < k; z++)
	{
		dam = 1;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			dam *= m - i;
			dam /= 1 + i;
		}
		printf("%d\n", dam);
	}
}