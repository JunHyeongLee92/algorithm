#include <string>
#include <vector>
#include <iostream>
#define MAX_SIZE 100 + 2
using namespace std;

struct PAIR
{
	int pillar;
	int step; 
};

PAIR map[MAX_SIZE][MAX_SIZE];
    
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
     for(int i = 0 ; i < build_frame.size(); i++)
    {
    	for(int j = 0 ; j < 4; j++)
    	{
    		cout << build_frame[i][j] << " ";
		}
		cout <<endl;
    }cout <<endl;
    
    for(int i = 0 ; i < build_frame.size(); i++)
    {
    	int x = build_frame[i][0];
    	int y = build_frame[i][1];
    	
    	cout << y << "," << x <<endl;
    	if(build_frame[i][3] == 1) // insert
    	{
    		if(build_frame[i][2] == 0) // pillar
    		{
    			if((y == 0) || (map[y-1][x].pillar == 1))
    			{
    				map[y][x].pillar = 1;
    			}
    			else if((x != 0) && (map[y][x-1].step == 1))
    			{
    			    map[y][x].pillar = 1;		
    			}
    		}
    		else //step
    		{
    			if((map[y-1][x].pillar == 1) || (map[y-1][x+1].pillar == 1))
    			{
    				map[y][x].step = 1;
    			}
    			else if((x!=0) && (map[y][x-1].step == 1) && (map[y][x+1].step == 1)) 
    			{
    				map[y][x].step = 1;
    			}
    		}
    	}
    	else // delete
    	{
    	}
    }
    
    for(int i = 0 ; i <= n; i++)
    {
    	for(int j = 0 ; j <= n; j++)
    	{
    		cout << map[i][j].pillar << "(" << map[i][j].step << ") ";
		}
		cout <<endl;
    }cout <<endl;
    
    
    return answer;
}
