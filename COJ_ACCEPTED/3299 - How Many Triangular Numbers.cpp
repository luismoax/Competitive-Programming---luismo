/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3299 - How Many Triangular Numbers?
    Online Judge: COJ
    Idea: Easy. Binary Search
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const ll lim = 2e12;

vector<ll> triang;

ll a, b;


int binarySearch(ll ii, int L, int R)
{
	if(L == R)
		return L;
	int mid = (L + R) >> 1;
	if(ii == triang[mid]) return mid;
	if(ii < triang[mid]) return binarySearch(ii, L, mid);
	return binarySearch(ii, mid + 1, R);
}

void solve()
{
	int cnt = 0;
	ll k = 1;
	
	//
	triang.push_back(-1);
	//
	while( ((k *(k + 1)) >> 1) <= lim)
	{
		triang.push_back(((k *(k + 1)) >> 1));
		cnt++;
		k++;
	}

	while(cin >> a >> b)
	{
		if(a + b == 0) return;

		int idxA = binarySearch(a, 0, triang.size() - 1);
		int idxB = binarySearch(b, 0, triang.size() - 1);		

		if(triang[idxA] < a) idxA++;
		if(triang[idxB] > b) idxB--;

		cout << idxB - (idxA - 1) << "\n";
	}
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("e:\\lmo.in","r",stdin);
	// freopen("e:\\lmo.out","w",stdout);
}

int main()
{
    // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
