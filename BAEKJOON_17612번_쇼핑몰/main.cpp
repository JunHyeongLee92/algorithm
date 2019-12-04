#include <stdio.h>
#include <queue>
#define MAX_NUM 100001
#define MAX_ITEM 20

using namespace std;

typedef struct _Person{
	int number = 0;
	int item = 0;
	int counter = 0;
} Person;

struct cmp
{
	bool operator()(Person a, Person b)
	{
		bool ret;
		
		if(a.item == b.item) // if item is equal, bigger counter value
		{
			return (a.counter < b.counter ? true : false);
		}
		else // else smaller item value 
		{
			return (a.item > b.item ? true : false);
		}
	}
};

priority_queue<Person, vector<Person>, cmp> out;

int N, K;
Person customer[MAX_NUM];
int outNumber[MAX_NUM] = {0, };

void solve()
{
	int idx_people = 1;
	int idx_out = 1;
	
	for(idx_people = 1 ; idx_people<=K; idx_people++)
	{
		customer[idx_people].counter = idx_people;
		out.push(customer[idx_people]);
	}

	while(!out.empty())
	{
		Person oldPeople = out.top();
		out.pop();
		
		outNumber[idx_out++] = oldPeople.number; // customer out	
		
		for(int i = 1; i<idx_people; i++)
		{
			customer[i].item -= oldPeople.item;
		}
		
		if(idx_people <= N) // customer in
		{		
			customer[idx_people].counter = oldPeople.counter;
			out.push(customer[idx_people]);
			idx_people++;
		}
	}
	
	for(int i = 1 ; i<=N; i++)
	{
		printf("%d = %d \n", i, outNumber[i]);
	}
}

void calc() // calculate out array 
{
	unsigned long long res = 0;
	
	for(int i = 1; i<=N; i++)
	{
		res += i*outNumber[i];
	}
	printf("%llu", res);
}

int main(void)
{
	scanf("%d %d", &N, &K);
	for(int i = 1; i <= N; i++)
	{
		scanf("%d %d", &customer[i].number, &customer[i].item); 
	}
	solve();
	calc();
	
	return 0;
}
