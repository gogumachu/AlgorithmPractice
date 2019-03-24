/*bfs Ǯ��
�޸𸮰� �ʹ� ���� ���� 2968k
-->dp�� Ǫ�� ��������غ����ҵ�


*/
#include<iostream>
#include<queue>
using namespace std;

bool visited[1001][1001]; //��ũ�� ����

int ans;
struct info
{
	int screen;
	int clip;
};
int S;

void bfs();
int main()
{
	ans = 2;
	scanf("%d",&S);
	bfs();
	printf("%d", ans);

}

void bfs()
{
	if (S == 2) return;
	queue<info> q;
	int s, c, t,size;
	q.push({2,1});
	visited[2][1] = true;

	while (!q.empty())
	{
		size = q.size();
		for (int i = 0; i < size; i++)
		{
			s = q.front().screen;
			c = q.front().clip;
			q.pop();
			if (s == S) return;
			//1.ȭ�鿡 �ִ� �̸�Ƽ�� ��� �����ؼ� Ŭ�����忡 ����
			if (s != c && visited[s][s] == false)
			{
				visited[s][s] = true;
				q.push({ s,s });
			}
			//2.Ŭ�����忡 �ִ� �̸�Ƽ�� ȭ�鿡 �ٿ��ֱ�
			if (s+c<=1000 && visited[s + c][c] == false)
			{
				visited[s + c][c] = true;
				q.push({ s + c,c });
			}
			//3.ȭ�鿡 �ִ� �̸�Ƽ�� �� �ϳ� ����
			if (s - 1 > 1 && visited[s - 1][c] == false)
			{
				visited[s - 1][c] = true;
				q.push({ s - 1,c });
			}
		}
		ans++;
	}
}