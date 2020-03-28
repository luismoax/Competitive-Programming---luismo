// Solved on contest
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int lim = 500 + 7;


string pattern, carving;
int N, M;

// tables to dynamically store the frequencies
int hashPattern[200];
int hashCarving[200];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	if(fopen("/home/mpc-tlj/Desktop/lmo.in", "r"))
		freopen("/home/mpc-tlj/Desktop/lmo.in", "r", stdin);

	cin >> N >> M;

	cin >> pattern >> carving;

	int answ = 0;

	int cntDifferenPattern = 0;
	for(int i = 0; i < pattern.length(); i++)
	{
		char cc = pattern[i];
		if(hashPattern[cc] == 0)
			cntDifferenPattern++;

		hashPattern[cc]++;
	}

	int ok = 0;

	for(int i = 0; i < pattern.length(); i++)
	{
		char cc = carving[i];

		// it changes
		if(hashCarving[cc] == hashPattern[cc] && hashCarving[cc] > 0)
			ok--;

		hashCarving[cc]++;

		if(hashCarving[cc] == hashPattern[cc] && hashPattern[cc] > 0)
			ok++;
	}

	if(ok == cntDifferenPattern)
		answ++;

	// for CARVING
	for(int i = pattern.length(); i < carving.length(); i++)
	{
		// the one that I take
		int cc = carving[i];

		// if this char were all right
		if(hashCarving[cc] == hashPattern[cc] && hashPattern[cc] > 0)
			ok--;
		hashCarving[cc]++;

		if(hashCarving[cc] == hashPattern[cc])
			ok++;
		// now with the one left behind
		cc = carving[i - pattern.length()];
		// if this char were all right
		if(hashCarving[cc] == hashPattern[cc])
			ok--;
		hashCarving[cc]--;

		if(hashCarving[cc] == hashPattern[cc] && hashPattern[cc] > 0)
			ok++;
		// compare
		if(ok == cntDifferenPattern)
			answ++;
	}

	cout << answ << "\n";
}
