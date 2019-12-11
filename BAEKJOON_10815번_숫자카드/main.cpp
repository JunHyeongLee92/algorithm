#include <stdio.h>

#define MAX_SIZE 500001
#define MAX_VALUE 20000001

int N, M;
int arrN[MAX_VALUE];
int res[MAX_SIZE];

int main(void)
{
	int input;
	int cmp;
	
	scanf("%d", &N);
	for(int i = 0; i<N; i++)
	{
		scanf("%d", &input);
		arrN[input + 10000000] = 1;
	}
	
	scanf("%d", &M);
	for(int i = 0; i<M; i++)
	{
		scanf("%d", &cmp);
		if(arrN[cmp + 10000000] == 1) res[i] = 1;
	}
	
	for(int i = 0; i<M; i++)
	{
		printf("%d ", res[i]);
	}
	
	return 0;
}

