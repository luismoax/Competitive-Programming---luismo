/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 
	Link: 
	Online Judge: 
	Idea: 
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
// IO
#define sf scanf
#define pf prllf
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"
 
using namespace std;
 
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll lim = 2e5 + 3;

int n;
string str;

int mt[30][30];

void solve()
{
	cin >> n;
    bool ok = true;
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        int b = 0;
        for(int j = 0; j < n; j++)
        {
            if(str[j] == 'B')
            {
                mt[i][j] = 1;
                b++;
            }
            if(j >= 2)
            {
                int last3 = mt[i][j] + mt[i][j-1] + mt[i][j-2];
                if(last3 == 3 || last3 == 0)
                    ok = false;
            }
        }
        if(b != n / 2)
            ok = false;
    }

    if(!ok)
    {
        cout << 0 << endl;
        return;
    }


    for(int j = 0; j < n; j++)
    {
        int b = 0;
        for(int i = 0; i < n; i++)
        {
            if(mt[i][j] == 1)
                b++;

            if(i >= 2)
            {
                int last3 = mt[i][j] + mt[i-1][j] + mt[i-2][j];
                if(last3 == 3 || last3 == 0)
                    ok = false;
            }
        }
        if(b != n / 2)
            ok = false;
    }

    if(!ok)
    {
        cout << 0 << endl;
        return;
    }

    cout << 1 << endl;    
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