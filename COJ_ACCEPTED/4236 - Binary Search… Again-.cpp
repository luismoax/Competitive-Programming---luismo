/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 4236 - Binary Search… Again?
	Online Judge: COJ
	Idea: Brute Force. Just do what it says
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
const int mod = 1e9;
const int lim = 1e5 + 2;

int tc;
int N;
ll arr[lim];
ll cumul[lim];

ll query(int a, int b)
{
	if(a > 0)
		return cumul[b] - cumul[a-1];
	return cumul[b];
}

void solve()
{
	// cin >> tc;
	sf("%d", &tc);
	while(tc -- >0)
	{
		// cin >> N;
		sf("%d", &N);
		for(int i = 0; i < N; i++)
		{
			// cin >> arr[i];
			sf("%lld", &arr[i]);
			cumul[i] = arr[i];
			if(i > 0)
				cumul[i] += cumul[i-1];
		}

		vector<int> toTheGarbage;
		int le = 0, ri = N - 1;
		while(le < ri)
		{
			if((ri - le + 1) % 2 == 1)
			{
				toTheGarbage.push_back(arr[ri--]);
			}

			int mid = (le+ri)/2;

			ll qLeft = query(le, mid);
			ll qRight = query(mid + 1, ri);

			if(qLeft <= qRight)			
				ri = mid;			
			else
				le = mid + 1;
		}

		// cout << arr[le] << endl;
		pf("%lld\n", arr[le]);
		sort(toTheGarbage.begin(), toTheGarbage.end());
		for(int i = 0; i < toTheGarbage.size(); i++)
			// cout << toTheGarbage[i] << " ";
			pf("%lld ", toTheGarbage[i]);
		// cout << endl;
		pf("\n");
	}
}

// void fastIO()
// {
// 	cin.sync_with_stdio(false);
// 	cin.tie(0);
// }

void IO()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("/media/Beijing/lmo.in","r") != NULL)
	{
		freopen("/media/Beijing/lmo.in", "r", stdin);
	}
}

int main()
{
	IO();

	// fastIO();

	solve();
}