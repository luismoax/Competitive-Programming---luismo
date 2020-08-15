/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Wesley's Anger Contest 5 Problem 1 - Matryoshka Acorns
	Link: https://dmoj.ca/problem/wac5p1
	Online Judge: dmoj.ca
	Idea: Ad-Hoc
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

int n;
int accorns[lim];
int taken[lim];

void solve()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> accorns[i];

	sort(accorns, accorns + n);

	int answ = 0;
	int cnt = 0;

	while(cnt < n)
	{
		int gr = -1;
		int lst = -1;
		for(int i = n - 1; i >= 0; i--)
		{
			if(!taken[i] && gr == -1 || accorns[i] < lst)
			{
				if(gr == -1)
				{
					gr = accorns[i];
					lst = accorns[i];					
				}
				else
				{
					lst = accorns[i];
				}
				cnt++;	
				taken[i] = 1;
			}
		}

		answ += gr;
	}
	cout << answ << endl;
}
 
void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}
 
void IO()
{

	if(fopen("c:\\Competitive Programming\\lmo.in","r") != NULL)
	{
		freopen("c:\\Competitive Programming\\lmo.in","r",stdin);
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