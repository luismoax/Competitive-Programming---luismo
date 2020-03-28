/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1142 - Summing up Powers (II)
	Online Judge: LightOJ
	Idea: Matriz Exponentiation of a Matrix of Matrices
	Exponentiate this matrix	
		|A 0|
		|A 1|
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
const int mod = 10;
const int lim = 61;


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


int tc, n, k;

void solve()
{
    sf("%d", &tc);
    int cs = 1;
    while(tc-- > 0)
    {
        sf("%d%d", &n, &k);

        for(int i = 0; i < lim; i++)
            for(int j = 0; j < lim; j++)
                elev[i][j] = base[i][j] = 0;

        // reading matrix
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                sf("%d", &base[i][j]);
                elev[i][j] = elev[i+n][j] = base[i+n][j] = base[i][j];
            }
        }
        // identity
        for(int i = 0; i < n; i++)
            base[i+n][i+n] = elev[i+n][i+n] = 1;

        binPow(elev, k, 2*n);

        pf("Case %d:\n", cs++);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                pf("%d", elev[i+n][j]);
            pf("\n");
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
	// IO();

	//fastIO();

	solve();
}
