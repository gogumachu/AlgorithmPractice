/*
���� 1325 : ȿ������ ��ŷ
dfs�� �̿��ؼ� Ǯ��
�ð��� �޸𸮸� �� ���� �ʿ䰡 ����
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
bool visited[10001];//node�� 1������ ���۵ǹǷ� �ִ밳��+1 �� �ʿ�
void dfs(int node);
int counts = 0; //Ž�� ������ ��� ������ �����ϴ� ����. dfs���ڷ� �Ѱ����� �ʰ� ���������� ����
int max_cnt = 0;

int main()
{
	int a = 0, b = 0;
	int ans_cnt = 0;
	scanf("%d%d", &n, &m);
	graph.resize(n+1); //���� ũ�� ����
	for (int i = 0; i<m; i++)
	{
		scanf("%d%d", &a, &b); 
		graph[b].push_back(a);//b -> a ����
	}

	for (int i = 1; i <= n; i++)
	{
		counts = 0;
		fill(begin(visited), begin(visited) + n+1, false);
		dfs(i);
		/*com c;
		c.num = i, c.cnt = counts;
		coms.push_back({c});*/ //����ü�� ����ȣ, Ž�������� ��� ���� �����ؼ� �ִ밪 ����ϰ� �ҷ��� ��� �ڵ�
		if (max_cnt < counts) //�� ū ���� ������ ������ �ִ��� �ʱ�ȭ�ϰ� �ٽ� ����. �� ����� ���� ȿ���ִ�
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