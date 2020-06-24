#include <stdio.h>
#include <vector>
#define MAX_SIZE 100001

using namespace std;
typedef unsigned long long ull;

int W[MAX_SIZE];
int Q[MAX_SIZE];
//int map[MAX_SIZE][MAX_SIZE];
vector<int> vec[MAX_SIZE];

ull solve(int size)
{
	ull ret = 1000000000;
	for(int i = 1; i<=size; i++)
	{
		ull sum = 0;
		for(auto it = vec[i].begin(); it != vec[i].end(); it++)
		{
			printf("#%d %d\n", *it, W[*it]);
			sum += W[*it];
		}
		printf("sum = %d\n", sum);
		if(sum < ret) ret = sum;
	}
	
	return ret;
}

int main(void)
{
	int T;
	int N;
	scanf("%d", &T);
	
	for(int t = 0 ; t < T; t++)
	{
		int sum = 0;
		
		scanf("%d", &N);
		
		for(int h = 1 ; h <= N; h++)
		{
			vec[h].clear();
		}
		
		for(int n = 1 ; n <= N; n++)
		{
			int isChecked = 0;
			scanf("%d %d", &W[n], &Q[n]);
			sum += W[n];
			
			for(auto it = vec[n].begin(); it != vec[n].end(); it++)
			{
				if(*it == Q[n])
				{
					isChecked = 1;
					break;
				}
			}
			
			if(!isChecked)
			{
				vec[n].push_back(Q[n]);
				vec[Q[n]].push_back(n);
			}
		}
		
		printf("%llu\n", sum - solve(N));
	}
	return 0;
}
