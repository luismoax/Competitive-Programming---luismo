/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: KQUERY
    Online Judge: SPOJ
    Idea: Offline Queries. Binary Indexed Tree. Sweep backwards
*/
#include <iostream>
#include <cstdio>
// Containers
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
// Algorithm
#include <algorithm>
#include <cstring>
#include <cmath>
// Constants
#define MAXN 1000001
#define MOD 1000000007
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define nint(i) sf("%d",&i);
#define nlong(i) sf("%lld",&i);

using namespace std;

const int lim = 3e4 + 5;
const int limQ = 200003;

int N, Q;

// >> BIT
int ft[lim];

inline int low_bit(int idx){return idx & -idx;}

void update(int idx, int v)
{
	for(int i = idx; i <= N; i+= low_bit(i))
		ft[i]+= v;
}

int retrieve(int idx)
{
	int sum = 0;
	for(int i = idx; i > 0; i-= low_bit(i))
		sum+= ft[i];
	return sum;
}
// << BIT

struct query
{
	// type 1 = number
	// type 2 = query
	int i, j, val, type;

	int idx; // original index
}  ;

vector<query> queries;

bool cmpQuery(query f, query s)
{
	if(f.val == s.val)
		return f.type < s.type;
	return f.val < s.val;
}

// to store answers
int answers[limQ];

int x, y, z;

void solve()
{
	cin >> N;

	// reading numbers
	for(int i = 0; i < N; i++)
	{
		cin >> x;
		// setting values of the query
		query q;
		q.val = x;
		q.idx = i + 1;
		q.type = 1;

		queries.push_back(q);
	}

	// reading queries
	cin >> Q;

	for(int i = 0; i < Q; i++)
	{
		cin >> x >> y >> z;
		// setting values of the queries
		query q;
		q.i = x;
		q.j = y;
		q.val = z;
		q.idx = i + 1;
		q.type = 2;

		queries.push_back(q);
	}

	sort(queries.begin(), queries.end(), cmpQuery);

	// sweep backwards
	for(int i = queries.size() - 1; i >= 0; i--)
	{
		query q = queries[i];
		if(q.type == 1)
			update(q.idx, 1);
		else
		{
			answers[q.idx] = retrieve(q.j) - retrieve(q.i - 1);
		}
	}
	// printing answer
	for(int i = 1; i <= Q; i++)
		cout << answers[i] << "\n";

}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("e:\\lmo.in","r",stdin);
	// freopen("e:\\lmo.out","w",stdout);
}

int main()
{
    // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}

