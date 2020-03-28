/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1871 - Balls Colors
	Online Judge: COJ
	Idea: Beautiful Problem. Iterate the whole array and at every step calculate the number of red balls to the right plus the number of green balls to the left. Take the best at the end.
	Meaining that at that point every ball to the left will be painted Red and very ball to the 
	right will be painted Green.
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

int tc;
string str;

int arr[100];

void solve()
{
    cin >> tc;
    while(tc-->0)
    {
        for(int i = 0; i < 100; i++) arr[i] = 0;
        cin >> str;
        //
        int len = str.length();
        for(int i = len - 1; i >= 0; i--)
        {
            arr[i] = arr[i + 1];
            if(str[i] == 'R')
                arr[i]++;
        }

        int best = arr[0];
        int cnt = 0;

        for(int i = 0; i <= len; i++)
        {
            if(str[i] == 'G')
            {
                cnt++;
            }
            best = min(best, cnt + arr[i + 1]);
        }
        cout << best << "\n";
    }
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
		freopen("d:\\lmo.out","w",stdout);
	}
	else if(fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
	}

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
