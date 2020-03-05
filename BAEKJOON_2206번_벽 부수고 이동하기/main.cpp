#include <cstdio>
#include <queue>
#define MAX_SIZE 1000
using namespace std;

struct NODE
{
	int y, x;
	int crash;
};

int N, M;
int map[MAX_SIZE][MAX_SIZE];
int check[MAX_SIZE][MAX_SIZE][2];

int dy[] = {1, 0, -1, 0};
int dx[] = {0, -1, 0, 1};

int bfs()
{
	int answer = -1;
	int x = 0;
	int y = 0;
	int crash = 0;
	int nx, ny, ncrash;
	queue<NODE> q;
	
	check[y][x][0] = 1;
	check[y][x][1] = 1;
	q.push({0,0,0});
	
	while(!q.empty())
	{
		y = q.front().y;
		x = q.front().x;
		crash = q.front().crash;
		q.pop();
		
		for(int i = 0 ; i < 4; i++)
		{
			ny = y + dy[i];
			nx = x + dx[i];
			ncrash = crash;
			
			if(ny >= 0 && ny < N && nx >= 0 && nx < M && check[ny][nx][ncrash] == 0)
			{
				if(map[ny][nx] == 1)
				{
					if(ncrash == 1) continue;
					
					ncrash = 1;
				}
				
				if(check[ny][nx][ncrash] < check[y][x][crash]) check[ny][nx][ncrash] = check[y][x][crash] + 1;
				q.push({ny, nx, ncrash});
			}
		}
	}
	
	for(int i = 0 ; i < N; i++)
	{	
		for(int j = 0 ; j < M; j++)
		{
			printf("%d ", check[i][j][0]);
		}printf("\n");
	}printf("\n");
	
	for(int i = 0 ; i < N; i++)
	{	
		for(int j = 0 ; j < M; j++)
		{
			printf("%d ", check[i][j][1]);
		}printf("\n");
	}
	
	if(check[N-1][M-1][0] == 0 && check[N-1][M-1][1] == 0) answer = -1;
	else 
	{
		if(check[N-1][M-1][0] == 0) answer = check[N-1][M-1][1];
		else if(check[N-1][M-1][1] == 1) answer = check[N-1][M-1][0];
		else answer = check[N-1][M-1][0] > check[N-1][M-1][1] ? check[N-1][M-1][1] : check[N-1][M-1][0] ;
	}
	return answer;
}

int main(void)
{
	scanf("%d %d", &N, &M);
	
	for(int i = 0 ; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	printf("%d", bfs());
	
	return 0;
}
