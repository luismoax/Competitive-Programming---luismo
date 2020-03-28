/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem:
	Online Judge: COJ
	Idea:
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e5 + 3;
const int mod = 1e9 + 7;

int tc;
int aa, bb, cc;
double a, b, c;

void solve()
{
    cin >> tc;
    while(tc--)
    {
        cin >> a >> b >> c;
        double tq = ((b + c - a) * (a + b - c) * (c + a - b)) / (a * b * c);

        if(tq == 1)
            cout << "equilateral\n";
        else if(tq > 0.5)
            cout << "good\n";
        else cout << "bad\n";
    }
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
		//freopen("d:\\lmo.out","w",stdout);
	}
	else if(fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
	}

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
