/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3151 - Peculiar Primes
	Online Judge: COJ
	Idea: Recursion + Number Theory. Try to build numbers using the power of the primes involved, and check
	whether the number is in the interval [X, Y]
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e5 + 7;

ll N, X, Y;
ll primes[10];

vector<ll> answ;

void rec(int idx, ll prod)
{
    // base
    if(idx == N)
    {
        if(prod != 1 && prod >= X && prod <= Y)
            answ.push_back(prod);
        return;
    }
    // call it with prime at power equal zero;
    rec(idx + 1, prod);

    // for each power greater than zero of the current prime
    // try to multiply it to prod, and recursive call.
    ll pw = primes[idx];
    ll aux = pw * prod;
    while(aux <= Y)
    {
        rec(idx + 1, aux);
        pw*= primes[idx];
        aux = prod * pw;
    }
}

void solve()
{
    while(cin >> N)
    {
        if(N == 0) return;
        answ.clear();
        for(int i = 0; i < N; i++)
            cin >> primes[i];
        cin >> X >> Y;

        if(X == 1)
            answ.push_back(1);

        // recursive method
        rec(0, 1);

        // sort the values of the answer
        sort(answ.begin(), answ.end());

        // print the answer
        if(answ.size() == 0)
            cout << "none";
        for(int i = 0; i < answ.size(); i++)
            if(i == 0)
                cout << answ[i];
            else cout << ","<< answ[i];
        cout << "\n";
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
