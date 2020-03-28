/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Tiles
	Online Judge: Light OJ
	Idea: Matrix Exponentiation.
	| 1 1 2 2 |     |Fn-1  |   |Fn  |
	| 1 0 0 0 |  X  |Fn-2  | = |Fn-1|
	| 0 1 0 0 |     |Fn-3  |   |Fn-2|
	| 0 0 1 1 |     |G(n-1)|   |G(n)|

	G(n) is the sum of all values of the function until Fn-4

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
const int mod = 10007;
const int lim = 1000000;

struct matrix
{
    int row, col;
    // ll ** mt;
    ll mt[4][4];
    matrix(int r, int c)
    {
        row = 4;
        col = 4;
        // mt = new ll * [r];
        for(int i = 0; i < row; i++)
        {
            // mt[i] = new ll[col];
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
        cout << "----------------" << endl;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
                cout << mt[i][j] << " ";
            cout << endl;
        }
        cout << "----------------" << endl;
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

int tc;
ll N;


void solve()
{
    sf("%d", &tc);
	// matrix to exponentiate
    matrix elev = matrix(4, 4);
    elev.mt[0][0] = 1;
    elev.mt[0][1] = 1;
    elev.mt[1][0] = 1;
    elev.mt[2][1] = 1;
    elev.mt[3][2] = 1;
    elev.mt[3][3] = 1;
    elev.mt[0][2] = 2;
    elev.mt[0][3] = 2;
	// solution generator
    matrix vm = matrix(4, 4);
    vm.mt[0][0] = 5;
    vm.mt[1][0] = 2;
    vm.mt[2][0] = 1;
    vm.mt[3][0] = 1;

    int cs = 1;
    while(tc-- >0)
    {
        sf("%lld", &N);

        pf("Case %d: ", cs++);

        if(N == 1)
            pf("1\n");
        else if(N == 2)
            pf("2\n");
        else if(N == 3)
            pf("5\n");
        else
        {
			// exponentiate the matrix
            matrix k = binPow(elev, N - 3);
			// find the solution
            matrix sol = k * vm;
			// print solution
            pf("%lld\n", sol.mt[0][0]);
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
