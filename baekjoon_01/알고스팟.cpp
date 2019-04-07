/*벽이 있으면 : 1 , 없으면 : 0 
위 값을 그래프의 가중치로 생각해서
최소 경로를 찾는 dikjstra 로 풀  수 있음

4ms, 2048kb 시간,메모리 줄일 필요가 있음
-->fill 안쓰고, 입력받으면서 dist값 초기화 & visited 배열 쓰지 않았더니
2036kb, 0ms로 줄음
*/
#include<iostream>
#include<queue>
#include <functional> //for greater
using namespace std;

typedef pair<int, int> node;
typedef pair<int, node> dnode; //weight, node

int n, m;//100
bool map[101][101];
int dist[101][101];
//bool visited[101][101];

int dx[4] = {-1,0,1,0};//시계방향
int dy[4] = {0,1,0,-1};
void dikjstra();
int main()
{
	int temp;
	scanf("%d %d", &m, &n);
	for (int i = 0; i <n; i++)
	{
		for (int j = 0; j < m; j++)	
		{
			scanf("%1d", &temp); //1일 경우엔 true = 1이 들어감
			map[i][j] = (temp == 1);
			dist[i][j] = 0x7fffffff; //int 의 최대값
		}
	}

	dikjstra();
	printf("%d", dist[n-1][m-1]);
}

void dikjstra()
{
	priority_queue<dnode,vector<dnode>, greater<dnode> > pq;
	pq.push({ 0,{0,0} });
	dist[0][0] = 0;
	node cur;
	int ni, nj; //next i , next j, cur weight
	while (!pq.empty())
	{
		cur = pq.top().second;  pq.pop();

		if (cur.first == n-1 && cur.second == m-1) return; //이 구문은 있으나 마나 차이가 없음
		
		for (int i = 0; i < 4; i++)
		{
			ni = cur.first + dx[i];
			nj = cur.second + dy[i];
			if(ni >= 0 && ni < n&& nj >= 0 && nj <m )//방문여부 확인해야 하지만, 방문했을 경우 아래 조건문을 충족하지 않기 때문에 큐에 push 안됨
			{
				if (dist[ni][nj] > map[ni][nj] + dist[cur.first][cur.second])
				{
					dist[ni][nj] = map[ni][nj] + dist[cur.first][cur.second];
					pq.push({ dist[ni][nj],{ni,nj } });
				}
			}
		}
	}
}
