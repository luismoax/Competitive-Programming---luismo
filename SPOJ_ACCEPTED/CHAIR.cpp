/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Chairs
	Link: https://www.spoj.com/problems/CHAIR/
	Online Judge: SPOJ
	Idea: DP.
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

int N, K;

ll dp[lim][lim];
bool mark[lim][lim];

ll DynamicProgramming(int chairs, int persons)
{
	if(persons == 0)
		return 1;

	if(chairs == 1 && persons <= 1)	
		return 1;
	
	if(persons * 2 > chairs)
		return 0;

	if(mark[chairs][persons])
		return dp[chairs][persons];
	mark[chairs][persons] = 1;

	ll s1 = DynamicProgramming(chairs - 1, persons); // when the last chair is unused
	ll s2 = DynamicProgramming(chairs - 2, persons - 1); // when the last chair is used

	dp[chairs][persons] = (s1 + s2) % mod;
	return dp[chairs][persons];
}

void solve()
{
	cin >> N >> K;

	ll answ = DynamicProgramming(N, K);

	cout << answ << endl;
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