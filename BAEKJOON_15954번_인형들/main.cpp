#include <stdio.h>
#include <math.h>
#define MAX_NUM 501

int N, K;
double arr[MAX_NUM];

int idx;
double res;

void solve()
{
	int start = 0;
	int end = K-1;
	double m_avg = 0;
	double total = 0;
	double m_sum = 0;
	
	double min = 0x7fffffffffffffff;
	int minIdx = start;
	int cnt;
	
	while(start <= N - K)
	{
		cnt = K;
		for(int i = start; i <= end; i++)
		{
			total += arr[i];
		}
		m_avg = total/cnt;
		
		for(int i = start; i <= end; i++)
		{
			m_sum = m_sum + pow((m_avg - arr[i]), 2);
		}
		
		printf("start = %d end = %d m_avg = %lf m_sum = %lf\n", start, end, m_avg, m_sum);
		end++;
		while(end < N)
		{
			double temp = 0;
			
			cnt++;
			total = total + arr[end];
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
			printf("start = %d end = %d m_avg = %lf m_sum = %lf\n", start, end, m_avg, m_sum);
			end++;
		}
		start++;
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
	
	solve();
	
	printf("%0.11lf\n", sqrt(res/K));
	
	return 0;
}

