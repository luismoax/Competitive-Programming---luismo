/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1070 - Algebraic Problem
	Online Judge: LightOJ
	Idea: Matrix Exponetiation
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
const int lim = 2e5 + 2;


struct matrix
{
    ull mt[2][2];
    int row, col;
    matrix(int r, int c)
    {
        row = r;
        col = c;
        mt[0][0] = mt[0][1] = mt[1][0] = mt[1][1] = 0;
    }

    void printMatrix()
    {
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
                cerr << mt[i][j] << " ";
            cerr << endl;
        }
        cerr << endl;
    }
};

matrix identity(int d)
{
    matrix id = matrix(d, d);
    for(int i = 0; i < d; i++)
        id.mt[i][i] = 1;
    return id;
}


matrix product(matrix a, matrix b)
{
    matrix nw = matrix(a.row, b.col);

    for(int i = 0; i < a.row; i++)
    {
        for(int j = 0; j < b.col; j++)
        {
            nw.mt[i][j] = 0;
            for(int k = 0; k < a.col; k++)
            {
                ull aux = (a.mt[i][k] * b.mt[k][j]);

                nw.mt[i][j] = (nw.mt[i][j] + aux);
            }
        }
    }
    return nw;
}

matrix binPow(matrix a, ll e)
{
    if(e == 0)
        return identity(a.col);
    if(e == 1)
        return a;
    matrix aux = binPow(a, e / 2);

    aux = product(aux, aux);

    if(e % 2 == 1)
        aux = product(aux, a);
    return aux;
}

int tc;
ll p, q, n;


void solve()
{
    sf("%d", &tc);
    int cs = 1;
    while(tc --> 0)
    {
        sf("%lld%lld%lld", &p, &q, &n);
        // p = a + b
        // q = ab
        matrix mm = matrix(2, 2);
        mm.mt[0][0] = p;
        mm.mt[0][1] = -q;
        mm.mt[1][0] = 1;
        mm.mt[1][1] = 0;

        mm.printMatrix();


        matrix X = matrix(2, 2);

        X.mt[0][0] = p;
        X.mt[1][0] = 2;

        matrix sol = binPow(mm, n);

        sol = product(sol, X);

        //sol.printMatrix();

        pf("Case %d: %llu\n", cs++, sol.mt[1][0]);
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
	
	solve();
}
