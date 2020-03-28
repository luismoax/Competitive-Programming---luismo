/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3794 - Counting Edges and Graphs
	Online Judge: COJ
	Idea: DP + Basic Combinatorics
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 5e3 + 3;

int T, N, K;

const int mod = 1000000007;

int pd[lim];
ll pascal[lim][lim];

int propDiv(int x)
{
    int cnt = 1;
    for(int i = 2; i * i <= x; i++)
    {
        if(x % i == 0)
        {
            cnt++;
            if(x / i != i)
                cnt++;
        }
    }
    return cnt;
}

void preProcess()
{
    pascal[0][0] = 1;
    // build Pascal
    for(int i = 1; i < lim; i++)
    {
        pascal[i][0] = pascal[i][i] = 1;
        for(int j = 1; j < i; j++)
            pascal[i][j] = (pascal[i - 1][j - 1] + pascal[i - 1][j]) % mod;

        //
        pd[i] = propDiv(i);

    }

/*
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j <= i; j++)
            cout << pascal[i][j] << " ";
        cout << endl;
    }
*/

}

void solve()
{
    cin >> T;

    // preprocess
    preProcess();


    // for each case
    while(T-->0)
    {
        cin >> N >> K;

        ll edges = 0;
        ll possible = 1;

        for(int i = 2; i <= N; i++)
        {
            edges += min(pd[i], K);
            if(pd[i] > K)
            {
                possible = (possible * pascal[pd[i]][K]) % mod;
            }
        }
        // print answer
        cout << edges << " " << possible << "\n";
    }
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

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
