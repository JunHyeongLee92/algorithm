#include <stdio.h>
#include <algorithm>
#define MAX_SIZE 201
using namespace std;

typedef unsigned long long ull;

int T, N;
int X[MAX_SIZE];
ull dp[MAX_SIZE][MAX_SIZE];

ull dfs(int L, int idx, int prev)
{
	int dp_sum = 0;
	
	if(L == N)
	{
		dp[L][prev] = 1;
		return 1;
	}

	if(dp[L][prev] == 0)
	{
		for(int i = prev; i <= X[idx+1]; i++)
		{
			dp_sum += dfs(L+1, idx+1, i);	
		}
		
		dp[L][prev] = dp_sum;
	}
	
	return dp[L][prev];
}

int main(void)
{	
	scanf("%d", &T);
	
	for(int t = 0; t < T; t++)
	{
		scanf("%d", &N);
		
		for(int i = 0; i <= N; i++)
		{
			for(int j = 0; j < MAX_SIZE; j++)
			{
				dp[i][j] = 0;
			}
		}
			
		for(int i = 1; i <= N; i++)
		{
			scanf("%d", &X[i]);
		}

		sort(X, X+N);	
		dfs(0, 0, 1);
		printf("%llu\n", (dp[0][1] * N) % 1000000007);
	}
	
	return 0;
}

