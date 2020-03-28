/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3455 - CAT II
	Online Judge: COJ
	Idea: DP. Easy
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
const int lim = 2e5 + 2;

int C, A, T, tc;
string str;

void solve()
{
    cin >> tc;
    while(tc-->0)
    {
        C = A = T =0;
        cin >> str;
        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] == 'C')
                C++;
            else if(str[i] == 'A')
                A+= C;
            else if(str[i] == 'T')
                T+= A;
        }
        cout << T << endl;
    }
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
