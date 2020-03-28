/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3471 - Prime Digits
	Online Judge: COJ
	Idea: Ad-Hoc. NT
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;
int N, M;

const int lim = 1e6 + 7;
bool sieve[1000007];

void buildSieve()
{
	sieve[0] = true;

	for(int i = 4; i < lim; i+= 2)
		sieve[i] = true;

	for(int i = 3; i < lim; i+= 2)
	{
		if(!sieve[i])
			for(int j = i + i; j < lim; j+= i)
				sieve[j] = true;
	}
/*
	for(int i= 0; i <= 31; i++)
		cout << i << " " << sieve[i] << endl;
*/
}

int A, B;

vector<int> v;

int sol[lim];

void solve()
{
	buildSieve();

	cin >> A >> B;

	int cnt = 0;

	while(A > 0)
	{
		int k = A % B;

		if(k == 1 || !sieve[k])
		{
			cnt++;
			sol[k]++;
		}
		A/= B;
	}

	cout << cnt;
	if(cnt > 0)
		cout << " ";

	for(int i = 0; i < lim; i++)
		if(sol[i] > 0)
		{
			for(int f = 0; f < sol[i]; f++)
			{
				cnt--;

				if(cnt > 0)
					cout << i << " ";
				else cout << i;

			}
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
