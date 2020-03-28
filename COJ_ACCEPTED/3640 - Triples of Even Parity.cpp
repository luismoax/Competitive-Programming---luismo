/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3640 - Triples of Even Parity
	Online Judge: COJ
	Idea: Sets + Basic Combinatorics
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

int Q, x;
char c;

set<int> forEven;
set<int> forOdd;

void solve()
{
    cin >> Q;
    // reading queries
    for(int i = 0; i < Q; i++)
    {
        cin >> c;
        if(c == 'i')
        {
            cin >> x;
            if(x % 2 == 0)
                forEven.insert(x);
            else forOdd.insert(x);
        }
        else if(c == 'r')
        {
			cin >> x;
            if(x % 2 == 0)
                forEven.erase(x);
            else forOdd.erase(x);
        }
        else
        {
            ll eSz = forEven.size();
            ll oSz = forOdd.size();
            //
            ll answ = (eSz * (eSz - 1) * (eSz - 2)) / 6;

            answ += (eSz * ( (oSz * (oSz - 1)) / 2 ));

            cout << answ << "\n";
        }
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
