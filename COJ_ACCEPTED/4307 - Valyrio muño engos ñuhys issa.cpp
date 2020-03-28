/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: 4307 - Valyrio muño engos ñuhys issa
	Online Judge: COJ
	Idea: DP.
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
const int lim = 500 + 2;

int tc;
int N;
int c, v, l, k;

ll dp[503][2];
int mark[503][2];
bool flag;

ll DynamicProgramming(int len, int tail, int tm)
{
    ll coef = (tail) ? c : v;
    if(len < 0)
        return 0;

    if(len == 1)
        return coef;

    if(mark[len][tail] == tm)
        return dp[len][tail];



    ll a1 = DynamicProgramming(len - 1, 0, tm) * coef;

    ll a2 = 0;
    if(tail == 0)
        a2 = DynamicProgramming(len - 1, 1, tm) * coef;

    if(a1 + a2 > k)
        flag = true;

    mark[len][tail] = tm;
    dp[len][tail] = (a1 + a2) % mod;
    return dp[len][tail];
}

void solve()
{
    cin >> tc;
    int time = 1;
    while(tc--)
    {
        cin >> c >> v >> l >> k;

        flag = false;
        ll answ = 0;

        answ = DynamicProgramming(l, 0, time++);

        cout << answ << " ";
        if(flag || answ >= k)
            cout << "Accepted" << endl;
        else cout << "Rejected" << endl;
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
