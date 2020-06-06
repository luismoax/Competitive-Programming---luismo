/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Common Divisors
	Link: https://cses.fi/problemset/task/1081
	Online Judge: CSES
	Idea: Keep a frequency of all possible divisor among all numbers. The answer will be the greatest one 
    with frequency > 1
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
const int lim = 2e5 + 3;

int n, xi;

int arr[lim];

int freq[1000003];

void solve()
{
    cin >> n;
    int mx = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> xi;
        mx = max(xi, mx);
        for(int j = 1; j * j <= xi; j++)
        {
            if(xi % j == 0)
            {
                freq[j]++;
                if(j * j != xi)
                    freq[xi / j]++;
            }
        }
    }

    for(int i = mx; i > 0; i--)
    {
        if(freq[i] > 1)
        {
            cout << i;
            return;
        }
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