/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: BORW
	Online Judge: SPOJ
	Idea: 
	// dp[k][i][j] - best solution at step k when 'i' is the greatest black and 'j' is the lowest white,
	// 'i' == 0 or 'j' = 0 means the no value have been painted with that color
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
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
const ll inf = 1e5 + 3;
const int mod = 1e9 + 7;
const int lim = 2e2 + 2;

int N;
int seq[lim];
set<int> rbTree;
map<int, int> forComp;
int arr[lim];

// dp[k][i][j] - best solution at step k when 'i' is the greatest black and 'j' is the lowest white,
// 'i' == 0 or 'j' = 0 means the no value have been painted with that color
int dp[lim][lim][lim];
bool mark[lim][lim][lim];

int DynamicProgramming(int idx, int black, int white)
{
	// if run out of numbers
	if(idx == -1)
	{
		return 0;
	}
	// if the current state was calculated
	if(mark[idx][black][white])
		return dp[idx][black][white];
	
	int k0 = DynamicProgramming(idx - 1, black, white) + 1;
	int k1 = inf;
	int k2 = inf;
	// if there is no element painted in black or the current one is greater
	// than the last black
	if(black == 0 || arr[idx] > black)
	{
		k1 = DynamicProgramming(idx - 1, arr[idx], white);
	}
	// if there is no element painted in white or the current one is lower
	// than the last white
	if(white == 0 || arr[idx] < white)
	{
		k2 = DynamicProgramming(idx - 1, black, arr[idx]);
	}
	// update current state
	dp[idx][black][white] = min(k0, min(k1, k2));
	// mark the state as visited
	mark[idx][black][white] = true;
	return dp[idx][black][white];
}


void solve()
{
	while(cin >> N)
	{
		if(N == -1)
			return;
		
		rbTree.clear();
		forComp.clear();
		for(int i = 0; i < N; i++)
			arr[i] = seq[i] = 0;
		memset(dp, 0, sizeof dp);
		memset(mark, 0, sizeof mark);

		for(int i = 0; i < N; i++)
		{
			cin >> seq[i];
			rbTree.insert(seq[i]);
		}

		set<int>::iterator it;
		int cnt = 1;
		for(it = rbTree.begin(); it != rbTree.end(); it++, cnt++)
		{
			forComp[*it] = cnt;
		}

		for(int i = 0; i < N; i++)
		{
			arr[i] = forComp[seq[i]];
		}


		int answ = DynamicProgramming(N - 1, 0, 0);
		// print the answer
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
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
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
