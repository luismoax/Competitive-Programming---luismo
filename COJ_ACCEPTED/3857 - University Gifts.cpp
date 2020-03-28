/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3857 - University Gifts
	Online Judge: COJ
	Idea: Number of derangements. deArr[i] = (i - 1)*deArr[i - 1] + (i - 1)*deArr[i - 2]
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e6 + 7;
const int mod = 1000000007;

int N, tc;

ll deArr[lim];

void preProcess()
{
    deArr[0] = deArr[1] = 0;
    deArr[2] = 1;
    deArr[3] = 2;

    for(int i = 4; i < lim; i++)
    {
        deArr[i] = ( ( (i - 1) * deArr[i - 1] % mod) +
                    ( (i - 1) * deArr[i - 2] % mod) ) % mod;
    }
}

void solve()
{
    preProcess();

    cin >> tc;
    while(tc--> 0)
    {
        cin >> N;
        cout << deArr[N] << "\n";
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
