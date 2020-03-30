/*
    Author: Luis Manuel D�az Bar�n (LUISMO)
    Problem: Left Rotation
    Online Judge: hackerrank.com
    Idea: Use of modulus in order to perform the rotation
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
const int lim = 2e5 + 7;

int n, d;
int arr[lim];
int answ[lim];
void solve()
{
    cin >> n >> d;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++)
    {
        int idx = (i - d + n) % n;
        answ[idx] = arr[i];
    }
    for(int i = 0; i < n; i++)
        cout << answ[i] << " ";
}

void fastIO()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
}

void IO()
{
    if(fopen("c:\\USERS\\LUISMO\\lmo.in","r") != NULL)
    {
        freopen("c:\\USERS\\LUISMO\\lmo.in","r",stdin);
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
