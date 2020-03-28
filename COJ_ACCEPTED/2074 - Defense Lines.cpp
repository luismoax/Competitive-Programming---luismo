/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 2074 - Defense Lines
	Online Judge: COJ
	Idea: Coordinates compression + DP + Segment Tree.
	1. dpBackwards[i] - stores the longest continuos increasing sequence (LCIS) starting at position i;
	2. since coordinates are compressed every value will be between [1...2*10^5], we build a SegmentTree
	suche that when querying from QL to QR it will return the greatest LCIS that ends with value less or equal than QR.
	3. we perform linear scan, at position i, the best value will be the query in the ST from [0 to (arr[i] - 1)]
	plus dpBackwards[i] which means the best LCIS ending at a value less or equal than arr[i] - 1 plus the best LCIS that starts at position i.

*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 2e5 + 7;

int arr[lim];
int arrSrt[lim];

int tc, N;

map<int, int> m;

// >> SEGMENT TREE
int t[lim << 2];
void update(int idx, int L, int R, int ii, int upd)
{
    if(L == R)
    {
        //
        t[idx] = max(t[idx] ,upd);
        return;
    }
    int le = idx * 2 + 1;
    int ri = idx * 2 + 2;
    int mid = (L + R) >> 1;

    if(ii <= mid)
        update(le, L, mid, ii, upd);
    else update(ri, mid + 1, R, ii, upd);
    // merge
    t[idx] = max(t[le], t[ri]);
}

int retrieve(int idx, int L, int R, int QL, int QR)
{
    // if contained
    if(L >= QL && R <= QR)
        return t[idx];
    // if outside
    if(L > QR || R < QL)
        return 0;
    int le = idx * 2 + 1;
    int ri = idx * 2 + 2;
    int mid = (L + R) >> 1;
    return max( retrieve(le, L, mid, QL, QR), retrieve(ri, mid + 1, R, QL, QR) );
}
// << SEGMENT TREE

int dpBackwards[lim];

void reset()
{
    memset(t, 0, sizeof t);
    memset(dpBackwards, 0, sizeof dpBackwards);
    m.clear();
}

void solve()
{
    cin >> tc;
    while(tc--)
    {
        cin >> N;

        reset();

        // reading integers
        for(int i = 0; i < N; i++)
        {
            cin >> arr[i];
            arrSrt[i] = arr[i];
        }
        // compress coordinates
        int cnt = 1;
        sort(arrSrt, arrSrt + N);
        for(int i = 0; i < N; i++)
            if(m.find(arrSrt[i]) == m.end())
                m[arrSrt[i]] = cnt++;

        for(int i = 0; i < N; i++)
            arr[i] = m[arr[i]];
        // end compression

        // backwards DPp
        for(int i = N - 1; i >= 0; i--)
        {
            if(i == N - 1 || arr[i] >= arr[i + 1])
                dpBackwards[i] = 1;
            else dpBackwards[i] = dpBackwards[i + 1] + 1;
        }

        int answ = -0;
        int sum = 0;
        // linear scan
        for(int i = 0; i < N; i++)
        {
            if(i == 0 || arr[i] <= arr[i - 1])
                sum = 1;
            else sum++;

            // retrieve from the SegmentTree
            int before = retrieve(0, 0, N, 0, arr[i] - 1);

            answ = max(answ, before + dpBackwards[i]);

            // update in the SegmentTree
            update(0, 0, N, arr[i], sum);

        }
        // printing answer
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
