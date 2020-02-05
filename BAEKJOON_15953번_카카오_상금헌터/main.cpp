#include <stdio.h>

int leagueA[] = {0, 5000000, 3000000, 2000000, 500000, 300000, 100000};
int leagueB[] = {0, 5120000, 2560000, 1280000, 640000, 320000};

int getGrade(int num, bool sel)
{
	int idx = 1;
	
	if(num <= 1) return num;
	
	if(sel == true) // 2017
	{
		for(int i = 2; i <= 6; i++)
		{
			idx += i;
			if(num <= idx) return i;
		}
	}else //2018
	{
		int r = 1;
		for(int i = 2; i <= 5; i++)
		{
			r *= 2;
			idx += r;
			if(num <= idx) return i;
		}
	}
	return 0;
}

int main(void)
{
	int TC;
	int a, b;
	int gradeA, gradeB;
	scanf("%d", &TC);
		
	for(int i = 0 ; i < TC ; i++)
	{
		scanf("%d %d", &a, &b);
		gradeA = getGrade(a, true);
		gradeB = getGrade(b, false);
		printf("%d\n", leagueA[gradeA] + leagueB[gradeB]);
	}
	
	return 0;
}

