/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem:
	Online Judge: COJ
	Idea:
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

int L, N;
ll arr[lim];
ll lucky[lim];
ll answ[lim];

map<ll, int> m;

void solve()
{
    cin >> L;
    //reading L lucky numbers
    for(int i = 0; i < L; i++)
        cin >> lucky[i];


    m[0]++;
    ll sum = 0;
    cin >> N;
    // reading N numbers
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
        sum+= arr[i];

        // for each lucky number
        for(int lu = 0; lu < L; lu++)
        {
            ll diff = sum - lucky[lu];

            if(m.find(diff) != m.end())
                answ[lu]+= m[diff];
        }

        m[sum]++;
    }
    for(int i = 0; i < L; i++)
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
