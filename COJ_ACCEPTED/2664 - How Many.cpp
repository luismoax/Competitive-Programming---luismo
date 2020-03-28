/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 2664 - How Many
    Online Judge: COJ
    Idea: Combinatorics
*/

#include <iostream>
#include <cstdio>
// Containers
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
// Algorithm
#include <algorithm>
#include <cstring>
#include <cmath>
// Constants
#define MAXN 1000001
#define MOD 1000000007
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define nint(i) sf("%d",&i);
#define nlong(i) sf("%lld",&i);

using namespace std;

void open_file()
{
    // freopen("//media//luismo//Trabajo//lmo.in","r",stdin);
    freopen("d:\\lmo.in","r",stdin);
}

const int mod = 1e9 + 7;

ll power(int b, int e)
{
    if(e ==0 )
        return 1;
    if(e == 1)
        return b;

    ll res = power(b, e/ 2);
    if(e % 2 == 0)
        return (res * res) % mod;

    return ( ( (res * res) % mod) * b ) %mod;
}

int N;
void solve()
{
    while(sf("%d",&N) != EOF)
    {
        ll answ = power(3, N);
        answ = answ % mod;
        pf("%lld\n", answ);
    }
}

int main()
{
    // open_file();

    solve();
}