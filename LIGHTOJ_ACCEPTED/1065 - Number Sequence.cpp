/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem:
	Online Judge:
	Idea:
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

int mod = 1e9 + 7;

struct matrix
{
    ll mt[2][2];
    int row, col;
    matrix(){}
    matrix(int r, int c)
    {
        row = r;
        col = c;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
                mt[i][j] = 0;
        }
    }


    void printMatrix()
    {
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
                cout << mt[i][j] << " ";
            cout << endl;
        }
    }

    matrix operator * (matrix & other)
    {
        // matrix to return
        matrix ret = matrix(row, other.col);

        // for each row of the current matrix
        for(int i = 0; i < row; i++)
        {
            // for each column of the other matrix
            for(int j = 0; j < other.col; j++)
            {

                for(int k = 0; k < other.row; k++)
                {
                    ll aux = (mt[i][k] * other.mt[k][j]) % mod;
                    ret.mt[i][j]  = (ret.mt[i][j] + aux) % mod;
                }
            }
        }
        return ret;
    }
};

matrix identity(int d)
{
    matrix ret = matrix(d, d);
    for(int i = 0; i < d; i++)
        ret.mt[i][i] = 1;
    return ret;
}

matrix binPow(matrix a, ll e)
{
    if(e == 0)
        return identity(a.col);
    if(e == 1)
        return a;
    matrix aux = binPow(a, e / 2);
    aux = aux * aux;
    if(e&1)
        aux = aux * a;
    return aux;
}

ll tc, a, b, n, m;

void solve()
{
    matrix fibb = matrix(2, 2);
    fibb.mt[0][0] = 1;
    fibb.mt[0][1] = 1;
    fibb.mt[1][0] = 1;

    int cs = 1;

    sf("%lld", &tc);

    while(tc-- > 0)
    {
        sf("%lld%lld%lld%lld", &a, &b, &n, &m);

        // setting the mod
        mod = 1;
        for(int i = 1; i <= m; i++)
            mod *= 10;

        // exponentiate the matrix
        matrix ex = binPow(fibb, n);

        ll answ = (ex.mt[1][0] * b + ex.mt[1][1] * a) % mod;

        if(n == 0)
            answ = a;
        if(n == 1)
            answ = b;

        pf("Case %d: ", cs++);
        pf("%lld\n", answ);
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

	// fastIO();

	solve();
}
