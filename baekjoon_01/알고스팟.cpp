/*���� ������ : 1 , ������ : 0 
�� ���� �׷����� ����ġ�� �����ؼ�
�ּ� ��θ� ã�� dikjstra �� Ǯ  �� ����

4ms, 2048kb �ð�,�޸� ���� �ʿ䰡 ����
-->fill �Ⱦ���, �Է¹����鼭 dist�� �ʱ�ȭ & visited �迭 ���� �ʾҴ���
2036kb, 0ms�� ����
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

int dx[4] = {-1,0,1,0};//�ð����
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
			scanf("%1d", &temp); //1�� ��쿣 true = 1�� ��
			map[i][j] = (temp == 1);
			dist[i][j] = 0x7fffffff; //int �� �ִ밪
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

		if (cur.first == n-1 && cur.second == m-1) return; //�� ������ ������ ���� ���̰� ����
		
		for (int i = 0; i < 4; i++)
		{
			ni = cur.first + dx[i];
			nj = cur.second + dy[i];
			if(ni >= 0 && ni < n&& nj >= 0 && nj <m )//�湮���� Ȯ���ؾ� ������, �湮���� ��� �Ʒ� ���ǹ��� �������� �ʱ� ������ ť�� push �ȵ�
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
