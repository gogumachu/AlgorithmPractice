/*bfs 풀이
메모리가 너무 많이 들음 2968k
-->dp로 푸는 방법생각해봐야할듯


*/
#include<iostream>
#include<queue>
using namespace std;

bool visited[1001][1001]; //스크린 개수

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
			//1.화면에 있는 이모티콘 모두 복사해서 클립보드에 저장
			if (s != c && visited[s][s] == false)
			{
				visited[s][s] = true;
				q.push({ s,s });
			}
			//2.클립보드에 있는 이모티콘 화면에 붙여넣기
			if (s+c<=1000 && visited[s + c][c] == false)
			{
				visited[s + c][c] = true;
				q.push({ s + c,c });
			}
			//3.화면에 있는 이모티콘 중 하나 삭제
			if (s - 1 > 1 && visited[s - 1][c] == false)
			{
				visited[s - 1][c] = true;
				q.push({ s - 1,c });
			}
		}
		ans++;
	}
}