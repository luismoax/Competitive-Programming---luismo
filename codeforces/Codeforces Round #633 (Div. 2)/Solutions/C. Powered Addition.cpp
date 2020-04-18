/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: C. Powered Addition
	Link: https://codeforces.com/contest/1339/problem/C
	Online Judge: codeforces.com
	Idea: O(N). Keep in mind that every number can be represented
    as a single sum of Powers Of Two... dammm !!!
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
const ll inf = 1e7 + 3;
const int mod = 1e9 + 7;
const int lim = 2e5 + 2;

int tc, n;

void solve()
{
	cin >> tc;
	while(tc-- > 0)
	{
		cin >> n;
		vector<ll> vect(n, 0);
		for(int i = 0; i < n; i++)
		{
			cin >> vect[i];
		}

		ll mx = vect[0];
		int tm = 0;
		for(int i = 1; i < n; i++)
		{
			if(vect[i] > mx)
			{
				mx = vect[i];
			}
			else if(vect[i] < mx)
			{
				ll diff = mx  - vect[i];
				int lg = log2(diff);
				tm = max(lg + 1, tm);
			}
		}

		cout << tm << endl;
	}
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
