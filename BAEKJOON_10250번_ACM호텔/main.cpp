#include <stdio.h>

int main(void)
{
	int T;
	scanf("%d", &T);	
	for(int i = 0; i<T; i++)
	{
		int W, H, N;
		scanf("%d %d %d", &H, &W, &N);
		printf("%d%02d\n", (N-1)%H + 1, (N-1)/H + 1); // N번째 방 계산 
	}
	return 0;
}
