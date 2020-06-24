#include <stdio.h>
#include <string.h>

#define MAX_SIZE 2500
#define SUB_MAX_SIZE 50

char s[MAX_SIZE];
char sub_s[4][SUB_MAX_SIZE];
int len[4];

int check[MAX_SIZE];

int min = MAX_SIZE;
int max = 0;

void dfs(int L, int cnt)
{
	if(L == 4)
	{
//		for(int i = 0; i< strlen(s); i++)
//		{
//			printf("%d", check[i]);
//		}printf(" cnt : %d\n", cnt);
		
		if(cnt > max) max = cnt;
		if(cnt < min) min = cnt;

		return;
	}
	else
	{
		char *ptr = strstr(s, sub_s[L]);
		if(ptr == NULL)
		{
			dfs(L+1, cnt);
		}
		else
		{
			while(ptr != NULL)
			{
				int idx = ptr - s;
				int tempCheck[SUB_MAX_SIZE] = {0, };
				int checkIdx = 0;
				int addCnt = 0;
				
				for(int i = 0; i < len[L]; i++)
				{
					if(check[idx + i] == 0)
					{
						addCnt += 1;
						check[idx + i] = 1;
						tempCheck[checkIdx++] = idx+i; 
					}
				}
				
				dfs(L+1, cnt + addCnt);
				
				for(int i = 0; i < checkIdx; i ++)
				{
					check[tempCheck[i]] = 0;
				}
				
				ptr = strstr(ptr + 1, sub_s[L]);
			}
		}
		
	}
	
	return;
}

int main(void)
{
	scanf("%s", &s);
	scanf("%s %s %s %s", &sub_s[0], &sub_s[1], &sub_s[2], &sub_s[3]); 
	
	for(int i = 0 ; i < 4; i++)
	{
		len[i] = strlen(sub_s[i]);
	}
		
	dfs(0, 0);
	printf("%d %d\n", min, max);
	return 0;
}
