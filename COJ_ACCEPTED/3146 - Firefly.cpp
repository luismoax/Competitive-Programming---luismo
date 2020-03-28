/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3146 - Firefly
    Online Judge: COJ
    Idea: Same idea of the overlapping intervals problem. Take the height as an array and treat
	each stalagmite of length L as an interval from H - L + 1 to H, and each stalactites of lenght
	L as an interval from 1 to L.
	Similar to ~ Another Range Tree Problem
	
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

const int lim = 1e5 * 5 + 5;

int open[lim];
int close[lim];

int N, H, x;

void solve()
{
    cin >> N >> H;

    // reading obstacles sizes
    for(int i = 1; i <= N; i++)
    {
        cin >> x;
        if(i % 2 == 0)
        {
            open[H - x + 1]++;
            close[H]++;
        }
        else
        {
            open[1]++;
            close[x]++;
        }
    }

    // linear scan
    int cnt = 0;
    int levels = 0;
    int mn = -1;
    for(int i = 1; i <= H; i++)
    {
        cnt+= open[i];

        if(mn == -1)
        {
            mn = cnt;
            levels = 1;
        }
        else if(cnt < mn)
        {
           mn = cnt;
           levels = 1;
        }
        else if(cnt == mn)
           levels++;

        cnt -= close[i];
    }

    cout << mn << " " << levels;
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("i:\\Z-SHIT\\UNISS\\Juegos de Datos x IDs\\3146\\001.in","r",stdin);
	// freopen("d:\\tt.out","w",stdout);
}

int main()
{
   // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
