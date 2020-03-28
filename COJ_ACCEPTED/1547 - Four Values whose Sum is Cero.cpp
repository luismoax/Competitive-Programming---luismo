/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1547 - Four Values whose Sum is Cero
	Online Judge: COJ
	Idea: Meet In The Middle. Store in a map the frequency of each sum of a pair from column A and column B. Then for each possible sum of a pair from column C and column D, see if its negative value has alredy been stored in the map.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 4e3 + 3;

int N;

int A[lim];
int B[lim];
int C[lim];
int D[lim];

map<ll, ll> m;

void solve()
{
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> A[i] >> B[i] >> C[i] >> D[i];

    // O(N^2 * logN)
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            ll sum = A[i] + B[j];
            m[sum]++;
        }
    }

    ll answ = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            ll sum = C[i] + D[j];

            ll aux = m[-sum];

            answ+= aux;
        }
    }
    // print answer
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
