#include <stdio.h>
#include <algorithm>
using namespace std;

int dp[100005];

int main() {
	int n, k, w, v;

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &w, &v);

		for (int j = k; j >= w; j--)
			dp[j] = max(dp[j - w] + v, dp[j]);
	}

	printf("%d", dp[k]);

	return 0;
}