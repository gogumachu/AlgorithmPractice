/*
���� 1697 ���ٲ���

bfs�� Ǯ��
�޸� 1324kb, �ð� 0ms

���� ��ġ�� �ʱ� ���, ���� ��ġ���� �� �� �ִ� ��ġ������ ���� ����
ex) 5���� ���� �ִ� ��ġ�� 4,6,10 �̹Ƿ� 5�� ����� ������ 4,6,10 ����� �����ϰ� ����
bfsƯ���� �ʺ�Ž���̹Ƿ� ����ġ���� Ư�� ���� ���� ������� ���� ã�� �� ����

bfs ���� ������� ���� ����������? �̿��ؼ� Ǫ�� ����� �ִµ�
*/
#include<stdio.h>
#include<queue>

using namespace std;
int n, k;//0~100,000
int answer;
bool visited[100001];
void bfs();
int main()
{
	answer = 0;
	scanf("%d %d", &n, &k);
	bfs();
	printf("%d\n", answer);

}

void bfs()
{
	if (n == k)
		return;
	//push
	queue <int> q;
	q.push(n);
	visited[n] = true;

	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			int current = q.front();
			if (current == k)
				return;
			q.pop();
			//x-1
			if ((current - 1) >= 0 && visited[current - 1] == false)
			{
				q.push(current - 1);
				visited[current-1] = true;
			}
			//x+1
	        if ((current + 1) <= 100000 && visited[current + 1] == false)
			{
				q.push(current + 1);
				visited[current + 1] = true;
			}
			//2*x
			if ((current * 2) <= 100000 && visited[current * 2] == false)
			{
				q.push(current * 2);
				visited[current *2] = true;
			}
		}
		answer++;
	}
}