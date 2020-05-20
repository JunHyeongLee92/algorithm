#include <stdio.h>
#include <algorithm>
#include <map>
#include <string.h>
#define MAX_LENGTH 101

using namespace std;
typedef long long ll;

map<string, int> m;
	
int getLength(string str)
{
	int idx = 0;
	while(str[idx] != '\0')
	{
		idx++;
	}
	
	return idx;
}

int stringCmp(string str1, string str2)
{
	int res = 0;
	for(int i = 0; i < str1.length(); i++)
	{
		if(str1[i] > str2[i])
		{
			res = 1;
			break;
		}else if(str1[i] < str2[i])
		{
			res = -1;
			break;
		}
	}
	
	return res;
}

ll sectionSum()
{
	ll section_sum = 0;
	
	char key1[MAX_LENGTH], key2[MAX_LENGTH];
	scanf("%s %s", &key1, &key2);

	for(auto it = m.begin(); it != m.end(); it++)
	{
		string it_key = it->first;
		int it_key_len = it_key.length();
		int key1_len = getLength(key1);
		int key2_len = getLength(key2);
		
		//it_key string length lower or bigger
		if(it_key_len < key1_len || key2_len < it_key_len) 
		{
			continue;
		}
		else if(key1_len < it_key_len && it_key_len < key2_len)
		{
			section_sum += it->second;	
		}
		else 
		{
			if((strcmp(it_key.c_str(), key1) == 0) || (strcmp(it_key.c_str(), key2) == 0)) 	section_sum += it->second;	
			else if(key1_len == key2_len)
			{
				if((stringCmp(key1, it_key) == -1) && (stringCmp(key2, it_key) == 1))
				{
					section_sum += it->second;	
				}
			}
			else if(key1_len == it_key_len)
			{
				if(stringCmp(key1, it_key) == -1)
				{
					section_sum += it->second;	
					break;
				}
			}
			else
			{
				if(stringCmp(key2, it_key) == 1)
				{
					section_sum += it->second;	
					break;
				}
			}
		}
	}
	
	printf("%lld ", section_sum);
}

int main(void)
{
	int n;
	int cmd, value;
	char key[MAX_LENGTH];
	
	ll sum = 0;
	
	scanf("%d", &n);
	
	for(int t = 0; t < n; t++)
	{
		scanf("%d", &cmd);
		switch(cmd)
		{
			case 1 :
			{
				scanf("%s %d", &key, &value);
				
				auto add_it = m.find(key);
				if(add_it != m.end()) 
				{
					add_it->second += value;
				}
				else
				{
					m.insert(make_pair(key, value));
				}
					
				sum += value;
				
				printf("%lld ", sum);
				break;
			}
			case 2 :
			{
				sectionSum();
				break;
			}
			case 3 :
			{
				scanf("%s", &key);				
				
				auto sub_it = m.find(key);
				if(sub_it != m.end()){
					sum -= sub_it->second;
					m.erase(sub_it);
				}
							
				printf("%lld ", sum);
				break;
			}
		}
	}

	
	return 0;
}
