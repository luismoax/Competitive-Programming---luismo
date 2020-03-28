/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem:  2936 - Triangles and Cuadrilats
    Online Judge: COJ
    Idea: Number of Triangles = C(N, 2) * M + C(M, 2) * M
			Number of Cuadrilats = C(N, 2) * C(M, 2)
*/
#include <iostream>
#include <cstdio>
// Containers
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
// Algorithm
#include <algorithm>
#include <cstring>
#include <cmath>
// Constants
#define MAXN 1000001
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define nint(i) sf("%d",&i);
#define nlong(i) sf("%lld",&i);

using namespace std;

// method used to read faster in C++
inline int read_int () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

const int lim  = 1e3 + 5;
const int MOD = 1e9 + 7;
// pascal triangle
int pasc[lim][lim];

// building pascal triangle
void build_pascal()
{
	for(int i = 1; i < lim; i++)
	{
		pasc[i][0] = pasc[i][i] = 1;
		for(int j = 1; j < i; j++)
		{
			pasc[i][j] = (pasc[i - 1][j - 1] + pasc[i - 1][j]) ;
		}
	}
}

int N, M;
void solve()
{
    build_pascal();
	while(sf("%d%d", &N, &M ) != EOF)
	{
		ll cn = pasc[N][2];
		ll cm = pasc[M][2];

		ll triangles = (cn * M) + (cm * N);
		ll cuadrilats = cn * cm;

		cout<<"Triangles: "<< triangles << "\n";
		cout<<"Quadrilaterals: "<< cuadrilats << "\n";
		cout<<"\n";
	}
}

void open_file()
{
    // freopen("//media//luismo//Trabajo//lmo.in","r",stdin);
	// freopen("d:\\lmo.in","r",stdin);	
}

int main()
{
    //open_file();

    solve();
}
