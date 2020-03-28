/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 1290 - Bytelandian Gold Coins
    Online Judge: COJ
    Idea: DP + TopDown. Beauty. Used a Map to store previously calculated values.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e5 + 3;

map<int, ll> m;
int n;

ll rec(int x)
{
    if(m.find(x) != m.end())
        return m[x];

    if(x == 0 || x == 1)
        return x;

    ll s1 = rec(x / 2);
    ll s2 = rec(x / 3);
    ll s3 = rec(x / 4);

    ll sol = max(s1+s2+s3, (ll)x);
    m[x] = sol;
    return sol;
}

void solve()
{
    for(int t = 0; t < 10; t++)
    {
        cin >> n;

        ll answ = rec(n);

        cout << answ << "\n";
    }
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

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
