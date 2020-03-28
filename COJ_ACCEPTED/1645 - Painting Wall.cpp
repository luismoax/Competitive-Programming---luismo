/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 1645 - Painting Wall
    Online Judge: COJ
    Idea: Read all queries and process them in reverse order. When needed to "paint" an interval
	chekc if there is a spot in it that hasn´t been painted, if so it means that the color
	we are about to paint will remain, there for count it.
	Use a Segment Tree to represent the Wall, update means "paint" and retrieve means "check"
	
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e6 + 3;
int tc, M;
// query bouds
int QL, QR;

struct node
{
	int white;
	bool lazy;
	node(){white = 0; lazy = 0;}
} t[lim << 2];

inline int ls(int idx){return (idx << 1) + 1;}
inline int rs(int idx){return (idx << 1) + 2;}
inline int middle(int L, int R){return (L + R) >> 1;}

void buildTree(int idx, int L, int R)
{
	t[idx].lazy = false;
	// if leaf
	if(L == R)
	{
		t[idx].white = 1;
		return;
	}
	int mid = middle(L , R);
	buildTree(ls(idx), L, mid);
	buildTree(rs(idx), mid + 1, R);
	// merge
	t[idx].white = t[ls(idx)].white + t[rs(idx)].white;
}

void propagate(int idx, int L, int R)
{
	if(t[idx].lazy)
	{
		t[idx].white = 0;
		// if not leaf
		if(L != R)
		{
			t[ls(idx)].lazy = true;
			t[rs(idx)].lazy = true;
		}
	}
	t[idx].lazy = false;
}

void update(int idx, int L, int R)
{
	// propagate first
	propagate(idx, L, R);
	// if contained
	if(L >= QL && R <= QR)
	{
		t[idx].white = 0;
		// if not leaf
		if(L != R)
		{
			t[ls(idx)].lazy = true;
			t[rs(idx)].lazy = true;
		}
		return;
	}
	// if outside
	if(L > QR || R < QL)
		return;
	int mid = middle(L, R);
	// update both subtrees
	update(ls(idx), L, mid);
	update(rs(idx), mid + 1, R);
	// merge
	t[idx].white = t[ls(idx)].white + t[rs(idx)].white;
}

int retrieve(int idx, int L, int R)
{
	// propagate first
	propagate(idx, L, R);
	// if contained
	if(L >= QL && R <= QR)
		return t[idx].white;
	// if outside
	if(L > QR || R < QL)
		return 0;
	int mid = middle(L, R);
	return retrieve(ls(idx), L, mid) + retrieve(rs(idx), mid + 1, R);
}

struct p
{
	int x, y;
	p(){}
} arr[100001];


void solve()
{
	cin >> tc;

	while(tc-->0)
	{
		int colors = 0; // colors to see
		int maxY = -1;

		cin >> M;
		// reading queries
		for(int i = 0; i < M; i++)
		{
			cin >> arr[i].x >> arr[i].y;
			maxY = max(maxY, arr[i].y);
		}

		// build the segment tree
		buildTree(0, 0, maxY - 1);

		// taking queries backwards
		for(int i = M - 1; i >= 0; i--)
		{
			QL = arr[i].x - 1;
			QR = arr[i].y - 1;

			int c = retrieve(0, 0, maxY - 1);
			if(c > 0)
				colors++;
			update(0, 0, maxY - 1);
		}

		cout << colors << "\n";
	}


}


void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("d:\\lmo.in","r",stdin);
	// freopen("d:\\lmo.out","w",stdout);
}

int main()
{
    // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}