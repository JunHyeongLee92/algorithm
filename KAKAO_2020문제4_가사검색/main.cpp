#include <string>
#include <vector>
#include <iostream>

using namespace std;
struct NODE
{
	string str;
	int res;
	int length;
    int side;
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    vector<NODE> strVec[2];
    string str;	
    int que_size, res, s, e, side;
    int flag;
    
    for(int i = 0 ; i<queries.size() ; i++)
    {
        flag = 1;
    	que_size = queries[i].size();
    	res = 0;
		s = 0;
		e = que_size - 1;
		
    	if(queries[i][s] == '?') // prefix
    	{
            side = 0;
            s = queries[i].find_last_of('?') + 1;
    	}
    	else if(queries[i][e] == '?')// suffix
    	{
            side = 1;
    		e = queries[i].find('?');
    	}

    	str = queries[i].substr(s, e);
        //cout << "s = " << s << " e = " << e << " str = " << str << endl;
    	for(int idx = 0 ; idx <strVec[side].size() ; idx++)
    	{
            //cout << "idx = " << idx << endl;
    		if(strVec[side][idx].str == str && strVec[side][idx].length == que_size)
    		{
    			flag = 0;
    			answer.push_back(strVec[side][idx].res);
    			break;
    		}
    	}
    	
    	if(flag)
    	{
	    	for(int j = 0 ; j<words.size(); j++)
	    	{
	    		if(words[j].size() != que_size) continue;
	    		if(words[j].substr(s,e) == str) res++;
	    	}
	    	NODE node = {str, res, que_size};
			strVec[side].push_back(node);	
	    	answer.push_back(res);
    	}
	}
    return answer;
}
