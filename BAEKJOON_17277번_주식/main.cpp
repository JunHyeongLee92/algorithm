#include <stdio.h>
#define MAX_SIZE 100000

int n, X, y, Z;
int v[MAX_SIZE];

void solve(void)
{
	int k;
	int cur_k;
	int res_i;
	int res_j = -1;
	
	if(y == 0) k = n;
	else k = X / y;

	for(int i = 0; i < n; i++)
	{
		long long sum = 0;
	
		for(int j = i; j < n; j++)
		{
			cur_k = j - i + 1;
			sum += v[j];
			if(cur_k > k) break;
			else if(sum >= (Z + y * cur_k))
			{
				res_i = i + 1;
				res_j = j + 1;
				k = cur_k;
				break;
			}
		}
	}
	
	if(res_j == -1) printf("-1\n");
	else printf("%d %d\n", res_i, res_j);
}

int main(void)
{
	int T;
	
	scanf("%d", &T);
	for(int t = 0; t < T; t++)
	{
		scanf("%d %d %d %d", &n, &X, &y, &Z);
		for(int idx = 0; idx < n; idx++)
		{
			scanf("%d", &v[idx]);
		}
		solve();
	}
	
	return 0;
}
