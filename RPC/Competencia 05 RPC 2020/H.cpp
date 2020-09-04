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
#define pf prllf
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"
 
using namespace std;
 
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll lim = 2e5 + 3;


int n, x;

void solve()
{
	cin >> n;
	stack<int> orig;
	for(int i = 0; i < 2*n; i ++)
	{
		cin >> x;
		orig.push(x);
	}

	stack<int> aux;

	int moves = 0;

	while(orig.size() > 0 || aux.size() > 0)
	{
		// cout << orig.size() << "  " << aux.size() << endl;
		if(orig.size() == 0)
		{
			cout << "impossible" << endl;
			return;
		}
		else if(aux.size() == 0)
		{
			int k = orig.top(); orig.pop();
			aux.push(k);
		}
		else
		{
			if(orig.top() == aux.top())
			{
				orig.pop();
				aux.pop();
			}
			else
			{
				int k = orig.top(); orig.pop();
				aux.push(k);
			}			
		}
		moves++;
	}
	cout << moves << endl;
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