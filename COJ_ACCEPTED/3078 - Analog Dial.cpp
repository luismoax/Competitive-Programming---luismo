/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3078 - Analog Dial
    Online Judge: COJ
    Idea: Use a Segment Tree with Lazy Propagation. On each node keep an array to store the frequency of digits
	from 0 to 9.
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

const int lim = 250000 + 5;
int N, M, A, B;

int arr[lim]; // array of values

// ... SEGMENT TREE
struct node
{
	int amount[10], sum;
	int L, R, lazy;
	node(){}
};
node tree[lim << 2];

inline int ls(int idx){return (idx<<1)|1;}
inline int rs(int idx){return (idx<<1) + 2;}

void buildTree(int idx,int L, int R)
{
	tree[idx].L = L; tree[idx].R = R;
	// if leaf
	if(L == R)
	{
		tree[idx].amount[arr[L]] = 1;
		tree[idx].sum = arr[L];
		return;
	}
	int mid = (L + R) >> 1;
	buildTree(ls(idx), L, mid);
	buildTree(rs(idx), mid + 1, R);

	// Merging
	for(int i = 0; i < 10; i++)
		tree[idx].amount[i] = tree[ls(idx)].amount[i] + tree[rs(idx)].amount[i];
	tree[idx].sum = tree[ls(idx)].sum + tree[rs(idx)].sum;
}

// propagation
void propagate(int idx)
{
	if(tree[idx].lazy > 0)
	{
		// updating frequencies values
		int auxx[10]; // auxiliar array
		int load = tree[idx].lazy; // next value jump
		memset(auxx, 0, sizeof auxx); // reset
		
		// updating new frequencies and value of the sum		
		for(int i = 0; i < 10; i++)
		{
			int nxt = (i + load) % 10;
			auxx[nxt] = tree[idx].amount[i];
		}
		int auxSum = 0;		
		for(int i = 0; i < 10; i++)
		{
			tree[idx].amount[i] = auxx[i];
			auxSum += auxx[i] * i;
		}
		tree[idx].sum = auxSum;


		// if not leaf propagate
		if(tree[idx].L != tree[idx].R)
		{
			tree[ls(idx)].lazy += tree[idx].lazy;
			tree[rs(idx)].lazy += tree[idx].lazy;
		}
	}
	tree[idx].lazy = 0; // reset lazyness
}

int retrieve(int idx, int QL, int QR)
{
	// first of all propagate
	propagate(idx);

	// if outside
	if(tree[idx].L > QR || tree[idx].R < QL)
		return 0;

	// if inside
	if(tree[idx].L >= QL && tree[idx].R <= QR)
	{
		int ret = tree[idx].sum; // current sum (value to return)

		// updating current values
		int auxx[10]; // auxiliar array
		int load = 1; // next value jump
		memset(auxx, 0, sizeof auxx);
		
		// updating new frequencies and value of the sum		
		for(int i = 0; i < 10; i++)
		{
			int nxt = (i + load) % 10;
			auxx[nxt] = tree[idx].amount[i];
		}
		int auxSum = 0;
		for(int i = 0; i < 10; i++)
		{

			tree[idx].amount[i] = auxx[i];
			auxSum += auxx[i] * i;
		}
		tree[idx].sum = auxSum;

		// if not leaf
		if(tree[idx].L != tree[idx].R)
		{
			tree[ls(idx)].lazy++;
			tree[rs(idx)].lazy++;
		}

		return ret;
	}
	
	int ret = retrieve(ls(idx), QL, QR) + retrieve(rs(idx), QL, QR);
	// Merging
	for(int i = 0; i < 10; i++)
		tree[idx].amount[i] = tree[ls(idx)].amount[i] + tree[rs(idx)].amount[i];
	tree[idx].sum = tree[ls(idx)].sum + tree[rs(idx)].sum;

	return ret;
}

char str[lim];
void solve()
{
	sf("%d%d", &N, &M);

	sf("%s", str);
	// reading values
	for(int i = 0; i < N; i++)
		arr[i] = str[i] - '0';

	// build Segment Tree
	buildTree(0, 0, N - 1);

	// reading queries
	for(int i = 0; i < M; i++)
	{
		sf("%d%d", &A, &B);
		A--; B--;

		int answ = retrieve(0,A, B);
		pf("%d\n", answ);
	}
}


void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("d:\\redoks\\redoks.in","r",stdin);
}

int main()
{
    // open_file();

    solve();
}
