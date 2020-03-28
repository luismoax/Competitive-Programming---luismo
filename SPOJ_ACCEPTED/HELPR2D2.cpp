/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: HELPR2D2
    Online Judge: SPOJ
    Idea: Use a Segment Tree storing in each node the max value of capacity for a single container in a range
	and the sum of the capacities used. When updating, if the LEFT branch contains a max value greater than the
	value to update, take that, otherwise if the RIGHT branch contains a max value greater than the value to 
	update take that.
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

int tc, K, n, r, v, mxCont = 100000;

struct node
{
	int L, R, max, val, sum;
	node(){}

};
node tree[ 4 * 100000 + 3];

inline int ls(int idx){return (idx << 1)|1;}
inline int rs(int idx){return (idx << 1) + 2;}

int usedContainers = 0;

// build the Segment Tree
void buildTree(int idx, int L, int R)
{
	tree[idx].L = L; tree[idx].R = R;

	// if leaf
	if(L == R)
	{
		tree[idx].val = K;
		tree[idx].max = tree[idx].val;
		tree[idx].sum = 0;
		return;
	}

	int mid = (L + R) >> 1;
	buildTree(ls(idx), L, mid);
	buildTree(rs(idx), mid + 1, R);
	// merging
	tree[idx].max = max(tree[ls(idx)].max, tree[rs(idx)].max);
	tree[idx].sum = tree[ls(idx)].sum + tree[rs(idx)].sum;
}

void update(int idx, int upd)
{
	// if node is leaf here goes the UPDATE
	if(tree[idx].L == tree[idx].R)
	{
		if(tree[idx].val == K)
			usedContainers++;

		tree[idx].val -= upd;
		tree[idx].max = tree[idx].val;
		tree[idx].sum = K - tree[idx].val;
		return;
	}

	// if not leaf
	int left = tree[ls(idx)].max; // maximum value of a container to the LEFT
	int right = tree[rs(idx)].max; // maximum value of a container to the RIGHT

	// if can go to the left node
	if(left >= upd)
		update(ls(idx), upd);
	// ELSE if can go to the right node
	else if(right >= upd)
		update(rs(idx), upd);

	// merging
	tree[idx].max = max(tree[ls(idx)].max, tree[rs(idx)].max);
	tree[idx].sum = tree[ls(idx)].sum + tree[rs(idx)].sum;
}


void solve()
{
	// number of testcases
	sf("%d", &tc);

	while(tc-->0)
	{
		// inital capacity of every container
		sf("%d", &K);

		// build Segment Tree
		buildTree(0, 0, mxCont - 1);
		usedContainers = 0;

		// number of arriving containers
		sf("%d", &n);

		int aux = n;

		char str[100]; // to read

		while(aux > 0)
		{
			sf("%s", &str); // read first token

			if(str[0] == 'b')
			{
				sf("%s", &str);
				r = atoi(str);

				sf("%s", &str);
				v = atoi(str);

				for(int i = 0; i < r; i++)
				{
					update(0, v);
					aux--;
				}
			}
			else
			{
				v = atoi(str);				
				update(0, v);
				aux--;
			}

		}

		pf("%d %d\n", usedContainers, K * usedContainers - tree[0].sum);
	}
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("d:\\lmo.in","r",stdin);
}

int main()
{
    // open_file();

    solve();
}
