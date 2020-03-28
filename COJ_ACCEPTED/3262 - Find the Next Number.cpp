/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3262 - Find the Next Number
    Online Judge: COJ
    Idea: Sweep line backwards, keep track of the last apparence of each number while sweeping.
	For each number check all its coprimes (in the range 1 -> 100) and the solution is the one
	with the last apparence if at least one did, otherwise the answer is -1
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

const int lim = 1e4 + 7;

int N, arr[lim], tc;

int hashTable[101]; //

int solution[lim];

bool gcdMt[101][101];

void preProc()
{
	for(int i = 1; i <= 100; i++)
		for(int j = 1; j <= 100; j++)
			if(gcd(i, j) == 1)
				gcdMt[i][j] = true;
}

void solve()
{
	preProc();

	cin >> tc;
	while(tc-->0)
	{
		fill(hashTable, hashTable + 101, -1);

		cin >> N;
		// reading integers
		for(int i = 0; i < N; i++)
			cin >> arr[i];

		// sweeping backwards
		for(int i = N - 1; i >= 0; i--)
		{
			int bestIdx = -1;

			// finding GCD
			for(int k = 100; k >= 1; k--)
				if(gcdMt[k][arr[i]] && hashTable[k] != -1 && (hashTable[k] < bestIdx || bestIdx == -1))
					bestIdx = hashTable[k] + 1;

			// update hash table
			hashTable[arr[i]] = i;

			solution[i] = bestIdx;
		}


		// printing solution
		for(int i = 0; i < N; i++)
			if(i == 0)
				cout << solution[i];
			else cout << " " << solution[i];

		if(tc > 0)
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
