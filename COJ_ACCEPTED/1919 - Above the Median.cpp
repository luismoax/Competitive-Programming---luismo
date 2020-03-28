/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1919 - Above the Median
	Online Judge: COJ
	Idea: Data Structure. First of all, face the problem like this.
	For each number is greater than X, turn it into 1 otherwise turn it into -1.
	Now the problem is to find the number of intervals with more 1 than -1. It can be done using a Segment Tree + Linear Scan.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e6 + 7;


struct SegmentTree
{
    int * t;
    int len;
    SegmentTree(int l)
    {
        len = l;
        t = new int[len << 2];
        fill(t, t + (len << 2), 0);
    }

    inline int ls(int idx){return (idx << 1) + 1;}
    inline int rs(int idx){return (idx << 1) + 2;}
    int mp(int l, int r) {return (l + r) >> 1;}

    void update(int idx, int L, int R, int ii, int upd)
    {
        int le = ls(idx), ri = rs(idx), mid = mp(L, R);
        if(L == R)
        {
            t[idx]+= upd;
            return;
        }
        if(ii <= mid)
            update(le, L, mid, ii, upd);
        else update(ri, mid + 1, R, ii, upd);
        // merge
        t[idx] = t[le] + t[ri];
    }

    void update(int ii, int upd)
    {
        update(0, 0, len - 1, ii, upd);
    }

    int retrieve(int idx, int L, int R, int QL, int QR)
    {
        int le = ls(idx), ri = rs(idx), mid = mp(L, R);
        // if contained
        if(L >= QL && R <= QR)
            return t[idx];
        // if outside
        if(L > QR || R < QL)
            return 0;
        int a1 = retrieve(le, L, mid, QL, QR);
        int a2 = retrieve(ri, mid + 1, R, QL, QR);
        return a1 + a2;
    }

    int retrieve(int QL, int QR)
    {
        return retrieve(0, 0, len - 1, QL, QR);
    }
};

int arr[lim], N, X;

void solve()
{
    cin >> N >> X;
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
        if(arr[i] >= X) arr[i] = 1;
        else arr[i] = -1;
    }

	// to store values of sums
    SegmentTree positive = SegmentTree(N + 3);
    SegmentTree negative = SegmentTree(N + 3);

    // final answer
    ll answ = 0;
    // current sum
    int sum = 0;
    
	// needed
    positive.update(0, 1);

    for(int i = 0; i < N; i++)
    {
        sum+= arr[i];

        if(sum >= 0)
        {
            int aux = negative.retrieve(0, N + 1) + positive.retrieve(0, sum);
            answ += aux;
            positive.update(sum, 1);
        }
        else
        {
            int aux = negative.retrieve(-sum, N + 1);
            answ += aux;
            negative.update(-sum, 1);
        }
    }
    // printing the answer
    cout << answ;
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
