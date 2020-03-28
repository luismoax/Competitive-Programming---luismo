/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: https://www.spoj.com/problems/INCSEQ/
	Online Judge: SPOJ
	Idea: Fenwick Tree + DP. Nice. Used 50 Fenwick Trees.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e16 + 3;
const int mod = 5000000;
const int lim = 2e5 + 7;

int N, K;
int arr[lim];

class FenwickTree
{
    private:
        vector<ll> tree;
        inline int lowBit(int i) {return i&-i;}

    public:

        FenwickTree(){}

        FenwickTree(int len)
        {
            tree.resize(len, 0);
        }

        FenwickTree(int len, int v)
        {
            tree.resize(len, v);
        }

        void update(int idx, ll upd)
        {
            for(int i = idx; i < tree.size(); i+= lowBit(i))
                tree[i]= (tree[i] + upd) % mod;
        }

        ll retrieve(int idx)
        {
            ll sum = 0;
            for(int i = idx; i > 0; i-= lowBit(i))
                sum = (sum + tree[i]) % mod;
            return sum;
        }

        ll retrieve(int a, int b)
        {
            if(a > b)
                return 0;
            return retrieve(b) - retrieve(a - 1);
        }
};

FenwickTree * fts[51];

void solve()
{
    cin >> N >> K;

    for(int i = 1; i <= N; i++)
        cin >> arr[i];
    for(int i = 1; i <= N; i++)
        arr[i]++;

    for(int i = 0; i <= K; i++)
        fts[i] = new FenwickTree(100003);

    for(int i = 1; i <= N; i++)
    {
        // for each possible K;
        for(int j = K; j > 0; j--)
        {
            ll ax = fts[j-1]->retrieve(1, arr[i] - 1);
            fts[j]->update(arr[i], ax);
        }
        fts[1]->update(arr[i], 1);
    }

    ll answ = fts[K]->retrieve(1, 100001);
    cout << answ;
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("/media/Beijing/lmo.in","r") != NULL)
	{
		freopen("/media/Beijing/lmo.in", "r", stdin);
	}
}

int main()
{
	IO();

	fastIO();

	solve();
}
