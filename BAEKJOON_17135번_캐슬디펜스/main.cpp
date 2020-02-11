#include <stdio.h>
#include <stdlib.h>
#include <queue>
#define MAX_SIZE 15 + 1
#define MAX_ARCHER 3

int max = 0;
int res;
int N, M, D;
int map[MAX_SIZE][MAX_SIZE];
int map_solve[MAX_SIZE][MAX_SIZE];
int archer[MAX_ARCHER];
int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};

typedef struct POS{
	int y, x;
}pos;

void move(int R)
{
	for(int i = N-1; i > R; i--) // start line 0
	{
		for(int j = 0; j < M; j++)
		{
			map_solve[i][j] = map_solve[i-1][j];
		}
	}
	
	for(int i = 0; i<M; i++)
	{
		map_solve[R][i] = 0;
	}
}

void attack()
{
	pos enemy[MAX_ARCHER] = {{MAX_SIZE, MAX_SIZE}, {MAX_SIZE, MAX_SIZE}, {MAX_SIZE, MAX_SIZE}};
	
	for(int i = 0 ; i < MAX_ARCHER; i++)
	{
		int check[MAX_SIZE][MAX_SIZE] = {0, };
		int ny, nx, nd;
		std::queue<pos> q;
		
		q.push({N-1, archer[i]});
		check[N-1][archer[i]] = 1;
		
		while(!q.empty())
		{
			pos cur = q.front();
			q.pop();
			
			if(map_solve[cur.y][cur.x]  == 1)
			{
				enemy[i].y = cur.y;
				enemy[i].x = cur.x;
				break;
			}
			
			for(int j = 0; j<4; j++)
			{
				ny = cur.y + dy[j];
				nx = cur.x + dx[j];
				nd = (N - ny) + abs((archer[i] - nx));
				if(ny < 0 || ny == N || nx < 0 || nx == M || nd > D || check[ny][nx] == 1) continue;
				
				q.push({ny, nx});
				check[ny][nx] = 1;
			}
		}
	}

	for(int i = 0 ; i < MAX_ARCHER; i++)
	{
		if(map_solve[enemy[i].y][enemy[i].x] == 1) res += 1;
		map_solve[enemy[i].y][enemy[i].x] = 0;
	}
}

void solve(void)
{
	res = 0;
	for(int i = 0; i<N; i++)
	{
		attack();
		move(i);
	}
	if(res > max) max = res;
}

void dfs(int L, int X)
{
	if(L == 3)
	{
		// copy map
		for(int i = 0; i<N; i++)
		{
			for(int j = 0; j<M; j++)
			{
				map_solve[i][j] = map[i][j];
			}
		}
		solve();
		return;
	}
	
	if(X < M)
	{
		//set archer position
		archer[L] = X;
		dfs(L+1, X+1);
		dfs(L, X+1);
	}
}

int main(void)
{
	scanf("%d %d %d", &N, &M, &D);
	
	for(int i = 0; i<N; i++)
	{
		for(int j = 0; j<M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	dfs(0, 0);
	printf("%d", max);
	return 0;
}
