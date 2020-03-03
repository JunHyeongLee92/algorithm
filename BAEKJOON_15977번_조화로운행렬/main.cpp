#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_COLUMN 3
#define MAX_ROW 200000
using namespace std;

int N, M;
int map[MAX_COLUMN][MAX_ROW];
vector< vector<int> > vec;

int dp[MAX_ROW] = {0, };

void LIS()
{
	dp[0] = 1;
	if(N == 3)
	{
		for(int i = 1; i<M; i++)
		{
			int max = 0;
			
			for(int j = 0; j < i; j++)
			{
				if((vec[j][1] < vec[i][1]) && (vec[j][2] < vec[i][2]) && (dp[j] > max))
				{
					max = dp[j];		
				}
			}
			dp[i] = max + 1;
		}
	}
	else
	{
		for(int i = 1; i<M; i++)
		{
			int max = 0;
			
			for(int j = 0; j < i; j++)
			{
				if((vec[j][1] < vec[i][1]) && dp[j] > max)
				{
					max = dp[j];			
				}
			}
			dp[i] = max + 1;
		}
	}
}

int cmp(vector<int> a, vector<int> b)
{
	if(a.front() < b.front())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main(void)
{
	int input;
	cin >> N >> M;
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}		

	for(int j = 0; j < M; j++)
	{
		vector<int> inputVec;
		for(int i = 0; i < N; i++)
		{
			inputVec.push_back(map[i][j]);
		}
		vec.push_back(inputVec);
	}		

	sort(vec.begin(), vec.end(), cmp);
//	for(int j = 0; j < M; j++)
//	{
//		for(int i = 0; i < N; i++)
//		{
//			cout << vec[j][i] << ' ';
//		}cout << endl;
//	}		
	
	LIS();
	
//	for(int i = 0; i < M; i++)
//	{
//		cout << dp[i] << ' ';
//	}cout << endl;
	cout << *max_element(dp, dp+M);
	return 0;
}
