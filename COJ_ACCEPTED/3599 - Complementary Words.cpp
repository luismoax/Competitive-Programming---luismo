/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3599 - Complementary Words
	Online Judge: COJ
	Idea: DP. Precompute all intervals andanswer queries in O(1). DP from the minor to the greater intervals
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 3e3 + 7;

string str;
int Q;
int cumul[lim];

int query(int s, int e)
{
	if(s == 0)
		return cumul[e];
	return cumul[e] - cumul[s - 1];
}

bool dp[lim][lim];

void processDP()
{
	int len = str.length();
	for(int sz = 1; sz <= len; sz++)
	{
		for(int i = 0; i + sz - 1 < len; i++)
		{
			int l = i;
			int r = i + sz - 1;

			int k1 = str[l] - 'a' + 1;
			int k2 = str[r] - 'a' + 1;

			int sm = k1 + k2;

			if(l + 1 <= r - 1)
			{
				if(dp[sz - 2][i + 1])
				{
					int blockLen = r - 1 - l;

					int cc = query(l + 1, r - 1);

					if(blockLen % 2 == 1)
					{
						int mid = (l + 1 + r - 1) >> 1;
						cc += cumul[mid] - cumul[mid - 1];
					}

					if(cc % (blockLen/2 + blockLen%2) == 0 && ((cc / (blockLen/2 + blockLen%2)  ==  sm)))
						dp[sz][i] = true;
					else dp[sz][i] = false;
				}
				else dp[sz][i] = false;
			}
			else
				dp[sz][i] = true;

		}
	}
}

void solve()
{
	cin >> str >> Q;

	// cumulative table
	for(int i = 0; i < str.length(); i++)
		if(i == 0)
			cumul[i] = str[i] - 'a' + 1;
		else cumul[i] = cumul[i - 1] + (str[i] - 'a' + 1);

	// DP procedure
	processDP();

	for(int i = 0; i < Q; i++)
	{
		int ai, bi;
		cin >> ai >> bi;
		//ai--; bi--;

		if(ai > bi)
			swap(ai, bi);

		int len = bi - ai + 1;

		if(dp[len][ai])
			cout << "yes\n";
		else cout << "no\n";
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
