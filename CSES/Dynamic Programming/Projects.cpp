/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Projects
	Link: https://cses.fi/problemset/task/1140
	Online Judge: CSES
	Idea: Coordinates Compression + Linear Scan + DP.
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
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 2e5 + 2;

int n, ai, bi, pi;

struct project
{
	int beg, fin, reward;
	project(){}
	project(int b, int f, int r)
	{beg = b; fin = f; reward = r;}
};

bool cmp(project a, project b)
{
	if(a.fin == b.fin)
		return a.beg < b.beg;
	return a.fin < b.fin;
}
// to store projects
vector<project> projs;
// to compress coordinates
set<int> rbTree;

void solve()
{
	cin >> n;
    // reading projects
	for(int i = 0; i < n; i++)
	{
		cin >> ai >> bi >> pi;
		projs.push_back(project(ai, bi, pi));
		rbTree.insert(ai);
		rbTree.insert(bi);
	}

	// compress coordinates
	map<int, int> comp;
	int cnt = 1;
	for(auto item: rbTree)	
		comp[item] = cnt++;

	// sort em' all
	sort(projs.begin(), projs.end(), cmp);
    // dp[i] - the maximun reward at time i
	vector<ll> dp(cnt);

	ll answ = 0;
	int idx = 0;
	for(int i = 1; i < cnt; i++)
	{
		ll curr = dp[i-1];
        // for each project ending at i
        // update dp[i] = current project's reward + the best achieved before
        // its start
		while(idx < projs.size() && comp[projs[idx].fin] == i)
		{
			int f = comp[projs[idx].beg];
			ll k = projs[idx].reward + dp[f - 1];
			curr = max(curr, k);
			idx++;
		}
		dp[i] = curr;
	}

	cout << dp[cnt - 1];
	
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	if(fopen("c:\\Users\\LUISMO\\lmo.in","r") != NULL)
	{
		freopen("c:\\Users\\LUISMO\\lmo.in","r",stdin);
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
