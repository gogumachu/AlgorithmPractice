/*
백준 1325 : 효율적인 해킹
dfs를 이용해서 풀음
시간과 메모리를 더 줄일 필요가 있음
*/
#include<iostream>
#include<vector>

using namespace std;
int n, m; //10,000 100,000
/*struct com
{
	int num = 0;
	int cnt = 0;
};
vector<com> coms;*/
vector<vector<int>> graph; //for adjacency list
int answers[10001];
bool visited[10001];//node가 1번부터 시작되므로 최대개수+1 이 필요
void dfs(int node);
int counts = 0; //탐색 가능한 노드 개수를 저장하는 변수. dfs인자로 넘겨주지 않고 전역변수로 선언
int max_cnt = 0;

int main()
{
	int a = 0, b = 0;
	int ans_cnt = 0;
	scanf("%d%d", &n, &m);
	graph.resize(n+1); //벡터 크기 지정
	for (int i = 0; i<m; i++)
	{
		scanf("%d%d", &a, &b); 
		graph[b].push_back(a);//b -> a 방향
	}

	for (int i = 1; i <= n; i++)
	{
		counts = 0;
		fill(begin(visited), begin(visited) + n+1, false);
		dfs(i);
		/*com c;
		c.num = i, c.cnt = counts;
		coms.push_back({c});*/ //구조체에 노드번호, 탐색가능한 노드 개수 저장해서 최대값 출력하게 할려고 썼던 코드
		if (max_cnt < counts) //더 큰 값이 나오면 기존에 있던것 초기화하고 다시 저장. 이 방법이 좀더 효율있다
		{
			ans_cnt = 0;
			max_cnt = counts;
			answers[ans_cnt++] = i;
		}
		else if (max_cnt == counts)
		{
			answers[ans_cnt++] = i;
		}
	}
	for (int i = 0; i < ans_cnt; i++)
	{ 
		printf("%d ", answers[i]);
	}
	/*for (int i = 0; i < n; i++)
	{
		if (coms[i].cnt == max_cnt)
			printf("%d ", i+1);
	}*/
}

void dfs(int node)
{
	if (visited[node] == true) return;
	visited[node] = true;
	counts++;
	for (int i = 0; i<graph[node].size(); i++)
		dfs(graph[node][i]);
}