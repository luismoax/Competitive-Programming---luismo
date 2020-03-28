/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1596 - Fibonacci Numbers
	Online Judge: COJ
	Idea: Matrix Exponentiation basic application
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
const int mod = 1e9;
const int lim = 1e6 + 2;


int tc;
ll x;

struct matrix
{
    int row, col;
    ll ** mt;
    matrix(int r, int c)
    {
        row = r;
        col = c;
        mt = new ll * [r];
        for(int i = 0; i < row; i++)
        {
            mt[i] = new ll[col];
            for(int j = 0; j < col; j++)
                mt[i][j] = 0;
        }
    }
    matrix(){}

    matrix operator * (matrix other)
    {
        matrix ret = matrix(row, other.col);
        for(int i = 0; i < ret.row; i++)
        {
            for(int j = 0; j < ret.col; j++)
            {
                for(int k = 0; k < other.row; k++)
                    ret.mt[i][j] = (ret.mt[i][j] +
                                    (this->mt[i][k] * other.mt[k][j]) % mod
                                     ) % mod;
            }
        }
        return ret;
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
};

matrix identity(int d)
{
    matrix ret = matrix(d, d);
    for(int i = 0; i < d; i++)
        ret.mt[i][i] = 1;
    return ret;
}
// identity matrix (needs to be instanciated)
matrix iden;

matrix binPow(matrix b, ll ex)
{
    if(ex == 0)
        return iden;
    if(ex == 1)
        return b;
    matrix aux = binPow(b, ex / 2);
    aux = aux * aux;
    if(ex % 2 == 1)
        aux = aux * b;
    return aux;
}


void solve()
{
	cin >> tc;
	matrix fibb = matrix(2, 2);
	fibb.mt[0][0] = fibb.mt[0][1] = fibb.mt[1][0] = 1;
	
	while(tc--)
	{
		cin >> x;
		
		matrix res = binPow(fibb, x - 1);

		int dg = log10(res.mt[0][0]) + 1;
		for(int i = 0; i < 9 - dg; i++)
			cout << 0;

		cout << res.mt[0][0] << endl;	
				
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
	else if(fopen("/media/Beijing/lmo.in","r") != NULL)
	{
		freopen("/media/Beijing/lmo.in", "r", stdin);
	}
}

int main()
{
	IO();

	fastIO();

	solve();
}