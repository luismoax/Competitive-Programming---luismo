/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Wesley's Anger Contest 6 Problem 3 - Difference Sorting
	Link: https://dmoj.ca/problem/wac6p3
	Online Judge: dmoj.ca
	Idea: Nice Problem, reducted to RMQ (used a Segment Tree).
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
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
const ll inf = 1e18 + 5;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;


// MIN / MAX SegmentTree - Point Update

ll mx[lim << 2];
ll mn[lim << 2];

void update(int idx, int L, int R, int ii, ll upd)
{
    if(L == R)
    {
        mx[idx] = mn[idx] = upd;
        return;
    }
    int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
    if(ii <= mid)
        update(le, L, mid, ii, upd);
    else update(ri, mid + 1, R, ii, upd);
    // merge
    mx[idx] = max(mx[le], mx[ri]);
    mn[idx] = min(mn[le], mn[ri]);
}

pll retrieve(int idx, int L, int R, int QL, int QR)
{
    if(L >= QL && R <= QR)
        return mkp(mx[idx], mn[idx]);

    if(L > QR || R < QL)
        return mkp(-1, mod + 59);

    int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;

    pll s1 = retrieve(le, L, mid, QL, QR);
    pll s2 = retrieve(ri, mid + 1, R, QL, QR);
    // merge
    pll ret = mkp(max(s1.first, s2.first), min(s1.second, s2.second));
    return ret;
}

int N;
pll ai[lim];
pll srt[lim];
map<ll, int> comp;
vector<ll> sing;

void solve()
{
	cin >> N;

	int cnt = 1;
	for(int i = 1; i <= N; i++)
	{
		cin >> ai[i].fi;
		ai[i].se = i;

		srt[i].fi = ai[i].fi;		
		srt[i].se = ai[i].se;		

		ll k = ai[i].fi;

		if(comp.find(k) == comp.end())
		{
			comp[k] = cnt++;
			sing.push_back(k);
		}
	}

	// sort em' all
	sort(srt, srt + N + 1);
	sort(sing.begin(), sing.end());

	for(int i = 0; i < sing.size(); i++)
	{
		int pos = i + 1;
		comp[sing[i]] = pos;

		if(i > 0)
			update(0, 0, N + 3, pos, sing[i] - sing[i-1]);
	}

	ll answ = 0;

	for(int i = 1; i <= N; i++)
	{
		if(srt[i].fi != ai[i].fi)
		{
			ll mx = max(ai[i].fi, srt[i].fi);
			ll mn = min(ai[i].fi, srt[i].fi);

			int le = comp[mn] + 1;
			int ri = comp[mx];

			pll k = retrieve(0, 0, N + 3, le, ri);
			
			answ = max(k.fi, answ);
		}
	}
	cout << answ << endl;
}
 
void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}
 
void IO()
{

	if(fopen("c:\\Competitive Programming\\lmo.in","r") != NULL)
	{
		freopen("c:\\Competitive Programming\\lmo.in","r",stdin);
	}
	else if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("media/Beijing/lmo.in","r") != NULL)
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