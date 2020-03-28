/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3723 - Consecutive Subsequences
	Online Judge: COJ
	Idea: While reading the numbers keep their sum, and keep a hash array [0...99] storing the remainder of each sum
	achieved before, then answer += hash[sum % K] and then update hash[sum % K]++;
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

ll int arr[lim];
int K, N, tc;
int hash[100]; // to hash remainders

void solve()
{
    cin >> tc;
    while(tc--)
    {
        cin >> N >> K;
        memset(hash, 0, sizeof hash);
        ll sum = 0; // total sum
        ll answ = 0; // answer
        // base
        hash[0] = 1;
        // reading integers
        for(int i = 0; i < N; i++)
        {
            cin >> arr[i];
            sum+= arr[i];
            int rem = sum % K;
            // update the answers
            answ+= hash[rem];
            // update the hash
            hash[rem]++;
        }
        // print answer
        cout << answ << "\n";
    }
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
