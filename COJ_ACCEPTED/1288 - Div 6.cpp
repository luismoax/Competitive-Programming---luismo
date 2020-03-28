/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 1288 - Div 6
    Online Judge: COJ
    Idea: Easy Number Theory.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 20;

int tc;
string str;

void solve()
{
    cin >> tc;
    while(tc--)
    {
        cin >> str;
        int len = str.length();
        int k = 0;
        for(int i = 0; i < len; i++)
            k+= str[i] - '0';

        if(k % 3 == 0 && (str[len - 1] - '0') % 2 == 0)
            cout << "YES\n";
        else cout << "NO\n";

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
