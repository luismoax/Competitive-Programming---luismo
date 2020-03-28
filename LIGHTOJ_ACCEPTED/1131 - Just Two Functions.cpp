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
    ll mt[6][6];
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

int tc;
ll a1, b1, c1, a2, b2, c2;
ll f0, f1, f2, g0, g1, g2;
int q, n;

void solve()
{
    int cs = 1;
    sf("%d", &tc);
    while(tc-- > 0)
    {
        sf("%lld%lld%lld", &a1, &b1, &c1);
        sf("%lld%lld%lld", &a2, &b2, &c2);
        sf("%lld%lld%lld", &f0, &f1, &f2);
        sf("%lld%lld%lld", &g0, &g1, &g2);
        sf("%d %d", &mod, &q);

        f0%= mod; f1%= mod; f2%= mod;
        g0%= mod; g1%= mod; g2%= mod;


        matrix elev = matrix(6, 6);
        elev.mt[0][0] = a1;
        elev.mt[0][1] = b1;
        elev.mt[0][5] = c1;
        elev.mt[1][0] = 1;
        elev.mt[2][1] = 1;
        elev.mt[3][2] = c2;
        elev.mt[3][3] = a2;
        elev.mt[3][4] = b2;
        elev.mt[4][3] = 1;
        elev.mt[5][4] = 1;

        for(int i = 0; i < 6; i++)
            for(int j = 0; j < 6; j++)
                elev.mt[i][j] %= mod;

        // vector
        vector<ll> v;
        v.push_back(f2);
        v.push_back(f1);
        v.push_back(f0);
        v.push_back(g2);
        v.push_back(g1);
        v.push_back(g0);


        pf("Case %d:\n", cs++);
        while(q-- > 0)
        {
            sf("%d", &n);

            if(n == 0)
                pf("%lld %lld\n", f0, g0);
            else if(n == 1)
                pf("%lld %lld\n", f1, g1);
            else if(n == 2)
                pf("%lld %lld\n", f2, g2);
            else
            {
                matrix exp = binPow(elev, n - 2);
/*
                pf("----\n");
                exp.printMatrix();
                pf("----\n");
*/
                ll fn = 0, gn = 0;
                for(int i = 0; i < v.size(); i++)
                {
                    ll xx = (v[i] * exp.mt[0][i])%mod;
                    fn = (fn + xx) % mod;

                    xx = (v[i] * exp.mt[3][i]) % mod;
                    gn = (gn + xx) % mod;
                }

                pf("%lld %lld\n", fn % mod, gn % mod);
            }
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

	solve();
}
