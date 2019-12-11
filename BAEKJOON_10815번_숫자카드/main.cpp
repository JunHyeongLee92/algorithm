#include <algorithm>
#include <stdio.h>

#define MAX_SIZE 500001

using namespace std;

typedef struct _CARD
{
	int val;
	int idx;
}card;

int N, M;
card arrN[MAX_SIZE];
card arrM[MAX_SIZE];
int res[MAX_SIZE] = {0, };

void solve(void)
{
	int idxN = 0;
	int idxM = 0;
	
	while((idxN < N) && (idxM < M))
	{
		if(arrM[idxM].val > arrN[idxN].val)
		{
			idxN += 1;
		}
		else
		{
			if(arrM[idxM].val == arrN[idxN].val)
			{
				res[arrM[idxM].idx] = 1;
			}
			idxM += 1;
		}
	}
	
	for(int i = 0; i<M; i++)
	{
		printf("%d ", res[i]);
	}printf("\n");	
}

bool cmp(const card &n1, const card &n2)
{
	if(n1.val < n2.val) return true;
	else return false;
}

int main(void)
{
	scanf("%d", &N);
	for(int i = 0; i<N; i++)
	{
		scanf("%d", &arrN[i].val);
		arrN[i].idx = i;
	}
	
	scanf("%d", &M);
	for(int i = 0; i<M; i++)
	{
		scanf("%d", &arrM[i].val);
		arrM[i].idx = i;
	}
	
	sort(arrN, arrN+N, cmp);	
	sort(arrM, arrM+M, cmp);
	
	solve();
		
	return 0;
}

