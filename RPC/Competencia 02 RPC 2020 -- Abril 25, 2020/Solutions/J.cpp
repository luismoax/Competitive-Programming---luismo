/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem:
	Link:
	Online Judge:	
	Idea:
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
#define M_PI 3.14159265358979323846

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e7 + 3;
const ll mod = (1ll << 32);
const int lim = 200;

int N;
int M = 5;
int x;
ld epsilon = 1e-6;

ld distance(int a, int b)
{
	if(a > b)
		swap(a, b);
	
	ld x = b - a;
	if(M - b + a < x)
		x = M - b + a;
	// degrees
	x = x * (360.0 / M);

	ld angle = (M_PI/180.0)*x;

	ld aux = 2.0 * (1.0 - cos(angle));
	ld dist = sqrt( aux );
	return dist;
}

vector<int> ti;
vector<int> stat;

// >> DP
ld dp[lim][lim];
bool mark[lim][lim];

ld DynamicProgramming(int idx, int step)
{
	if(step == 1)	
		return 0;
	
	// if state visited
	if(mark[idx][step])
		return dp[idx][step];

	// mark the state
	mark[idx][step] = true;

	for(int i = 1; i <= M; i++)
	{
		int currStEx = stat[i];
		if(currStEx == ti[step - 1])
		{
			ld aux = DynamicProgramming(i, step - 1);
			ld dist = distance(idx, i);			
			
			if(aux + dist < dp[idx][step])
			{				
				dp[idx][step] = aux + dist;
			}
		}
	}
	return dp[idx][step];
}
// << DP

void solve()
{
	
	// cout << 
	// 1 + distance(1, 3) + distance(3, 2) + distance(2, 1)
	// 		+ distance(1, 5) + distance(5, 4)	;
	
	for(int i = 0; i < lim; i++)
	{
		for(int j = 0; j < lim; j++)
		{
			dp[i][j] = 1000000;
			mark[i][j] = false;
		}
	}

	cin >> N;
	ti.push_back(-1);
	stat.push_back(-1);
	for(int i = 0; i < N; i++)
	{
		cin >> x;
		ti.push_back(x);
	}

	cin >> M;
	for(int i = 0; i < M; i++)
	{
		cin >> x;
		stat.push_back(x);
	}

	ld answ = inf;
	for(int i = 1; i <= M; i++)
	{
		if(stat[i] == ti[N])
		{
			ld aux = DynamicProgramming(i, N);
			answ = min(answ, aux);
		}
	}
	cout.precision(9);
	cout << fixed <<  answ + 1.0 << endl;
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
