/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 4078 - Buyers Search
	Online Judge: COJ
	Idea: RMQ + Binary Search
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 1e5 + 7;

int tc, N, H, P, A, B;
int ci[lim];

// RMQ Sparse Table >>
int sparseTable[lim][20];

void buildSparseTable()
{
    for(int i = 0; i < N; i++)
        sparseTable[i][0] = ci[i];

    for(int pw = 1; (1<<pw) <= N; pw++)
    {
        // for each position
        for(int i = 0; i + (1<<pw) - 1 < N; i++)
            sparseTable[i][pw] =
                max(sparseTable[i][pw-1], sparseTable[i+(1<<(pw-1))][pw-1]);
    }
}

int query(int a, int b)
{
    if(a > b) swap(a, b);

    int blockLen = log2(b - a + 1);

    int a1 = sparseTable[a][blockLen];
    int a2 = sparseTable[b - (1<<blockLen) + 1][blockLen];

    return max(a1, a2);
}

// RMQ Sparse Table <<

void solve()
{
    cin >> N;
    // reading money
    for(int i = 0; i < N; i++)
        cin >> ci[i];

    // build the sparse Table
    buildSparseTable();

    cin >> H;
    // reading houses
    for(int i = 0; i < H; i++)
    {
        cin >> P >> A >> B;
        A--; B--;

        // Binary Search over the interval
        int le = A, ri = B;

        while(le != ri)
        {
			// mid point
            int mid = (le+ri) >> 1;
			// query the interval from the beginning to the mid point
            int q = query(le, mid);
			// if there exist an elemente in it with value greater
			// than P, I can still move left
            if(q >= P)
            {
                ri = mid;
            }
			// if not, then look to the right
            else le = mid + 1;
        }
		// if the element found has value greater than P
		// (because it might not exist)
        if(ci[le] >= P)
            cout << le + 1 << endl;
		// 
        else cout << -1 << endl;
    }
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
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

	fastIO();

	solve();
}
