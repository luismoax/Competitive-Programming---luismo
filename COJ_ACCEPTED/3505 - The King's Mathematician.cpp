/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3505 - The King's Mathematician
	Online Judge: COJ
	Idea: Easy Math
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
const int lim = 1e6 + 2;

int tc;
int N, A, C;

int rem[103];

void solve()
{
    cin >> tc;
    for(int cs = 1; cs <= tc; cs++)
    {
        cin >> N >> A >> C;
        memset(rem, 0, sizeof rem);
        rem[0] = 1;
        int xi = 0;
        for(int i = 1; i < 103; i++)
        {
            int ax = (A*xi + C) % N;
            rem[ax] = 1;
            xi = ax;
        }

        int cnt = 0;
        for(int i = 0; i < N; i++)
            cnt += rem[i];
        cout << "Case #" << cs << ": " << cnt << endl;
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