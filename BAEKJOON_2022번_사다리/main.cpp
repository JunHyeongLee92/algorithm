#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
	double X, Y, C;
	double left, right, w;
	double h_x, h_y, h_mid;
	
	scanf("%lf %lf %lf", &X, &Y, &C);
	left = 0;	
	right = min(X,Y);

	while(right - left > 0.000001)
	{
		w = (left + right) / 2;
		
		h_x = sqrt(X*X - w*w);
		h_y = sqrt(Y*Y - w*w);
		h_mid = (h_x*h_y) / (h_x+h_y);
		
		if(h_mid > C)
		{
			left = w;	
		}
		else
		{
			right = w;
		}
	}
	printf("%.3lf\n", left);
	
	return 0;
}
