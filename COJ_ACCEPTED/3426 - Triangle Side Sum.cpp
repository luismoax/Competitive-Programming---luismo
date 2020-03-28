/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3426 - Triangle Side Sum
	Online Judge: COJ
	Idea: Find the lowest and the greatest among the possible values. Print the sum
	of the integers between those numbers
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
const int lim = 2e5 + 2;

ll A, B;


void solve()
{
    cin >> A >> B;

    if(A > B)
        swap(A, B);

    ll mn = B - A + 1;
    ll mx = A + B - 1;

    ll answ = (mn + mx)*(mx - mn + 1) / 2;

    cout << answ << endl;
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
