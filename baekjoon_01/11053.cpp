
#include<iostream>
#include <algorithm>
using namespace std;

int N;//1~1000
int arr[1000];
int dp[1000];
int L[4] = {1,2,4,0};
inline int func_max(int a, int b) {
	return a > b ? a : b;
}
void normal_dp(); //o(n^2) 퓰이
void use_lower_bound(); //o(nlogn) lower_bound를 이용한 풀이 https://seungkwan.tistory.com/8 참고
int main() {
	scanf("%d", &N);
	
	use_lower_bound();
	//normal_dp();
}

void use_lower_bound()
{
	int len = 0;
	L[0] = 0;
	for (int i = 0; i < N; i++)
	{
		int cur = 0;
		scanf("%d", &cur);
		auto pos = lower_bound(L, L + len, cur);//iterator 반환. 만족하는 요소 없으면 last를 반환
		*pos = cur; //cur이 들어가야할 index 에 넣어준다.
		if (pos == L + len)//cur이 L의 마지막 원소보다 크다면 L의 길이가 늘어난다.
			len++;
	}
	printf("%d", len);
}

void normal_dp()
{
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	int max = 1;
	dp[0] = 1;
	for (int i = 1; i < N; ++i)
	{
		//dp[i] = 
		int dp_max = 0;
		for (int j = 0; j < i; ++j)
		{
			if (arr[j] < arr[i] && dp[j] > dp_max)
			{
				dp_max = dp[j]; //i 보다 원소값은 작지만 dp값은 제일 큰 값을 저장
			}
		}
		dp[i] = dp_max + 1;
		max = func_max(dp[i], max);
	}
	printf("%d", max);
}