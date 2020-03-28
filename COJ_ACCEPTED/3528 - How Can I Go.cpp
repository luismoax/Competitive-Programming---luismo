/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3528 - How can I go?
	Online Judge: COJ
	Idea: Matrix Exponentiation
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int mod = 1e9 + 7;


int N, M, Q;

struct matrix
{
	ll mt[51][51];
	matrix(){}
};

void printMt(matrix & a, int dim)
{
	for(int i = 0; i < dim; i++)
	{
		for(int j = 0; j < dim; j++)
			cout << a.mt[i][j] << " ";
		cout << "\n";
	}
}

matrix mult(matrix & a, matrix & b, int dim)
{
	matrix c;
	for(int i = 0; i < dim; i++)
		for(int j = 0; j < dim; j++)
			for(int k = 0; k < dim; k++)
			{
				c.mt[i][j] += (a.mt[i][k] * b.mt[k][j]) % mod;
				c.mt[i][j] %= mod;
			}
	return c;
}

matrix mpow(matrix & a, int pw, int dim)
{
	if(pw == 1)
		return a;

	matrix k = mpow(a, pw / 2, dim);

	matrix ret = mult(k, k, dim);

	if(pw % 2 == 0)	
		return ret;
	else return mult(ret, a, dim);
}

matrix adj; // adjacency

void solve()
{
	cin >> N >> M;

	// reading edges
	for(int i = 0; i < M; i++)
	{
		int xx, yy;
		cin >> xx >> yy;
		xx--; yy--;
		adj.mt[xx][yy]++;
	}

	cin >> Q;
	
	adj = mpow(adj, Q, N);
	
	cout << adj.mt[0][N - 1];
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
		freopen("d:\\lmo.in","r",stdin);

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
