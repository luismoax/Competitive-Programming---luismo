/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem:
	Online Judge: COJ
	Idea: Solution = C(N + 1, M)*N!*M! + C(N + 1, M - 1)*N!*(M-1)!*2
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e3 + 7;
const int mod = 1000000007;

int N, M;

ll fact[lim];
ll pascal[lim][lim];

void buildPascal()
{
    fact[0] = 1;
    pascal[0][0] = 1;
    for(int i = 1; i < lim; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
        pascal[i][0] = pascal[i][i] = 1;
        for(int j = 1; j < i; j++)
        {
            pascal[i][j] = (pascal[i - 1][j] + pascal[i - 1][j - 1]) % mod;
        }
    }
/*
    for(int i = 1; i < 10; i++)
    {

        for(int j = 0; j <= i; j++)
        {
            cout << pascal[i][j] << " ";
        }
        cout << endl;
    }
*/
}


void solve()
{
    buildPascal();

    cin >> N >> M;

    ll answ = pascal[N + 1][M];
    answ = (answ * fact[N]) % mod;
    answ = (answ * fact[M]) % mod;

    M--;
    ll secAnsw = pascal[N + 1][M];
    secAnsw = (secAnsw * fact[N]) % mod;
    secAnsw = (secAnsw * fact[M]) % mod;
    secAnsw = (secAnsw * 2) % mod;

    // print answer
    cout << (answ + secAnsw) % mod;
}

int main()
{
	if(fopen("e:\\lmo.in","r") != NULL)
	{
		freopen("e:\\lmo.in","r",stdin);
	}
	else if(fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
	}

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
