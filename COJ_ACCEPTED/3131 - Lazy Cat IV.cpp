/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3131 - Lazy Cat IV
    Online Judge: COJ
    Idea: Precompute every Fibonacci's Sons value (an amount of 4005), store them in a set 
	or in a sorted array so a number can be cheked in O(logN) whether belongs to the collection
	or not. Then use a Binary Indexed Tree of a Segment Tree to perform the queries
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

const int lim = 1e5 + 5;

int N, Q, type;
ll arr[lim]; // for original values values

ll fib[lim];
set<ll> fibSons;

void generate()
{
	fib[0] = fib[1] = 1;

	// insert number two
	for(int i = 2; i < 91; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];

		for(int j = 1; j < i; j++)
		{
			ll k = fib[i] + fib[j];
			fibSons.insert(k);
		}
	}
}

// >> BINARY INDEXED TREE
inline int low_bit(int i){return i & -i;}

int fenwick[lim];

void update(int idx, int v)
{
	for(int i = idx; i <= N; i+= low_bit(i))
		fenwick[i]+= v;
}

int retrieve(int idx)
{
	int sum = 0;
	for(int i = idx; i > 0; i-= low_bit(i))
		sum+= fenwick[i];
	return sum;
}

// << BINARY INDEXTED TREE

void solve()
{	
	// generate all numbers
	generate();
	
	cin >> N >> Q;

	// reading values
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];

		// if is a Fibonacci's Sons term
		if(fibSons.find(arr[i]) != fibSons.end())
			update(i + 1, 1);
	}
	// reading queries
	for(int i = 0; i < Q; i++)
	{
		cin >> type;
		// if first type
		if(type == 1)
		{
			int cnt = 0;
			int x,y; cin >> x >> y;
			
			if(x > y) swap(x, y);

			cnt = retrieve(y) - retrieve(x - 1);
			
			cout << cnt << "\n";
		}
		else
		{
			int x; ll y; cin >> x >> y;
			x--;

			// if y IS a Fibonacci's Sons term
			if(fibSons.find(y) != fibSons.end())
			{
				// if there is not a Fibonacci's Sons term at index x
				if(fibSons.find(arr[x]) == fibSons.end())
				{
					update(x + 1, 1);
				}
			}
			// if y IS NOT a Fibonacci's Sons term
			else
			{
				// if there is a Fibonacci's Sons term
				if(fibSons.find(arr[x]) != fibSons.end())
					update(x + 1, -1);
			}

			arr[x] = y;
		}
	}
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("e:\\lmo.in","r",stdin);
}

int main()
{
    // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
