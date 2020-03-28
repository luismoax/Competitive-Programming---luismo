/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: FACTCG2
    Online Judge: SPOJ
    Idea: Nice Problem. Use Eratostenes' sieve and store in position i the minimun prime number
	which divides i.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define lim  10000007

using namespace std;

int sieve[lim];

void eratostenes()
{
	sieve[2] = 2;

	for(int i = 4; i < lim; i+= 2)
		sieve[i] = 2;

	for(int i = 3; i < lim; i+= 2)
	{
		if(sieve[i] == 0)
		{
			sieve[i] = i;
			for(int j = i + i; j < lim; j+= i)
			{
				if(sieve[j] == 0)
					sieve[j] = i;
			}
		}
	}
}

int N;

void solve()
{
	eratostenes();

	while(cin >> N)
	{
		if(N == 1)
			cout << "1";
		else
		{
			cout << "1";

			while(N > 1)
			{
				cout << " x " << sieve[N];
				N /= sieve[N];
			}
		}
		cout << "\n";
	}

}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("d:\\lmo.in","r",stdin);
	// freopen("d:\\lmo.out","w",stdout);
}

int main()
{
    // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
