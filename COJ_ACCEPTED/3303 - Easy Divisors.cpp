/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3303 - Easy Divisors
	Online Judge: COJ
	Idea: For each possible K store all indexes: idx, such that arr[idx] is divisible by K, in order, so each query can be performed in O(logN) using binary search. O(N*sqrt(10^6)) + O(Q*logN).
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
int N, Q;

int arr[lim];
vector<int> coll[lim];
int a, b, k;

void solve()
{
    cin >> N;
    // reading integers
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
        // divisors
        for(int div = 1; div * div <= arr[i]; div++)
        {
            if(arr[i] % div == 0)
            {
                coll[div].push_back( i );
                if(div * div != arr[i])
                    coll[arr[i] / div].push_back(i);
            }
        }
    }
    cin >> Q;

    // for each query
    for(int i = 0; i < Q; i++)
    {
        cin >> a >> b >> k;
        a--; b--;
/*
        cout << k << ": ";
        for(int j = 0; j < coll[k].size(); j++)
            cout << coll[k][j] << " ";
        cout << "\n";
*/

        int ub = upper_bound(coll[k].begin(), coll[k].end(), b) - coll[k].begin();
        int lb = lower_bound(coll[k].begin(), coll[k].end(), a) - coll[k].begin();
        cout << ub - lb << "\n";
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
