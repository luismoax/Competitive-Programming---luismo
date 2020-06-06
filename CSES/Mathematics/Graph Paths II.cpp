/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Graph Paths II
	Link: https://cses.fi/problemset/task/1724
	Online Judge: CSES
	Idea: Nice use of Matrix Exponentiation. The key idea is to mantain at [i][j] the minimum distance from i -> j
    after multipliying the matrix a number of times
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
const ll inf = 1000000000000000005;
const int mod = 1e9 + 7;
const int lim = 1e6 + 3;

int N, M, K, A, B, C;


struct matrix
{
    int row, col;
    ll ** mt;
    ll defValue = 0;

    matrix(int r, int c)
    {
        row = r;
        col = c;
        mt = new ll * [r];
        for(int i = 0; i < row; i++)
        {
            mt[i] = new ll[col];
            for(int j = 0; j < col; j++)
                mt[i][j] = defValue;
        }
    }
    // Create a Matrix with a default value
    matrix(int r, int c, ll dv)
    {
        this->defValue = dv;
        row = r;
        col = c;
        mt = new ll * [r];
        for(int i = 0; i < row; i++)
        {
            mt[i] = new ll[col];
            for(int j = 0; j < col; j++)
                mt[i][j] = defValue;
        }
    }

    matrix(){}

    matrix operator * (matrix other)
    {
        matrix ret = matrix(row, other.col, this->defValue);
        for(int i = 0; i < ret.row; i++)
        {
            for(int j = 0; j < ret.col; j++)
            {
                for(int k = 0; k < other.row; k++)
                {
                    // instead of multiplying sum:
                    // the min distance in a path from i->k plus the min distance in a path from k->j
                    ret.mt[i][j]  = min(ret.mt[i][j], this->mt[i][k] + other.mt[k][j]);
                }     
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
    cin >> N >> M >> K;

    matrix adj = matrix(N, N, inf);
    for(int i = 0; i < M; i++)
    {
        cin >> A >> B >> C;
        A--; B--;
        adj.mt[A][B] = min(adj.mt[A][B], (ll)C);
    }

    // Exponentiate the matrix (instead of multiplying, keep the best sum)
    adj = binPow(adj, K);

    ll answ = adj.mt[0][N-1];
    
    // if the answer could not be found (there is no path of such length)
    if(answ == inf)
        answ = -1;
    // print answer
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