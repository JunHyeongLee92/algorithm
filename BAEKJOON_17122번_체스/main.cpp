#include <iostream>
using namespace std;

string cmp(string a, int int_b)
{
	string res;
	
	int r, c;
	int r_a, c_a;
	int r_b, c_b;
	r_a = a[0] - 'A';
	c_a = a[1] - '1';
		
	r_b = (int_b - 1) % 8;
	c_b = (int_b - 1) / 8;
	
	r = (r_a + r_b) % 2;
	c = (c_a + c_b) % 2;
	
	res = ( r == 0 ? (c == 0 ? "YES" : "NO") : (c == 1 ? "YES" : "NO") );
	return res;
}

int main(void)
{
	int N;
	string A;
	int B;
	
	cin >> N;
	for(int i = 0 ; i < N; i++)
	{
		cin >> A >> B;
		cout << cmp(A, B) << endl;
	}
	
	return 0;
}
