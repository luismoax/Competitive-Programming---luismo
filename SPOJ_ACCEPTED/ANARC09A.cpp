/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem:
	Online Judge: https://www.spoj.com/problems/ANARC09A/
	Idea: DP
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

typedef pair<int, int> pii;
const ll inf = 1e18 + 3;
const int mod = 1e9 + 7;
const int lim = 2e3 + 2;

string str;
int cs;

void solve()
{
    cin >> str;
    int cs = 1;
    while(str[0] != '-')
    {
        int answ = 0;
        int op = 0;
        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] == '}')
            {
                if(op == 0)
                {
                    op++;
                    answ++;
                }
                else op--;
            }
            else op++;
        }

        cout << cs << ". " << answ + op / 2 << "\n";

        cin >> str;
        cs++;
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
