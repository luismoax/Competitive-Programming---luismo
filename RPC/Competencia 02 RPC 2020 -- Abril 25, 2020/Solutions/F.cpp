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
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e7 + 3;
const ll mod = (1ll << 32);
const int lim = 1e5 + 2;

ll N, C, x;
vector<ll> buckets;

void solve()
{
	cin >> N >> C;
	for(int i = 0; i < N; i++)
	{
		cin >> x;
		buckets.push_back(x);
	}
	sort(buckets.begin(), buckets.end());
    // for(int i = 0; i < buckets.size(); i++)
    //     cout << buckets[i] << " ";
    // cout << endl;
	int answ = 0;
	ll cnt = 0;
    int le = 0, ri = N - 1;
	while(le < ri)
	{
		if(buckets[le] + buckets[ri] <= C)
		{
			answ++;
			le++;
			ri--;
		}
		else
		{
			answ++;
			ri--;
		}
	}

	if(le == ri)
		answ++;

	cout << answ;

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
