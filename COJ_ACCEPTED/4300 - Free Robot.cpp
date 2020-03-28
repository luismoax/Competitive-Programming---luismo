/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: 4300 - Free Robot
	Online Judge: COJ
	Idea: Pre-Computed all values
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
const int lim = 100 + 2;

int tc;
int N;


ll sol [] = {
3,
15,
75,
391,
2065,
11091,
60215,
330003,
1820869,
10103153,
56313047,
315071801,
1768489771,
9953853677
};

void solve()
{
    cin >> tc;
    int cs = 1;
    while(tc-- > 0)
    {
        cin >> N;
        cout << sol[N - 1] << endl;
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
