/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3375 - Naebbirac Phrases
    Online Judge: COJ
    Idea: Strings, easy
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

string a, b;
int tc;

void solve()
{
	cin >> tc;

	while(tc-->0)
	{
		cin >> a >> b;

		int cnt = 0;
		for(int i = 0; i < a.length(); i++)
		{
			if(a[i] == b[i])
				cnt++;
		}
		cout << a.length() - cnt << "\n";
	}
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("d:\\lmo.in","r",stdin);
	// freopen("d:\\lmo.out","w",stdout);
}

int main()
{
    open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
