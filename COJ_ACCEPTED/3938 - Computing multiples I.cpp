/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3938 - Computing multiples I
	Online Judge: COJ
	Idea: BitMask ~ Inclusion / Exclusion
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

ll K, N;

vector<ll> arr;

void solve()
{
    cin >> K >> N;
    ll x;
    // reading integers
    for(int i = 0; i < N; i++)
    {
        cin >> x;
        arr.push_back(x);
    }

    ll answ = 0;

    // bit mask
    for(int mask = 1; mask < (1 << N); mask++)
    {
        ll aux = 1;
        int ab = 0; // active bits

        // for each possible active bit
        for(int i = 0; i < N; i++)
        {
            if((mask & (1 << i)) != 0)
            {
                aux *= arr[i] / __gcd(aux, arr[i]);
                ab++; // increase the number of active bits
            }
        }

        ll div = K / aux; // number of multiples

        if(ab % 2 == 1)
            answ+= div;
        else answ-= div;
    }
    // print the answer
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
