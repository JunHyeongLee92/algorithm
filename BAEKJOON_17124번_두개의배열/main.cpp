#include <stdio.h>
#include <algorithm>
#define MAX_SIZE 1000001
using namespace std;

int A[MAX_SIZE];
int B[MAX_SIZE];

void input(int len, int arr[])
{
	for(int i = 0; i < len; i++)
	{
		scanf("%d", &arr[i]);
	}
}

void solve(int n, int m)
{
	int sum = 0;
	int idx;
	
	sort(A, A+n);
	sort(B, B+m);
	idx = lower_bound(B, B+m, A[0]) - B;
	if(idx == m) idx -= 1;
	
	for(int i = 0; i<n; i++)
	{
		for(int j = idx; j < m; j++)
		{
			if(B[j] == A[i])
			{
				idx = j;
				break;
			}
			else if(B[j] > A[i])
			{
				if(j != 0) idx = (B[j] - A[i]) < (A[i] - B[j-1]) ? j : j-1;
				break;
			}
			else if(j == m - 1)
			{
				idx = j;
				break;
			}
		}
		if(idx == m) idx -= 1;
		sum += B[idx];
	}
	
	printf("%d\n", sum);
}

int main(void)
{
	int T, n, m;
	
	scanf("%d", &T);
	
	for(int i = 0 ; i < T; i++)
	{
		scanf("%d %d", &n, &m);
		
		input(n, A);
		input(m, B);
		solve(n,m);
	}
	return 0;
}

