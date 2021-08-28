/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Sum of Four Values
	Link: https://cses.fi/problemset/task/1642
	Online Judge: CSES
	Idea: O(N^2*LogN). See implementation, watch some corner cases
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
#define M_PI 2.0 * acos(0)
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 1e5 + 3;

int n, x;
int arr[lim];

void solve()
{
	cin >> n >> x;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

    // map to keep sums of pairs 
	map<int, pii> mp;
	bool ok = false;
    // for each i
	for(int i = 0; !ok && i < n; i++)
	{
        // auxiliar map
		map<int, pii> auxMp;
		for(int j = i + 1; !ok && j < n; j++)
		{
			int sm = arr[i] + arr[j];

			if(mp.find(x - sm) != mp.end())
			{
				pii p = mp[x - sm];

				int le = p.fi;
				int ri = p.se;

				if(le != i && le != j && ri != i && ri != j)
				{
					cout << le + 1  << " " << ri + 1 << " " << i + 1 << " " << j + 1 << endl;
					ok = 1;
				}
			}

			auxMp[sm] = mkp(i, j);
		}

		for(auto item: auxMp)
		{
			mp[item.fi] = item.se;
		}
	}
	if(!ok)
		cout << "IMPOSSIBLE" << endl;
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
		// freopen("d:\\lmo.out","w",stdout);
	}
	else if(fopen("/Wolfburg/lmo.in","r") != NULL)
	{
		freopen("/Wolfburg/lmo.in", "r", stdin);
	}
}

int main()
{
	IO();

	fastIO();

	solve();
}
