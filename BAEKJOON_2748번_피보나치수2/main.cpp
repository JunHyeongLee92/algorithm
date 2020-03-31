#include <iostream>
#define MAX_SIZE 91

using namespace std;

typedef unsigned long long ull;
ull dp[MAX_SIZE];

ull pibo(int n)
{
	if(n > 1 && dp[n] == 0) dp[n] = pibo(n-1) + pibo(n-2);
	return dp[n];
}

int main(void)
{
	int n;
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	cout << pibo(n);
	return 0;
}
