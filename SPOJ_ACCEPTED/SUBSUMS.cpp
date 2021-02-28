/*
	Author: Luis Canuel Díaz Barón (LUISCO)
	Problem: Subset Sums
	Link: https://www.spoj.com/problems/SUBSUMS/
	Online Judge: SPOJ
	Idea: Meet In The Middle + Bitmask + Binary Search. See Implementation
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e9;
const int mod = 1e9 + 7;
const int lim = 3e2 + 3;

ll N, A, B;

void solve()
{
	cin >> N >> A >> B;

    
	vector<ll> arr(N, 0);
    // read whole collection
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	ll answ = 0;
    // case N = 1
	if(N == 1)
	{
		int ret = 0;
		if(arr[0] >= A && arr[0] <= B)
			ret++;
		if(A <= 0 && B >= 0)
			ret++;
		cout << ret;
		return;
	}

    // vectors to store subset sums per halves
	vector<ll> left, right;

    // divide the whole collection in half
	int mid = (N-1) / 2;
	int szLe = mid + 1;
	int szRi = N - szLe;
	// find all the possible subset sums for the left half
	for(int mask = 0; mask < (1ll << szLe); mask++)
	{
		ll sm = 0;
		for(int i = 0; i < szLe; i++)
		{
			if( mask&(1ll<<i) )
			{
				sm += arr[i];
			}
		}
		left.push_back(sm);
	}
    // find all the possible subset sums for the right half
	for(int mask = 0; mask < (1ll << szRi); mask++)
	{
		ll sm = 0;
		for(int i = 0; i < szRi; i++)
		{
			if( mask&(1ll<<i) )
			{
				sm += arr[mid + 1 + i];
			}
		}
		right.push_back(sm);
	}
    // sort 'em all
	sort(left.begin(), left.end());
	sort(right.begin(), right.end());

    // Meet In The Middle
	for(int i = 0; i < left.size(); i++)
	{
		ll val = left[i];

		ll srcUpper = B - val;
        
		int ub = upper_bound(right.begin(), right.end(), srcUpper) - right.begin();

		ll srcLower = A - val;

		int lb = lower_bound(right.begin(), right.end(), srcLower) - right.begin();

		answ += ub - lb;
	}
    // print answer
	cout << answ << endl;
}
 
void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}
 
void IO()
{

	if(fopen("c:\\Competitive Programming\\lmo.in","r") != NULL)
	{
		freopen("c:\\Competitive Programming\\lmo.in","r",stdin);
	}
	else if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("media/Beijing/lmo.in","r") != NULL)
	{
		freopen("/media/Beijing/lmo.in", "r", stdin);
	}
}
 
int main()
{
	IO();
 
	fastIO();
 
	solve();
}