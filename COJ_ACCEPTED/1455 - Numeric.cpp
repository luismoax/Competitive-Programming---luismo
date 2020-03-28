/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1455 - Numeric
	Online Judge: COJ
	Idea: Number Theory + Incl/Excl.
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

ll A, B, N;

int sieve[lim];

void buildSieve()
{
    for(int i = 2; i < lim; i+= 2)
        sieve[i] = 2;

    for(ll i = 3; i < lim; i+= 2)
    {
        if(sieve[i] == 0)
        {
            sieve[i] = i;
            for(ll j = i * i; j < lim; j+= i + i)
                sieve[j] = i;
        }
    }
}


set<ll> rbTree;
vector<ll> deco;

ll bitMask(ll X)
{
    int sz = deco.size();

    ll answ = 0;

    for(int mask = 1; mask < (1<<sz); mask++)
    {
        ll prod = 1;
        int cnt = 0;
        for(int i = 0; i < sz; i++)
        {
            if((mask&(1<<i)) != 0)
            {
                prod *= deco[i];
                cnt ++;
            }
        }

        if(cnt % 2 == 0)
            answ -= X / prod;
        else answ += X / prod;
    }

    return X - answ;
}

void solve()
{
    buildSieve();

    cin >> N >> A >> B;

    // to decompose
    ll k = N;
    while(k > 1)
    {
        rbTree.insert(sieve[k]);
        k /= sieve[k];
    }

    for(set<ll>::iterator it = rbTree.begin(); it != rbTree.end(); it++)
        deco.push_back(*(it));

    ll a1 = bitMask(B);
    ll a2 = bitMask(A - 1);

    cout << a1 - a2 << endl;
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
