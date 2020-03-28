/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3675 - Juan at Gym
	Online Judge: COJ
	Idea: BitMask
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define dd double
#define ld long double
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

typedef pair<int, int> pii;
const ll inf = 1e18 + 3;
const int mod = 1e9 + 7;
const int lim = 100 + 7;

int N;
dd P, B;
dd weights[lim];

dd epsilon = 0.000001;

struct setComparer
{
    bool operator() (const dd a, const dd b) const
    {
        return a + epsilon < b;
    }
};


set<dd, setComparer> rbTree;


void solve()
{
    // cin >> N >> P >> B;
    sf("%d%lf%lf", &N, &P, &B);

    for(int i = 0; i < N; i++)
        // cin >> weights[i];
        sf("%lf", &weights[i]);


    // bitmask
    for(int mask = 1; mask < (1<<N); mask++)
    {
        dd cur = B;
        // for
        for(int j = 0; j < N; j++)
        {
            if( (mask&(1<<j)) > 0 )
                cur+= (weights[j] + weights[j]);
        }

        if(cur >= P - 0.000001)
            rbTree.insert(cur);
    }

	if(rbTree.size() == 0)
        // cout << "Strong";
        pf("Strong");
    else // cout << rbTree.size();
        pf("%d", rbTree.size());
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

	// cin.sync_with_stdio(false);
	// cin.tie(0);

	solve();
}

