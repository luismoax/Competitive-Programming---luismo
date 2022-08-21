/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 
	Link: 
	Online Judge: 
	Idea: 
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define M_PI 2.0 * acos(0)
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 1e3 + 3;

int N, K;

void solve()
{
	cin >> N >> K;
	vector<ll> arr((1 << N), 0);
	for(int i = 0; i < (1 << N); i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());

	ll answ = 0;

	int sz = (1 << N);
	int len = sz;
	int idx = 0;
	while(len > 1)
	{
		set<ll> rbTree;
		for(int i = 0; i < (len / 2); i++)
			rbTree.insert(arr[idx + i]);
		
		// backwards
		for(int i = 0; i < (len / 2); i++)
		{
			int kidx = (sz - 1) - i;
			ll currVal = arr[kidx];

			set<ll>::iterator it = rbTree.lower_bound(currVal - K);
			if(it != rbTree.end())
			{
				ll v = *it;
				if(currVal - v <= K)
				{
					
 					answ++;
				}
				else it = rbTree.begin();
			}
			else it = rbTree.begin();

			rbTree.erase(it);
		}

		idx += len / 2;
		len = len / 2;
	}
	cout << answ << endl;
}
 
void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}
 
void IO()
{

	if(fopen("c:\\Users\\LUISMO\\lmo.in","r") != NULL)
	{
		freopen("c:\\Users\\LUISMO\\lmo.in","r",stdin);
	}
	else if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("media/Beijing/lmo.in","r") != NULL)
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