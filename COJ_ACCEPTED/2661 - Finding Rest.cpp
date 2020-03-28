/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 2661 - Finding Rest
    Online Judge: COJ
    Idea: Easy Number Theory. Find the Cycle which is modulo 3.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e7 + 3;

string str;

void solve()
{
    while(cin >> str)
    {
        int rm = 0;
        for(int i = 0; i < str.length(); i++)
            rm = (rm + (str[i] - '0')) % 3;

        if(rm == 0)
            cout << 1;
        else if(rm == 1)
            cout << 7;
        else cout << 4;
        cout << "\n";
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
