/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3560 - How Many Square Free Numbers
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

ll prime1 = 1e9 + 9;
ll prime2 = 1e9 + 7;

ll gcd(ll a, ll b)
{
	if(a == 0)
		return b;
	if(b == 0)
		return a;
	if(b == 1)
		return 1;

	if(a == 1)
		return 1;
	return gcd(b, a % b);
}

int N;
ll arr[30];

// map
set< pair<ll, ll> > hash;

ll ggccdd[30][30];

bool bits[30];
void bitMask(int idx, int active, ll h1, ll h2)
{
	// base case
	if(idx == N)
	{
		if(active <= 1)
			return;
		// hash it all
		hash.insert(make_pair(h1, h2));

		return;
	}

	if(idx > 0)
		// do not take this element
		bitMask(idx + 1, active, h1, h2);

	// try to take this element
	for(int i = 0; i < idx; i++)
	{
		if(bits[i] && ggccdd[i][idx] != 1 )
		{
			return;
		}
	}

	// if all actives were coprimes with idx
	bits[idx] = 1;
	bitMask(idx + 1, active + 1, (h1 * (arr[idx]%prime1) ) % prime1, (h2* (arr[idx]%prime2)) % prime2);
	bits[idx] = 0;
}


// precompute gcds
void gcdss()
{
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			ggccdd[i][j] = __gcd(arr[i], arr[j]);
}


void solve()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	N++;

	for(int i = 0; i < N; i++)
		cin >> arr[i];

	// generate GCDs
	gcdss();

	bitMask(0, 0, 1LL, 1LL);

	int sz = hash.size();

	cout << sz << "\n";
}



int main()
{
	if(fopen("/home/mpc-tlj/Desktop/lmo.in", "r"))
		freopen("/home/mpc-tlj/Desktop/lmo.in", "r", stdin);

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
