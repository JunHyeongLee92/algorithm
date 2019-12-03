#include <stdio.h>

#define MAX_NUM 100001
#define MAX_ITEM 20
typedef struct _Person{
	int number = 0;
	int item = 0;
} Person;

int N, K;
Person counter[MAX_NUM];
Person customer[MAX_NUM];
int out[MAX_NUM] = {0, };

void solve()
{
	int idx_people = 1;
	int idx_out = 1;
	
	while(idx_people <= N) // while customer input
	{
		int idx_counter = 1;
		int min = 20;

		// O(N^2)
		// check to empty space and compare min value
		while(idx_counter <= K) 
		{
			if(counter[idx_counter].item == 0) break;
			
			if(counter[idx_counter].item < min) min = counter[idx_counter].item;
			idx_counter++;
		}
		
		if(idx_counter <= K) // if it is not full
		{
			counter[idx_counter] = customer[idx_people];
			idx_people++;
		}
		else 
		{
			for(int i = K; i > 0; i--) // search from behind to front with subtract the min value
			{
				counter[i].item -= min;
				if(counter[i].item == 0)
				{
					out[idx_out++] = counter[i].number;
					counter[i].number = 0;
				}
			}
		}
	}
	
	while(idx_out <= N) // Until all the customer are gone.
	{
		int min = 20;
		for(int i = 1 ; i <= K; i++)
		{
			if(counter[i].item <= 0) continue;
			else if(counter[i].item < min) min = counter[i].item;
		}
		
		for(int i = K; i > 0; i--)
		{
			counter[i].item -= min;
			if(counter[i].item == 0)
			{
				out[idx_out++] = counter[i].number;
				counter[i].number = 0;
			}
		}
	}
}

void calc() // calculate out array 
{
	unsigned long long res = 0;
	
	for(int i = 1; i<=N; i++)
	{
		res += i*out[i];
	}
	printf("%llu", res);
}

int main(void)
{
	scanf("%d %d", &N, &K);
	for(int i = 1; i <= N; i++)
	{
		scanf("%d %d", &customer[i].number, &customer[i].item); 
	}
	solve();
	calc();
	
	return 0;
}
