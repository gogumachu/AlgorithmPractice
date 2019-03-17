/*
���� 7576 �丶��
bfs �̿��ؼ� Ǯ��

�� �丶�� ���� ���ؼ� 
�湮�Ҷ����� �丶�� ���� ������Ű��
���丶�� ���� == ������Ų �丶�� ���� ��

�� ������ٴ� �;���ϴ� �丶�� (���� 0�ΰ�) ������ ����
�湮�Ҷ����� ���� ���ҽ�Ű�� ����� �ð��� ���ݴ� �پ ����

�Ʒ� ������� Ǯ�� ������ 
�ð� 112ms -> 108ms�� �پ���
�޸� 	10056kb ����
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
//int t_count;//���� �丶�� ����
//int alltomato;//�� �;�� �ϴ� �丶�� ����
int untomato; //�;�� �ϴ� �丶�� (���� ���� �丶��)
int days; //��¥
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
			//��
			if (ci - 1 >= 0 && box[ci - 1][cj] == 0)
			{
				untomato--;
				box[ci - 1][cj] = 1;
				q.push({ ci - 1, cj });
			}
			//��
			if (ci + 1 < n && box[ci + 1][cj] == 0)
			{
				untomato--;
				box[ci + 1][cj] = 1;
				q.push({ ci + 1, cj });
			}
			//��
			if (cj -1 >= 0 && box[ci][cj-1] == 0)
			{
				untomato--;
				box[ci][cj-1] = 1;
				q.push({ ci, cj-1 });
			}
			//��
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