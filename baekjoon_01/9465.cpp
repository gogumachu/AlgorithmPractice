/*
dp를 이용해서 풀음

dp[0][i] 에는 i 줄까지 들어갈수 있는 최대값을 저장한다.

자신의 대각선 방향 or 그 대각선 옆에 있는 값중 큰 값 + 현재 자신의 값 이 최대값이다.

(대각선방향으로만 선택할수 있으므로)

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