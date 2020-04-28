/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Wesley's Anger Contest 4 Problem 1
	Link: https://dmoj.ca/problem/wac4p1
	Online Judge: dmoj.ca
	Idea: Ad-Hoc. Brute Force
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
const ll mod = 1e9 + 7;
const int lim = 2e5 + 3;

int N, Q, le, ri, type;

bool cmp(ll a, ll b)
{
	return a > b;
}

void solve()
{	
	cin >> N >> Q;
	vector<ll> v(N);
	for(int i = 0; i < N; i++)
		cin >> v[i];

	while(Q-- > 0)
	{
		cin >> type >> le >> ri;
		le--; ri --;
		
		if(type == 1)
		{
			for(int i = le; i <= ri; i++)
				for(int j = i + 1; j <= ri; j++)
					if(v[i] > v[j])
					{
						ll x = v[i];
						v[i] = v[j];
						v[j] = x;
					}
		}
		else
		{
			for(int i = le; i <= ri; i++)
				for(int j = i + 1; j <= ri; j++)
					if(v[i] < v[j])
					{
						ll x = v[i];
						v[i] = v[j];
						v[j] = x;
					}
		}
	}
	cout << v[0];
	for(int i = 1; i < N; i++)
		cout << " " << v[i];
	cout << endl;
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