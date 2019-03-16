/*
����4963 ���ǰ���
dfs�� Ǯ��

cin,cout ����� -> scanf�� �ٲٰ� ���� 4ms -> 0ms�� �ð��� �پ��� �޸𸮴� ������ ����

�޸𸮸� ���ϼ� �ִ� ����� �����غ�����
*/
#include <iostream>

int map[50][50];
int w, h;
int land_cnt; //���� ���� ���� ����
//����, ���� �밢�� ���� ��� Ž��
int x[8] = {-1,-1,0,1,1,1,0,-1};
int y[8] = {0,-1,-1,-1,0,1,1,1};

void dfs(int a, int b);
int main()
{
	while (1)
	{
		scanf("%d %d", &w, &h);
		if (w == 0) //0 �Է��� ������ ����
			break;
		land_cnt = 0;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				scanf("%d", &map[i][j]);

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] == 1) //���� ��� ������ ����
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
	map[a][b] = -1; //�湮�� ���� ��� -1�� ǥ��. 0���� ���൵ �������
	for (int i = 0; i < 8; i++)
	{
		if (a + y[i] >= 0 && a + y[i] < h && b + x[i] >= 0 && b + x[i] < w && map[a + y[i]][b + x[i]] == 1)
		{
				dfs(a + y[i], b + x[i]);
		}
	}
}