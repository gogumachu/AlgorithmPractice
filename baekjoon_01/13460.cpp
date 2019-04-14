/*
구슬을 한번 굴렸던 방향이나, 역방향으로 돌리지 않게 구현하고 나니 시간과 메모리가 훨씬 단축되었음
 if(j == cur.dir || j == (cur.dir+2) %4) continue; 

메모리:19528kb, 시간36ms -> 메모리:1988kb, 시간 0ms 로 줄어듦

*/

#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;

//구슬들의 위치와, 굴렸던 방향을 기록함
typedef struct node_info
{ 
  int bx, by;
  int rx, ry;
  int dir;
}node;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int N, M;//3~10
char board[10][10];
int bfs(node &init);
int main()
{
  scanf("%d %d", &N, &M);
  node init_info;
  for (int i = 0; i < N; i++)
  {
    getchar(); //\n 입력 제거
    for (int j = 0; j < M; j++)
    {
      scanf("%c",&board[i][j]);
      if (board[i][j] == 'R')
        init_info.rx = i, init_info.ry = j;
      else if (board[i][j] == 'B')
        init_info.bx = i, init_info.by = j;
    }
  }
  init_info.dir = -4;
  int result = bfs(init_info);
  printf("%d\n", result);
}

int bfs(node &init)
{
  int count = 0;
  queue<node> q;
  q.push(init);
  while (!q.empty()) {
    int size = q.size();
    count++;
    if (count > 10) //10번 이상 굴렸을 경우
      break;
    for (int i = 0; i < size; i++) {
      node cur = q.front(); q.pop();
      for (int j = 0; j< 4; j++) {
        if(j == cur.dir || j == (cur.dir+2) %4) continue;
        node tmp = cur;
        //파란구슬을 굴린다.
        do { 
          tmp.bx += dx[j];
          tmp.by += dy[j];
        } while((board[tmp.bx][tmp.by] != 'O') &&(board[tmp.bx][tmp.by] != '#'));
        if (board[tmp.bx][tmp.by] == 'O') continue;
        
        //빨간구슬을 굴린다.
        do {
          tmp.rx += dx[j];
          tmp.ry += dy[j];
        } while ((board[tmp.rx][tmp.ry] != 'O') && (board[tmp.rx][tmp.ry] != '#'));
        
        if (board[tmp.rx][tmp.ry] == 'O') {
          return count;
        }
        // 같은 곳에 위치한다면
        if( (tmp.rx == tmp.bx) && (tmp.ry == tmp.by)) {  //움직인 횟수로 비교한다.
           if( (abs(cur.bx-tmp.bx) +abs(cur.by-tmp.by)) >(abs(cur.rx-tmp.rx) +abs(cur.ry-tmp.ry))){
            tmp.bx -= dx[j];      
            tmp.by -= dy[j];      
           }
           else {
            tmp.rx -= dx[j];
            tmp.ry -= dy[j]; 
           }
        }
        
        tmp.bx -= dx[j];
        tmp.by -= dy[j];
        tmp.rx -= dx[j];
        tmp.ry -= dy[j];
        //굴린 구슬의 상태를 큐에 넣는다.
        q.push({tmp.bx, tmp.by, tmp.rx, tmp.ry,j});
      }
    }//end for
  } //end queue while
  return -1;
}
