/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 4105 - Elemento Faltante
	Online Judge: COJ
	Idea: Algebra
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 1e7 + 2;

ll n;

void solve()
{
    cin >> n;
    ll sum = 0;
    for(int i = 0; i < n-1; i++)
    {
        ll k; cin >> k;
        sum += k;
    }

    ll tri = (n*(n+1))/2;

    cout << tri - sum;

}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
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

	fastIO();

	solve();
}
