/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Jarin Loves New Task
	Link: https://www.spoj.com/problems/JLNT/
	Online Judge: SPOJ
	Idea: DP. Easy
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
#define M_PI 2.0 * acos(0)
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 3;
const int lim = 1e3 + 3;

int N, L, tc;
int arr[lim];
int dp[1003][5003];
bool mark[1003][5003];

int DynamicProgramming(int idx, int len)
{
	if(idx <= 0 || len == 0)
		return 0;

	if(mark[idx][len])
		return dp[idx][len];

	mark[idx][len] = 1;

    // when the link between the current and the predecesor is NOT TAKEN
	int s1 = DynamicProgramming(idx - 1, len); 
    // when the link between the current and the predecesor is TAKEN
	int s2 = 0;
	if(len >= (arr[idx] - arr[idx - 1]))
		s2 = DynamicProgramming(idx - 2, len - (arr[idx] - arr[idx - 1])) + 2; 
	
	dp[idx][len] = max(s1, s2);
	return dp[idx][len];
}

void solve()
{
	cin >> tc;
	for(int cs = 1; cs <= tc; cs++)
	{
		cin >> N >> L;
		
		memset(dp, 0, sizeof dp);
		memset(mark, 0, sizeof mark);

		for(int i = 0; i < N; i++)
			cin >> arr[i];
		cout << "Case " << cs << ": ";
		int answ = DynamicProgramming(N - 1, L);		
		cout << answ << endl;
	}
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