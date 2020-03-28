/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3321 - Last Digits of Primorial
	Online Judge: COJ
	Idea: Eratostenes Sieve + Cumulative Table
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
const ll mod = 10000000000;

ll N;

bool sieve[lim];

vector<int> primes;

ll cumul[lim];

void erat()
{
	primes.push_back(2);
	sieve[0] = sieve[1] = true;

	for(int i = 4; i < lim; i+= 2)
		sieve[i] = true;

	for(int i = 3; i < lim; i+= 2)
	{
		if(!sieve[i])
		{
			primes.push_back(i);
			for(int j = i + i; j < lim; j+= i)
				sieve[j] = true;
		}
	}

/*
	for(int i = 0; i < 20; i++)
		cout << primes[i] << "\n";
*/

	cumul[0] = 1;
	for(int i = 1; i < lim; i++)
	{
		if(!sieve[i])
		{
			cumul[i] = (cumul[i - 1] * i);

			if(cumul[i] > 9999999999)
				cumul[i] %= mod;
		}
		else cumul[i] = cumul[i - 1];
	}

/*
	for(int i = 1; i <= 50; i++)
	{
		cout << i << " " <<  cumul[i] << endl;
	}
*/
}



int tc;
void solve()
{
	erat();

	cin >> tc;
	while(tc--)
	{
		cin >> N;

		ll dig = log10(cumul[N]) + 1;

		if(N > 30)
		{
			int zeroes = 10 - dig;
			for(int i = 0; i < zeroes; i++)
				cout << "0";
		}

		cout << cumul[N] << "\n";
	}


}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
		freopen("d:\\lmo.in","r",stdin);

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
