/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Edit Distance
	Link: https://cses.fi/problemset/task/1639
	Online Judge: CSES
	Idea: Classic DP Problem.
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
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e9 + 3;
const int mod = 1e9 + 7;
const int lim = 5e3 + 2;

string strA, strB;

int dp[lim][lim];
bool mark[lim][lim];

int DynamicProgramming(int la, int lb)
{
    // if no characters in strA add all characters in strB
	if(la == 0)
		return lb;
    // if no characters in strB delete all characters in strA
	if(lb == 0)
		return la;
    // if visited state
	if(mark[la][lb])
		return dp[la][lb];
    // mark the state as visited
	mark[la][lb] = true;
    
    // when deleting las character from strB
	int s1 = DynamicProgramming(la, lb - 1) + 1;
	// when deleting las character from strA
    int s2 = DynamicProgramming(la - 1, lb) + 1;
    // when calculating assuming both characters at the end match 
	int s3 = DynamicProgramming(la - 1, lb - 1);
    // if they are different the change operation should be applied
	if(strA[la - 1] != strB[lb - 1])
		s3++;
    // update dp
	dp[la][lb] = min(s1, min(s2, s3));
	return dp[la][lb];
}

void solve()
{
	cin >> strA >> strB;

	cout << DynamicProgramming(strA.size(), strB.size()) << endl;
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
	else if(fopen("/media/Beijing/lmo.in","r") != NULL)
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