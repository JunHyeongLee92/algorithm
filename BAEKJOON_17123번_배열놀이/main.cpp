#include <iostream>
#include <stdio.h>
#define MAX_SIZE 1001
using namespace std;

int map[MAX_SIZE][MAX_SIZE];

int main(void)
{
	int T;
	int N, M;
	int r1, c1, r2, c2, v;
	
	cin >> T;
	
	for(int i = 0 ; i < T; i++)
	{
		int sum_r[MAX_SIZE] = {0, };
		int sum_c[MAX_SIZE] = {0, };
		
		scanf("%d %d", &N, &M);		
		for(int r = 1; r <= N; r++)
		{
			for(int c = 1; c <= N; c++)
			{
				scanf("%d", &map[r][c]);
				sum_r[r] += map[r][c];
				sum_c[c] += map[r][c];
			}
		}
		
		for(int m = 0; m < M; m++)
		{
			scanf("%d %d %d %d %d", &r1, &c1, &r2, &c2, &v);
			
			int num_r = r2 - r1 + 1;
			int num_c = c2 - c1 + 1;
			
			for(int r = r1; r <= r2; r++)
			{
				sum_r[r] = sum_r[r] + v * num_c; 
			}
			
			for(int c = c1; c <= c2; c++)
			{
				sum_c[c] = sum_c[c] + v * num_r; 
			}
		}

		for(int i = 1; i <= N; i++)
		{
			printf("%d ", sum_r[i]);
		}printf("\n");		
		for(int i = 1; i <= N; i++)
		{
			printf("%d ", sum_c[i]);
		}printf("\n");
	}	
	return 0;
}
