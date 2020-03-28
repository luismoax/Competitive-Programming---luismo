/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3251 - Cesta
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

const int lim = 1e6 + 7;

string str;
vector<int> dig;
bool flag = false;
int sum = 0;

void solve()
{
    cin >> str;

    for(int i = 0; i < str.length(); i++)
    {
        int x = str[i] - '0';
        sum+= x;

        if(x == 0)
            flag = true;

        dig.push_back(x);
    }


    if(sum % 3 != 0 || !flag)
    {
        cout << -1;
        return;
    }

    //
    sort(dig.begin(), dig.end());

    for(int i = dig.size() - 1; i >= 0; i--)
        cout << dig[i];

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
