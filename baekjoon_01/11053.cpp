
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
void normal_dp(); //o(n^2) ǽ��
void use_lower_bound(); //o(nlogn) lower_bound�� �̿��� Ǯ�� https://seungkwan.tistory.com/8 ����
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
		auto pos = lower_bound(L, L + len, cur);//iterator ��ȯ. �����ϴ� ��� ������ last�� ��ȯ
		*pos = cur; //cur�� ������ index �� �־��ش�.
		if (pos == L + len)//cur�� L�� ������ ���Һ��� ũ�ٸ� L�� ���̰� �þ��.
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
				dp_max = dp[j]; //i ���� ���Ұ��� ������ dp���� ���� ū ���� ����
			}
		}
		dp[i] = dp_max + 1;
		max = func_max(dp[i], max);
	}
	printf("%d", max);
}