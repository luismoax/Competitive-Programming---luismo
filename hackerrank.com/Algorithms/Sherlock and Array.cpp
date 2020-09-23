/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Sherlock and Array
	Link: https://www.hackerrank.com/challenges/sherlock-and-array/problem
	Online Judge: hackerrank.com
	Idea: Basic use of a Cumulative Table
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
#define x first
#define y second
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;

int tc, n;

void solve()
{
	cin >> tc;
	while(tc-- > 0)
	{
		cin >> n;
        // to store numbers
		vector<ll> vect(n + 2);
        // to store cumulative sums
		vector<ll> sums(n + 2);
        // I added two more positions to cumulative sums for confort        
		vect[0] = sums[0] = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> vect[i];
			sums[i] = sums[i-1] + vect[i];
		}
		sums[n+1] = sums[n];

		bool ok  = false;

		for(int i = 1; !ok && i <= n; i++)
		{
			int qLeft = sums[i - 1];
			int qRight = sums[n + 1] - sums[i];

			if(qLeft == qRight)
				ok = true;
		}

		if(ok)
			cout << "YES";
		else cout << "NO";
		cout << endl;
	}
	
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