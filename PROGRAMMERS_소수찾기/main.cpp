#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    map< int, vector<string> > m;
    map< int, vector<string> >::iterator it;    
    
    for(int i = 0; i < phone_book.size(); i++)
    {
    	m[phone_book[i].size()].push_back(phone_book[i]);
    }
    
    for(it = m.begin(); it != m.end(); it++)
    {
    	cout << it->first << endl;
//    	for(int j = 0; j < it->second.size(); j++)
//		{
//			cout << it->second[j];
//	    }cout << endl;
	}
    
    return answer;
}

int main(void)
{
    vector<string> input;
	input.push_back("11");
	input.push_back("111");
	input.push_back("1111");
	input.push_back("1");
    solution(input);
	return 0;
}
