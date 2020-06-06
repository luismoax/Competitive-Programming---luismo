/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Throwing Dice
	Link: https://cses.fi/problemset/task/1096
	Online Judge: CSES
	Idea: Basic use of Matrix Exponentiation to solve the following recurrence: Fn = Fn-1 + Fn-2 +...+ Fn-6 
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


ll dice(int n)
{
    if(n < 0)
        return 0;
    if(n == 0)
        return 1;
    ll ret = 0;
    for(int i = 1; i <= 6; i++)
        ret += dice(n - i);
    return ret;
}

ll n;

/*
    // Base cases
    1 -     1
    2 -     2
    3 -     4
    4 -     8
    5 -     16
    6 -     32
*/

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
    cin >> n;
    
    matrix bas = matrix(6, 6);
    for(int i = 0; i < 6; i++)
        bas.mt[0][i] = 1;
    for(int i = 1; i < 6; i++)
        bas.mt[i][i-1] = 1;
    
    // vector 
    matrix col = matrix(6 , 1);    
    col.mt[0][0] = 32;
    col.mt[1][0] = 16;
    col.mt[2][0] = 8;
    col.mt[3][0] = 4;
    col.mt[4][0] = 2;
    col.mt[5][0] = 1;
    
    ll answ = 0;

    if(n <= 6)
        answ = col.mt[6 - n][0];
    else
    {
        matrix sol = binPow(bas, n - 6);
        // multiplied exponentied matrix by vector
        sol = sol * col;
        //
        answ = sol.mt[0][0];
    }
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