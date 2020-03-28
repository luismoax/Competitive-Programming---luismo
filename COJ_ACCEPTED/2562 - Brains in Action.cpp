/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 2562 - Brains in Action
	Online Judge: COJ
	Idea: Factorization using Erathostenes' Sieve
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
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 1e6 + 2;


int N;

int sieve[lim];

void buildSieve()
{
    sieve[2] = 2;
    for(int i = 4; i < lim; i+= 2)
        sieve[i] = 2;

    for(int j = 3; j < lim; j+= 2)
    {
        if(sieve[j] == 0)
        {
            sieve[j] = j;
            for(int i = j + j; i < lim; i+= j)
                sieve[i] = j;
        }
    }
/*
    for(int i = 0; i < 40; i++)
    {
        cout << i << " " << sieve[i] << endl;
    }
*/
}

map<int, int> m;

void solve()
{
    buildSieve();

    while(cin >> N)
    {
        m.clear();
        int aux = N;
        while(aux > 1)
        {
            m[sieve[aux]]++;
            aux/= sieve[aux];
        }

        map<int, int>::iterator it;
        for(it = m.begin(); it != m.end(); it++)
        {
            cout << "(" << it->first << "(" << it->second << "))";
        }
        cout << endl;
    }
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
