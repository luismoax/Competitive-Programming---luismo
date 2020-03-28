/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3768 - Buckets for your house
	Online Judge: COJ
	Idea: Linear scan, keep a cumulative table and use a map to store cumulative values. O(NlogN)
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e5 + 7;

int N, K;
ll arr[lim];
ll cumul[lim];

map<ll, int> m;

void solve()
{
    cin >> N >> K;
    int answ = 200003;
    // reading
    m[0] = 0;
    for(int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        cumul[i] = cumul[i - 1] + arr[i];

        int pos = -1;

        if(m.find(cumul[i] - K) != m.end())
            pos = m[cumul[i] - K];

        if(pos != -1)
            answ = min(answ, i - pos);

        m[cumul[i]] = i;


        // cout << answ << endl;
    }

    if(answ == 200003) answ = -1;

    cout << answ;

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
