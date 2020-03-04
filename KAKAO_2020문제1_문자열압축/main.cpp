#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

struct PAIR
{
	string str;
	int cnt;
};

int solution(string s)
{
	int answer = 1000;
	int l = 1;
	
	while(l <= s.length() / 2 + 1)
	{
		vector<PAIR> vec;
		string tok = s.substr(0, l);
		int pos = 0;
		int flag = 1;
		while(pos < s.length())
		{
			PAIR inputPair = {tok, 0};
			
			while(s.substr(pos, l) == tok)
			{
				inputPair.cnt += 1;	
				pos += l;
				if(pos > s.length()) 
				{
					flag = 0;
					break;
				}
			}
			vec.push_back(inputPair);
			if(flag) tok = s.substr(pos, l);
		}
		l++;
		
		int length = 0;
		for(int i = 0 ; i< vec.size(); i++)
		{
			if(vec[i].cnt != 1)
			{
				while(vec[i].cnt > 0)
				{
					vec[i].cnt /= 10;
					length += 1;
				}
			}
			length += vec[i].str.length();
		}	
		if(length < answer) answer = length;
	}
	return answer;
}
