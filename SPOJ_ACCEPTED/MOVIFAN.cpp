/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: https://www.spoj.com/problems/MOVIFAN/
	Online Judge: SPOJ
	Idea: DP + Fenwick Tree. dp[i] - number of ways of watch at least 1 show when the last watched is the i-th
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
const int mod = 1e9 + 7;
const int lim = 3e5 + 2;


int tc, N, len;
ll shows[lim];

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
                tree[i] = (tree[i] + upd) % mod;
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
            return (retrieve(b) - retrieve(a - 1) + mod) % mod;
        }
};
FenwickTree * ft;

// dp[i] - number of ways of watch at least 1 show when the last watched is the i-th
ll dp[lim];

void solve()
{
	cin >> tc;
	while(tc-->0)
	{
		cin >> N >> len;
		// reading shows
		for(int i = 1; i <= N; i++)
			cin >> shows[i];
		// sort 'em all
		sort(shows, shows + N);
		// create the Fenwick Tree
		ft = new FenwickTree(N + 1);
		// for each possible starting time (in order)
		for(int i = 1; i <= N; i++)
		{
			// find the (upper_bound) most left show which overlaps it
			int le = 1, ri = i - 1;
			while(le < ri)
			{
				int mid = (le + ri) / 2;
				if(shows[mid] + len <= shows[i])
					le = mid + 1;
				else ri = mid;
			}
			// lst is the last show which overlaps current starting time
			ll lst = shows[le]+len > shows[i] ? le - 1: le;
			// find the sum of the answers until it 
			ll q = ft->retrieve(1, lst);
			// set dp value
			dp[i] = (1 + q) % mod;
			// update the Fenwick Tree
			ft->update(i, dp[i]);
		}
		// find answer
		ll answ = ft->retrieve(1, N);
		// print answer
		cout << answ << endl;
	}
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
