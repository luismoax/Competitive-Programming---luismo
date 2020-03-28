/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1989 - Bale Share
	Online Judge: COJ
	Idea: DP + Bitmask. dp[i][j], keeps the best distribution when B1 = i
	and B2 = j. Keep a mask to mark the taken elements.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 2e3 + 2;

int N, arr[lim];

int sum;

int dp[lim][lim];
bool mark[lim][lim];


int DynamicProgramming(int mask, int b1, int b2)
{
	// if all elements taken (mask is full)
    if(mask == (1<<N) - 1)
        return max(max(b1, b2), sum-(b1+b2));
	// if this state was calculated before
    if(mark[b1][b2])
        return dp[b1][b2];

	// keeps the best value that can be achieved once we reach this state
	int aux; 
	// auxiliar
    int a1, a2;
	// store in aux the bale with greatest size at this state
    aux = max(sum-(b1+b2), max(b1, b2));
    for(int i = 0; i < N; i++)
    {
		// if the i-th element is not taken
        if((mask&(1<<i)) == 0)
        {
			
            a1 = DynamicProgramming(mask|(1<<i), b1 + arr[i], b2);
            a2 = DynamicProgramming(mask|(1<<i), b1, b2 + arr[i]);
			// update the value
            aux = min(aux, min(a1, a2));
        }
    }
	// mark state as calulated
    mark[b1][b2] = true;
	// update dp
    dp[b1][b2] = aux;
	// return
    return dp[b1][b2];
}


void solve()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
	// calculate
    ll answ = DynamicProgramming(0, 0, 0);
	// print answer
    cout << answ << endl;
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
	}

	fastIO();

	solve();
}
