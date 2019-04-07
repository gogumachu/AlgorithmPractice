/*
dp�� �̿��ؼ� Ǯ��

dp[0][i] ���� i �ٱ��� ���� �ִ� �ִ밪�� �����Ѵ�.

�ڽ��� �밢�� ���� or �� �밢�� ���� �ִ� ���� ū �� + ���� �ڽ��� �� �� �ִ밪�̴�.

(�밢���������θ� �����Ҽ� �����Ƿ�)

*/
#include<iostream>

int dp[2][100001];
int T, N;
inline int func_max(int a, int b) {
	return a > b ? a : b;
}
void maxSticker();
int main()
{
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &N);
		for (int j = 0; j < 2; j++)
			for (int k = 1; k <= N; k++)
				scanf("%d", &dp[j][k]);
		maxSticker();
	}
}

void maxSticker()
{
	for (int i = 2; i <= N; i++)
	{
		dp[0][i] = dp[0][i] + func_max(dp[1][i-1],dp[1][i-2]);
		dp[1][i] = dp[1][i] + func_max(dp[0][i - 1], dp[0][i - 2]);
	}

	printf("%d\n",func_max(dp[0][N],dp[1][N]));
}