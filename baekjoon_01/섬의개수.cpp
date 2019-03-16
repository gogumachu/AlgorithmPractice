/*
백준4963 섬의개수
dfs로 풀음

cin,cout 입출력 -> scanf로 바꾸고 나니 4ms -> 0ms로 시간이 줄었음 메모리는 변하지 않음

메모리를 줄일수 있는 방법을 생각해봐야함
*/
#include <iostream>

int map[50][50];
int w, h;
int land_cnt; //섬의 개수 세는 변수
//가로, 세로 대각선 방향 모두 탐색
int x[8] = {-1,-1,0,1,1,1,0,-1};
int y[8] = {0,-1,-1,-1,0,1,1,1};

void dfs(int a, int b);
int main()
{
	while (1)
	{
		scanf("%d %d", &w, &h);
		if (w == 0) //0 입력이 들어오면 종료
			break;
		land_cnt = 0;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				scanf("%d", &map[i][j]);

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] == 1) //섬일 경우 개수를 센다
				{
					dfs(i,j);
					land_cnt++;
				}
			}
		}
		printf("%d\n", land_cnt);
	}//end whileo
}

void dfs(int a, int b)
{
	map[a][b] = -1; //방문할 섬인 경우 -1로 표시. 0으로 해줘도 상관없음
	for (int i = 0; i < 8; i++)
	{
		if (a + y[i] >= 0 && a + y[i] < h && b + x[i] >= 0 && b + x[i] < w && map[a + y[i]][b + x[i]] == 1)
		{
				dfs(a + y[i], b + x[i]);
		}
	}
}