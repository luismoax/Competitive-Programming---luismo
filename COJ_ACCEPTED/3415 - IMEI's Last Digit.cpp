/*
    Author: Luis Manuel D?az Bar?n (LUISMO)
    Problem: 3415 - IMEI's Last Digit
    Online Judge: COJ
    Idea: Easy Ad-Hoc
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

int tc;
string str;

void solve()
{
	cin >> tc;
	while(tc-->0)
	{
		cin >> str;
		int sum = 0;
		for(int i = 0; i < str.length(); i++)
		{
			if(i % 2 == 0)
				sum += str[i] - '0';
			else
			{
				int aux = (str[i] - '0') * 2;
				sum+= (aux / 10 + aux % 10);
			}
		}
		sum %= 10;
		if(sum > 0)
			sum = 10 - sum;
		cout << sum << endl;
	}
}

int main()
{
	
    solve();
}
