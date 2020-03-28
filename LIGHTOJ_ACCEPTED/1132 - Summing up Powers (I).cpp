/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1132 - Summing up Powers
	Online Judge: http://lightoj.com/volume_showproblem.php?problem=1132
	Idea: Matrix Exponentiation. Create a base matrix with the coeficients
	of the Newton Binomial of order K. Keep track of the summatory
	Watch what happens when N^K and (N+1)^K
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
const ll mod = (1ll<<32);
const int lim = 53 + 2;

int tc;
ll N, K;

// >> pascal
ull pascal[53][53];
void buildPascal()
{
    for(int i = 0; i < 53; i++)
    {
        pascal[i][0] = pascal[i][i] = 1;
        for(int j = 1; j < i; j++)
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
    }
}
// << pascal


// >> MATRIX EXPNENTIATION - Fixed Memory
ull base[lim][lim];
ull elev[lim][lim];
ull auxMt[lim][lim];

// multiply by another square matrix of the same dimension
// using auxMt as an auxiliar Matrix
void multiply(ull mt[lim][lim], int d)
{
    //
    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
        {
            for(int k = 0; k < d; k++)
            {
                auxMt[i][j] = ((elev[i][k] * mt[k][j]) % mod
                            + auxMt[i][j]) % mod;
            }
        }
    }
    for(int i = 0; i < d; i++)
        for(int j = 0; j < d; j++)
        {
            elev[i][j] = auxMt[i][j];
            auxMt[i][j] = 0;
        }
}

void printMatrix(ull mt[lim][lim] ,int d)
{
    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
            cout << mt[i][j] << " ";
        cout << endl;
    }
}

// Binary Exponentiation of the Static Matrix B
void binPow(ull b[lim][lim], ll ex, int d)
{
    if(ex == 0 || ex == 1)
        return;
    
    binPow(b, ex / 2, d);

    multiply(b, d);

    if(ex % 2 == 1)
        multiply(base, d);
}

// >> MATRIX EXPNENTIATION - Fixed Memory

void solve()
{
    buildPascal();
    sf("%d", &tc);
    int cs = 1;

    while(tc-- > 0)
    {
        sf("%lld%lld", &N, &K);

        // reseting elev
        for(int i = 0; i < K + 2; i++)
            for(int j = 0; j < K + 2; j++)
                base[i][j] = elev[i][j] = 0;
        // set the Pascal Triangle in the elevation matrix and in the base
        for(int i = K; i >= 0; i--)
        {
            for(int j = 0; j <= K; j++)
                base[K - i][K - j] = elev[K - i][K - j] = pascal[i][j];
        }
        for(int i = 0; i <= K; i++)
            base[K + 1][i] = elev[K + 1][i] = pascal[K][i];
        base[K + 1][K + 1]=elev[K + 1][K + 1] = 1;

        binPow(elev, N - 1, K + 2);

        ll answ = 0;
        for(int i = 0; i < K + 2; i++)
            answ += elev[K + 1][i];

        pf("Case %d: ", cs++);

        pf("%lld\n", answ % mod);
    }
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
	}
}

int main()
{
    IO();

	solve();
}
