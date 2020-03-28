/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3526 - Unordered list I
	Online Judge: COJ
	Idea: Sweep Line, offline queries, BIT. ~ KQUERY
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e5 + 7;
int N;
int ft[lim];

inline int lowBit(int i){return i & -i;}

void update(int idx, int v)
{
	for(int i = idx; i < lim; i+=lowBit(i))
		ft[i]+=v;
}

int retrieve(int idx)
{
	int sum = 0;
	for(int i = idx; i > 0; i-= lowBit(i))
		sum+= ft[i];
	return sum;

}

struct p
{
	int pos, val;
	p(){}
	p(int p, int v){pos = p; val = v;}
} arr[lim];

// compare by value
bool cmp(p a, p b)
{
	if(a.val == b.val)

		return a.pos > b.pos;


	return a.val < b.val;
}

int answ[lim];

void solve()
{
	cin >> N;
	// reading
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i].val;
		arr[i].pos = i + 1;
	}

	// sort em all
	sort(arr, arr + N, cmp);
/*
	for(int i = 0; i < N; i++)
		cout << arr[i].val << " " << arr[i].pos << endl;
*/
	// sweep line backwards
	for(int i = N - 1; i >= 0; i--)
	{
		int pos = arr[i].pos;
		int val = arr[i].val;

		int tmp = retrieve(N) - retrieve(pos);

		answ[pos] = tmp;

		update(pos, 1);
	}


	// printing answer
	for(int i = 1; i <= N; i++)
		if(i == 1)
			cout << answ[i];
		else cout << " " << answ[i];


}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
		freopen("d:\\lmo.in","r",stdin);

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
