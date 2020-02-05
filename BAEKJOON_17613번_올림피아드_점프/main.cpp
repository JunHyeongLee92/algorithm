#include <stdio.h>

#define MAX_SIZE 100000001

#define MIN(X, Y) ((X < Y) ? X : Y)
#define MAX(X, Y) ((X > Y) ? X : Y)

int x, y;
int dp[MAX_SIZE] = {0, };

int jump(int start, int end)
{
	if(dp[end] != 0) return dp[end];
	else
	{
		for(int i = 1; i <= end; i++)
		{
			dp[i] = 0x7fffffff;
			
			int mul = 2;
			int cnt = 1;
			
			while((mul - 1) <= i)
			{
				dp[i] = MIN(dp[i - (mul - 1)] + cnt, dp[i]);
				mul *= 2;
				cnt += 1;
			}
		}
	}
	
	int ret = 0;
	for(int i = start; i <= end; i++)
	{
		ret = MAX(ret, dp[i]);	
	}
	return ret;
}

int main(void)
{
	int T;
	scanf("%d", &T);
		
	for(int i = 0 ; i < T; i++)
	{
		scanf("%d %d", &x ,&y);
		printf("%d\n", jump(x, y));
		
//		for(int j = 0; j<=y; j++)
//		{
//			printf("%d ", dp[j]);
//		}printf("\n");
	}
	
	return 0;
}

