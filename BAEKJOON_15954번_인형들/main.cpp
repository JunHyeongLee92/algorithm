#include <stdio.h>
#include <math.h>
#define MAX_NUM 501

int N, K;
double arr[MAX_NUM];

int idx;
double res;
double min = 0x7fffffffffffffff;

void solve(int cnt)
{
	int start = 0;
	int end = cnt-1;
	double total = 0;
	double m_avg = 0;
	double m_sum = 0;
	
	int minIdx = start;
	
	for(int i = start; i <= end; i++)
	{
		total += arr[i];
	}
	m_avg = total/cnt;
	
	for(int i = start; i <= end; i++)
	{
		m_sum = m_sum + pow((m_avg - arr[i]), 2);
	}
	end++;
	if(m_sum < min) min = m_sum;
	
	while(end < N)
	{
		double temp = 0;
		total = total - arr[start++] + arr[end];
		m_avg = total/cnt;
		
		for(int i = start; i <= end; i++)
		{
			temp = temp + pow((m_avg - arr[i]), 2);
		}
		if(temp < min)
		{	
			min = temp;
			minIdx = start;
		}
		end++;
	}

	res = min;
	idx = minIdx;
}
int main(void)
{
	scanf("%d %d", &N, &K);
		
	for(int i = 0 ; i < N ; i++)
	{
		scanf("%lf", &arr[i]);
	}
	
	for(int i = K; i <= N; i++)
	{
		solve(i);
	}
	
	printf("%0.11lf", sqrt(res/K));
	
	return 0;
}

