/*
백준 1697 숨바꼭질

bfs로 풀이
메모리 1324kb, 시간 0ms

현재 위치를 초기 노드, 현재 위치에서 갈 수 있는 위치값들을 노드로 설정
ex) 5에서 갈수 있는 위치는 4,6,10 이므로 5에 연결된 노드들을 4,6,10 노드라고 생각하고 구현
bfs특성상 너비탐색이므로 현위치에서 특정 노드로 가는 가장빠른 길을 찾을 수 있음

bfs 외의 방법으로 뭔가 수학적으로? 이용해서 푸는 방법도 있는듯
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