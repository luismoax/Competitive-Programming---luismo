/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1083 - Histogram
	Online Judge: LightOJ
	Idea: Using a Stack. The idea behind is to calculate for each bar the greatest rectangle
	containing it and in which it has lowest hight. So foreach bar X we calculate the distance of the nearest bar with lower height to the left of X and the same to the right of X.
	The problem its reduced to the one finding the nearest lower element.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e6 + 7;

ll arr[lim];
int N = -1;
int tc;
int aux[lim];

void solve()
{
    sf("%d", &tc);
    for(int cs = 1; cs <= tc; cs++)
    {
//        cin >> N;
sf("%d", &N);
        // reading heights
        for(int i = 0; i < N; i++)
        {
            //cin >> arr[i];
            sf("%lld", &arr[i]);
            aux[i] = 1;
        }

        stack<ll> stk;
        stk.push(-1);

        // linear scan
        for(int i = 0; i < N; i++)
        {
            while(stk.top() != -1 && arr[stk.top()] >= arr[i])
                stk.pop();

            aux[i] = i - stk.top();

            stk.push(i);
        }

        // clear the stack
        while(stk.size() > 0) stk.pop();
        stk.push(N);

        ll mx = 0;

        // linear scan backwards
        for(int i = N - 1; i >= 0; i--)
        {
            while(stk.top() != N && arr[stk.top()] >= arr[i])
                stk.pop();

            int dist = stk.top() - i;

            mx = max(mx, (dist + aux[i] - 1) * arr[i]);

            stk.push(i);
        }

        // print answer
        //cout << mx << "\n";
        pf("Case %d: %lld\n",cs, mx);
    }
}

int main()
{
	
	solve();
}
