/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: DMOPC '20 Contest 3 P2 - Bob and Parallel-Ks
	Link: https://dmoj.ca/problem/dmopc20c3p2
	Online Judge: dmoj.ca
	Idea: Sort + Binary Search
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
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;

int N, M, K;

void solve()
{
	cin >> M >> N >> K;
	
	// map< pair<pii,int> , int> mp;
	vector< pair<pii,int> > v;
	int answ = 0;
	for(int i = 0; i < M; i++)
	{
		int prev = 0;
		int note = 0;

		for(int j = 0; j < N; j++)
		{			
			prev = note;
			cin >> note;
			if(j > 0)
			{
				pair<pii,int> curr = mkp(mkp(prev, note), j);
				
				v.push_back(curr);
			}
		}
	}

	sort(v.begin(), v.end());

	for(auto item: v)
	{
		pii p = item.fi;
		int pos = item.se;

		pii src1 = mkp(p.fi - K, p.se - K);
		pii src2 = mkp(p.fi + K, p.se + K);

		int cnt1 = upper_bound(v.begin(), v.end(), mkp(src1, pos)) - lower_bound(v.begin(), v.end(), mkp(src1, pos));
		int cnt2 = upper_bound(v.begin(), v.end(), mkp(src2, pos)) - lower_bound(v.begin(), v.end(), mkp(src2, pos));

		answ += cnt1 + cnt2;
	}

	cout << answ / 2 << endl;
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