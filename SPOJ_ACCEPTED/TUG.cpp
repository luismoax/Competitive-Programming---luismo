/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: TUG
	Link: https://www.spoj.com/problems/TUG/
	Online Judge: SPOJ
	Idea: If there are more than 100 elements (by dirichlet principle) there should be two elements with the same value.
	In case there are no repeated elements. For each value v between 1 and sum_of_elements find the number of ways of representing v
	as the sum of some elements, if there is more than one way, then there can be picked two diferent subsets with the same sum
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
const int mod = 301907;
const int lim = 1e6 + 3;

int arr[100001];
ll dp[101][10001];
bool mark[101][10001];

ll DynamicProgramming(int idx, int sm)
{
	if(sm == 0)
		return 1;
	
	if(idx < 0 || sm < 0)
		return 0;

	if(mark[idx][sm])
		return dp[idx][sm];

	mark[idx][sm] = 1;

	ll k1 = DynamicProgramming(idx - 1, sm - arr[idx]);
	ll k2 = DynamicProgramming(idx - 1, sm);

	dp[idx][sm] = k1 + k2;	
	
	return dp[idx][sm];
}

int tc, N;

void solve()
{
    cin >> tc;
	while(tc--)
	{
		// clear DP
		memset(dp, 0, sizeof dp);
		memset(mark, 0, sizeof mark);
		
		cin >> N;
		int sum = 0;
		for(int i = 0; i < N; i++)
		{
			cin >> arr[i];
			sum += arr[i];
		}
		bool ok = false;

		if(N >= 100)
			ok = true;

		if(!ok)
		{
			for(int j = 1; !ok && j <= sum; j++)
			{
				ll k = DynamicProgramming(N - 1, j);
				ok = k > 1;
			}			
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