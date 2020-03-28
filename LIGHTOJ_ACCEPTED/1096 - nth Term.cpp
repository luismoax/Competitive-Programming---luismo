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
    ll mt[4][4];
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
                pf("%lld ", mt[i][j]);
            pf("\n");
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

ll tc, a, b, c, n;

void solve()
{
    mod = 10007;
    int cs = 1;

    sf("%lld", &tc);

    while(tc-- > 0)
    {
        sf("%lld%lld%lld%lld", &n, &a, &b, &c);

        matrix mother = matrix(4, 4);
        mother.mt[0][0] = a;
        mother.mt[0][2] = b;
        mother.mt[0][3] = 1;
        mother.mt[1][0] = 1;
        mother.mt[2][1] = 1;
        mother.mt[3][3] = 1;

        pf("Case %d: ", cs++);
        ll answ = 0;
        if(n > 2)
        {
            matrix pwdMatrix = binPow(mother, n - 2);
            answ = (c*pwdMatrix.mt[0][3]) % mod;
        }
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
	//IO();

	//fastIO();

	solve();
}
