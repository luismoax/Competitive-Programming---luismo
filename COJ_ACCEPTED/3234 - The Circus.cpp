/*
    Author: Luis Manuel D�az Bar�n (LUISMO)
    Problem: 3234 - The Circus
    Online Judge: COJ
    Idea: Brute Force
	
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e3 + 7;

int C, N, arr[10004];

void solve()
{
	while(true)
	{
		cin >> C >> N;
		if(C + N == 0) 
			break;
		
		int cnt = 0;
		// reading families
		for(int i = 0; i < N; i++)
		{
			cin >> arr[i];
			if(C >= arr[i])
			{
				C-= arr[i];
				cnt++;
			}
		}
		cout << cnt << " " << C << "\n";
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
    // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
