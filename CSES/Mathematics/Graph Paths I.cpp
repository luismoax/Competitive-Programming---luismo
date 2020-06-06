/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Graph Paths I
	Link: https://cses.fi/problemset/task/1723
	Online Judge: CSES
	Idea: Classic Matrix Exponentiation
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
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
const ll inf = 1e7 + 3;
const int mod = 1e9 + 7;
const int lim = 1e6 + 3;

int n, m, k, a, b;


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

matrix binPow(matrix b, ll ex)
{
    if(ex == 0)
        return identity(b.col);
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
    cin >> n >> m >> k;

    matrix adj = matrix(n, n);
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--; b--;
        adj.mt[a][b]++;    
    }

    adj = binPow(adj, k);
    
    ll answ = adj.mt[0][n-1];

    cout << answ;
}
 
void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}
 
void IO()
{
	if(fopen("c:\\Users\\LUISMO\\lmo.in","r") != NULL)
	{
		freopen("c:\\Users\\LUISMO\\lmo.in","r",stdin);
	}
	else if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("media/Beijing/lmo.in","r") != NULL)
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