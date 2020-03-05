#include <string>
#include <iostream>
#include <vector>

using namespace std;

int res = 50;
int length;
string g_begin, g_target;
vector<int> check;
vector<string> g_words;

void dfs(int L, string str)
{
	if(L > check.size()) return;
	
	if(str == g_target)
	{
		res = L < res ? L : res;
		cout << "res = " <<res << endl;
		return;
	}
	
	for(int i = 0; i<check.size(); i++)
	{
		if(check[i] == 0)
		{
			for(int j = 0; j<length; j++)
			{
				if((str.substr(0, j) == g_words[i].substr(0,j)) && (str.substr(j+1, length) == g_words[i].substr(j+1, length)))
				{
					cout << j << ' ' << str << ' ' << g_words[i] << endl;
					check[i] = 1;
					dfs(L+1, g_words[i]);
					check[i] = 0;
					break;
				}
			}
		}
	}
}

int solution(string begin, string target, vector<string> words) {
    g_begin = begin;
    g_target = target;
	g_words = words;
	length = begin.length();	
	check.assign(words.size(), 0);
	
	dfs(0, begin);
	
    return res;
}

int main(void)
{
	return 0;
}
