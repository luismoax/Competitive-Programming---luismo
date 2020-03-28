/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: 1912 - Extending Fibonacci
	Online Judge: COJ
	Idea: Offline
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18 + 3;
const int mod = 1000000007;
const int lim = 1e7 + 2;

ll N, K, T;

vector<pll> queries;

ll answ[4000];


void solve()
{
    cin >> T >> K;

    for(int i = 0; i < T; i++)
    {
        cin >> N;
        queries.push_back(make_pair(N, i));
    }

    // sort by value
    sort(queries.begin(), queries.end());

    int qIdx = 0;

    while(qIdx < queries.size() && queries[qIdx].first < K)
    {
        answ[queries[qIdx].second] = 1;
        if(queries[qIdx].first == 0)
            answ[queries[qIdx].second] = 0;
        qIdx++;
    }

    queue<ll> q;

	// current element
	ll curr = K - 1;
	for(int i = 1; i < K; i++)
		q.push(1);


    for(int i = K; i < lim && qIdx < queries.size(); i++)
    {
        while(qIdx < queries.size() && queries[qIdx].first == i)
        {
            answ[queries[qIdx].second] = curr;
            qIdx++;
        }

        q.push(curr);

		curr = (curr + curr) % mod;

		if(q.size() > K)
        {
            curr = (curr - q.front() + mod) % mod;
            q.pop();
        }
    }

    for(int i = 0; i < T; i++)
        cout << answ[i] << "\n";
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
