/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem:
	Online Judge:
	Idea:
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
const ll infinite = 1e18 + 3;
const int mod = 1e9 + 7;
const int lim = 2e5 + 2;


ll X, Y, Z, W;


int arr[] = {2, 4, 8, 3, 2, 6, 1, 2, 2, 4};

int check(ll k)
{
    if(k == 1) return 4;
    if(k == 2) return 6;
    k-= 3;

    return arr[k % 8];
}

void solve()
{
    cin >> X >> Y >> Z >> W;
    cout << check(X);
    cout << check(Y);
    cout << check(Z);
    cout << check(W);
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
