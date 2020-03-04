#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string p) {
    cout << "recul 1" << endl;
	string answer = "";
    string u, v;
    
    int pos = 0;
    int left = 0;
    int right = 0;

    if(p[0] == '(') left = 1;
    else if(p[0] == ')') right = 1;
    else return answer;
    
    while(left != right)
    {
   	    if(p[++pos] == '(') left += 1;
    	else right += 1;
    }//pos is start index of v
    
	u = p.substr(0, pos + 1);
	v = p.substr(pos + 1, p.length());
    
    cout << u << '+' << v << endl;
	if(u[0] == '(')
	{
		answer = u + solution(v);
	}
	else
	{   
		answer.push_back('(');
		answer += solution(v);
		answer.push_back(')');
		for(int i = 1; i < u.length() -1 ; i++)
		{
			if(u[i] == '(') answer.push_back(')');
			else answer.push_back('(');
		}
	}
    
    return answer;
}

int main(void)
{
	string input;
	cin >> input;
	cout << solution(input) << endl;
	return 0;
}
