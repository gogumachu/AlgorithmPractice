/*
백준 7576 토마토
bfs 이용해서 풀이

총 토마토 개수 구해서 
방문할때마다 토마토 개수 증가시키고
총토마토 개수 == 증가시킨 토마토 개수 비교

위 방법보다는 익어야하는 토마토 (값이 0인것) 개수를 세서
방문할때마다 값을 감소시키는 방법이 시간이 조금더 줄어서 나옴

아래 방법으로 풀이 수정후 
시간 112ms -> 108ms로 줄었음
메모리 	10056kb 동일
*/
#include<iostream>
#include<queue>

struct tindex
{
	int x, y;
};
int m, n; //2~1000
int box[1000][1000];
std::queue <tindex> q;
//int t_count;//익은 토마토 개수
//int alltomato;//총 익어야 하는 토마토 개수
int untomato; //익어야 하는 토마토 (익지 않은 토마토)
int days; //날짜
void bfs();
int main()
{
	scanf("%d %d", &m,&n);
	//alltomato = m*n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &box[i][j]);
			//if (box[i][j] == -1) alltomato--;
			if (box[i][j] == 0) untomato++;
			if (box[i][j] == 1) { 
				q.push({ i,j }); 
				//t_count++;
			}
		}
	}
	bfs();
	//if (alltomato != t_count)
	if(untomato> 0)
		days = -1;
	printf("%d", days);

}

void bfs()
{
	if (untomato == 0)
		return;
	days = -1;
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			int ci = q.front().x;
			int cj = q.front().y;
			q.pop();
			//상
			if (ci - 1 >= 0 && box[ci - 1][cj] == 0)
			{
				untomato--;
				box[ci - 1][cj] = 1;
				q.push({ ci - 1, cj });
			}
			//하
			if (ci + 1 < n && box[ci + 1][cj] == 0)
			{
				untomato--;
				box[ci + 1][cj] = 1;
				q.push({ ci + 1, cj });
			}
			//좌
			if (cj -1 >= 0 && box[ci][cj-1] == 0)
			{
				untomato--;
				box[ci][cj-1] = 1;
				q.push({ ci, cj-1 });
			}
			//우
			if (cj +1 <m && box[ci][cj+1] == 0)
			{
				untomato--;
				box[ci][cj+1] = 1;
				q.push({ ci, cj+ 1 });
			}
		}//end for
		days++;
	}
}