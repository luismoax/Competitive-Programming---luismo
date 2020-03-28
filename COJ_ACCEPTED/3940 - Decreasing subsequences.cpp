/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3940 - Decreasing subsequences
	Online Judge: COJ
	Idea: DP + SegmentTree
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
const int mod = 1000000007;

int tc, N;
ll arr[lim];

// >> SegmentTree
ll t[lim << 2];

inline int ls(int i) {return (i << 1) + 1;}
inline int mid(int L, int R) {return (L + R) >> 1;}

void build(int idx, int L, int R)
{
	if(L == R)
	{
		t[idx] = 0;
		return;
	}
	int le = ls(idx);
	int ri = le + 1;
	int mp = mid(L, R);
	build(le, L, mp);
	build(ri, mp + 1, R);
	t[idx] = 0;
}

void update(int idx, int L, int R, int ii, ll upd)
{
	if(L == R)
	{
		t[idx] = (t[idx] + upd) % mod;
		return;
	}
	int le = ls(idx);
	int ri = le + 1;
	int mp = mid(L, R);

	if(ii <= mp)
		update(le, L, mp, ii, upd);
	else update(ri, mp + 1, R, ii, upd);
	// merge
	t[idx] = (t[le] + t[ri]) % mod;
}

ll retrieve(int idx, int L, int R, int QL, int QR)
{
	if(L >= QL && R <= QR)
		return t[idx] % mod;
	if(L > QR || R < QL)
		return 0;

	int le = ls(idx);
	int ri = le + 1;
	int mp = mid(L, R);


	ll solLeft = retrieve(le, L, mp, QL, QR);
	ll solRight = retrieve(ri, mp + 1, R, QL, QR);

	return (solLeft + solRight) % mod;
}
// >> SegmentTree

// >> coordinates compression
map<ll, int> m;
ll ccomp[lim];
// << coordinates compression

void solve()
{
    cin >> tc;
    while(tc-->0)
    {
        cin >> N;

        // clear the map and building the SegmentTree
        m.clear();
        build(0, 0, N);

        // reading numbers
        for(int i = 0; i < N; i++)
        {
            cin >> arr[i];
            ccomp[i] = arr[i];
        }

        // sort 'em all
        sort(ccomp, ccomp + N);

        int cnt = 0;
        // compressing
        for(int i = 0; i < N; i++)
        {
            if(i == 0 || ccomp[i] != ccomp[i - 1])
            {
                cnt++;
                m[ccomp[i]] = cnt;
            }
        }

        ll answ = 0;

        // linear scan
        for(int i = 0; i < N; i++)
        {
            ll x = arr[i];
            // find the number of decreasing sequences ending in a greater number
            int aux = m[x];

            ll amount = (retrieve(0, 0, N, aux + 1, cnt) + 1) % mod;

            answ = (answ + amount) % mod;

            // update in the tree
            update(0, 0, N, aux, amount);
        }

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
