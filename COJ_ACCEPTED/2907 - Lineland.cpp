/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 2907 - Lineland
	Online Judge: COJ
	Idea: Sort + Binary Search (upper bound)
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
const int mod = 1e9 + 7;
const int lim = 2e5 + 2;

int N;
vector<pll> cities;

void solve()
{
    while(cin >> N)
    {
        cities.clear();
        // reading sities
        for(int i = 0; i < N; i++)
        {
            pll aux;
            cin >> aux.first >> aux.second;
            cities.push_back(aux);
        }
        // sort em' all
        sort(cities.begin(), cities.end());

        int idx = cities[0].first;
        int cnt = 0;

        for(int i = 0; i < cities.size(); i++)
        {
            int xi = cities[i].first;
            int ci = cities[i].second;

            // upper bound
            int L = i + 1;
            int R = cities.size();
			// binary search
            while(L != R)
            {
                int mid = (L + R) / 2;

                if(cities[mid].first <= xi + ci)
                    L = mid + 1;
                else R = mid;
            }
			// update if better 
            if(R - i - 1> cnt)
            {
                cnt = R - i - 1;
                idx = cities[i].first;
            }
        }
		// print answer
        cout << idx << " " << cnt << endl;
    }


}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
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

	fastIO();

	solve();
}
