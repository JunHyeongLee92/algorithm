#include <stdio.h>

#define MAX_SIZE 14
#define MAX_SUM 200000*14

int K;
int S = 0;
int arr[MAX_SIZE];
int res[MAX_SUM] = {0, };
int cnt = 0;

void dfs(int L, int R)
{
	if(L > K)
	{
		if(R > 0) 
		{	
			if(res[R] == 0) cnt++;
			
			res[R] = 1;
		}
		return;
	}
	dfs(L+1, R); // 0
	dfs(L+1, R+arr[L]); // 0 + 1, 0 + 5, 0 + 7, 0 + 1 + 5, 0 - 1 + 5, 0 + 5 + 7, 0 - 5 + 7...
	dfs(L+1, R-arr[L]); // 0 - 1, 0 - 5, 0 - 7, 0 - 1 - 5, 0 + 1 - 5, ...
}

int main(void)
{	
	scanf("%d", &K);
	for(int i = 1; i<=K; i++)
	{
		scanf("%d", &arr[i]);
		S += arr[i];
	}
		
	dfs(0, 0);
	printf("%d", S - cnt);
	return 0;
}

