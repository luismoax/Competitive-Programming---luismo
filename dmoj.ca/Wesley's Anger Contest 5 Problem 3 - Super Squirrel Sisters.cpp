/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Wesley's Anger Contest 5 Problem 3 - Super Squirrel Sisters
	Link: https://dmoj.ca/problem/wac5p3
	Online Judge: dmoj.ca
	Idea: Sliding Window. Windows' sizes should be of square length, otherwise solution can't be found.
    For each possible window, linear scan keeping the number of numbers that have value sqrt(len(window))
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

int N;
int bi[lim];
int freq[lim];

void solve()
{
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> bi[i];

	ll answ = N;

	for(int j = 2; j * j <= N; j++)
	{		
		int windLen = j * j;
		
		fill(freq, freq + lim, 0);

		int goal = j;
		int cntGoal = 0;
		// fill first window
		for(int i = 0; i < windLen; i++)
		{
			int x = bi[i];

			if(freq[x] == goal)
				cntGoal--;
			
			if(freq[x] == goal - 1)
				cntGoal++;

			freq[x]++;
		}

		if(cntGoal == goal)
			answ++;

		for(int i = 1; i + windLen - 1 < N; i++)
		{
			if(freq[bi[i-1]] == goal)
				cntGoal--;
			else if(freq[bi[i-1]] == goal + 1)
				cntGoal++;
			freq[bi[i-1]]--;

			if(freq[bi[i + windLen - 1]] == goal - 1)
				cntGoal++;
			else if(freq[bi[i + windLen - 1]] == goal)
				cntGoal--;
			freq[bi[i + windLen - 1]]++;
			
			if(cntGoal == goal)
				answ++;			
		}
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