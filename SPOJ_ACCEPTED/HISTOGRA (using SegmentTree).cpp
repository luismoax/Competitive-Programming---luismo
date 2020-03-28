/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: HISTOGRA
	Online Judge: COJ
	Idea: Using Divide And Conquer Solution.
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

int tc, N;

ll arr[lim];
// >> SEGMENT TREE
ll t[lim << 2];

inline int ls(int i) { return (i * 2) + 1; }
inline int mid(int L, int R) { return (L + R) / 2; }

void buildTree(int idx, int L, int R)
{
    if(L == R)
    {
        t[idx] = L;
        return;
    }
    int mp = mid(L, R);
    int le = ls(idx), ri = le + 1;
    // build boths subtrees
    buildTree(le, L, mp);
    buildTree(ri, mp + 1, R);
    // merge
    if(arr[t[le]] < arr[t[ri]])
        t[idx] = t[le];
    else t[idx] = t[ri];
}

ll retrieveMinIdx(int idx, int L, int R, int QL, int QR)
{
    if(L >= QL && R <= QR)
        return t[idx];

    if(L > QR || R < QL)
        return -1;
    // mid point
    int mp = mid(L, R);
    // child pointers
    int le = ls(idx), ri = le + 1;

    //
    ll sol1 = retrieveMinIdx(le, L, mp, QL, QR);
    ll sol2 = retrieveMinIdx(ri, mp + 1, R, QL, QR);

    // If non-valid solutions return the valid ones
    if(sol1 == -1)
        return sol2;
    if(sol2 == -1)
        return sol1;
    // if valid solutions return the best
    if(arr[sol1] < arr[sol2])
        return sol1;
    return sol2;
}
// << SEGMENT TREE

ll DivideAndConquerSolution(int QL, int QR)
{
    // base uncase
    if(QL > QR)
        return 0ll;

    // base case
    if(QL == QR)
        return arr[QL];

    // take the minimum value in the interval
    int mn = retrieveMinIdx(0, 0, N - 1, QL, QR);
	// Find solution to the left side
    ll sol1 = DivideAndConquerSolution(QL, mn - 1);
	// Find solution to the right side
    ll sol2 = DivideAndConquerSolution(mn + 1, QR);
	// Take with this minimum height the whole interval as a third possible solution
    ll sol3 = (QR - QL + 1) * arr[mn];
	// return the greatest solution
    return max( max(sol1, sol2), sol3 );
}


void solve()
{
    while(1)
    {
        cin >> N;

        if(N == 0) return;

        // reading heights
        for(int i = 0; i < N; i++)
            cin >> arr[i];

        // build the SegmentTree
        buildTree(0, 0, N - 1);


        // perform Divide And Conquer Solution
        ll answ = DivideAndConquerSolution(0, N - 1);

        cout << answ << "\n";
    }
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
	}

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
