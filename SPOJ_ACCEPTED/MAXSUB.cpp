/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: https://www.spoj.com/problems/MAXSUB/
	Online Judge: SPOJ
	Idea: Ad-Hoc. Sort + Modular Exponentiation
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e16 + 3;
const int mod = 1000000009;
const int lim = 2e5 + 2;

int tc, N;

ll arr[lim];

ll binPow(ll b, ll e)
{
	if(e == 0)
		return 1;
	if(e == 1)
		return b;
	
	ll aux = binPow(b, e / 2);
	aux = (aux * aux) % mod;
	if(e % 2 == 1)
		aux = (aux * b) % mod;
	return aux; 
}


void solve()
{
	cin >> tc;
	while(tc-- > 0)
	{
		cin >> N;

		for(int i = 0; i < N; i++)
			cin >> arr[i];
		
		sort(arr, arr + N);

		int zeroes = 0;

		if(arr[N - 1] < 0)
		{
			int cnt = 1;
			int idx = N - 2;
			while(idx >= 0 && arr[idx] == arr[N - 1])
			{
				idx--;
				cnt++;
			}
			cout << arr[N - 1] << " " << cnt << endl; 
		}
		else
		{
			ll answ = 0;
			ll cnt = 0;
			for(int i = N - 1; i >= 0 && arr[i] >= 0; i--)
			{
				if(arr[i] == 0)
					zeroes++;
				answ += arr[i];
			}
			cnt = binPow(2, zeroes);
			if(answ == 0)
				cnt--;
			cout << answ << " " << cnt <<endl;
		}
	}
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	if(fopen("c:\\lmo.cpp","r") != NULL)
	{
		freopen("c:\\lmo.cpp","r",stdin);
	}
	else if(fopen("/media/Beijing/lmo.in","r") != NULL)
	{
		freopen("/media/Beijing/lmo.in", "r", stdin);
	}
}

int main()
{
	IO();

	fastIO();

	solve();
}
