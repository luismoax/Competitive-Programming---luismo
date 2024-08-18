/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Traffic Lights
	Link: https://cses.fi/problemset/task/1163
	Online Judge: CSES
	Idea: After inserting all the lights into a Red-Black Tree in their original order, process the lights in the reverse order of their insertion. 
	For each light removal, calculate the gap that is formed between the neighboring lights that were present before the current light was inserted.
	 Update the maximum gap after each removal, keeping track of the largest gap throughout the process.
*/
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
// Types
#define ll long long
#define i64 unsigned long long
#define ld long double
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define M_PI 2.0 * acos(0)
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 2e5 + 5;
const ld epsilon = 0.000001;

int x, n;

void solve()
{
	cin >> x >> n;

	set<int> rbTree;

	// Add first and last poles
	rbTree.insert(0);
	rbTree.insert(x);


	vector<int> vect(n, 0);

	// storing the lights in the order they are inserted, and pushing them in the Red-Black Tree
	for(int i = 0; i < n; i++)
	{
		cin >> vect[i];
		rbTree.insert(vect[i]);
	}

	
	// find the greatest gap at the end of the insertions
	int mx = 0;
	int lst = 0;

	for(auto item: rbTree)
	{
		mx = max(item - lst, mx);
		lst = item;
	}	

	// vector to store the answers
	vector<int> answ;
	answ.push_back(mx);

	// interate in the inverted order of insertions
	for(int i = 0; i < n; i++)
	{
		// index
		int idx = n - 1 - i;
		// current value
		int v = vect[idx];
		// erase the value from the Red-Black Tree
		rbTree.erase(v);

		// find lower and upper bound for the current value
		set<int>::iterator leIter = rbTree.lower_bound(v);
		leIter--;
		set<int>::iterator riIter = rbTree.upper_bound(v);
		

		int le = *leIter;
		int ri = *riIter;
		
		// find distance between poles existing before the insertion of the current one
		int curr = ri - le;

		// update the maximun gap value
		mx = max(curr, mx);

		// insert the answer
		answ.push_back(mx);
	}

	// print the answers
	for(int i = 0; i < n; i++)
	{
		int idx = n - 1 - i;

		cout << answ[idx] << " ";
	}
	cout << endl;

}
void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	const char *route = "c:\\Users\\LUISMO\\lmo.in";

	if (fopen(route, "r") != NULL)
	{
		freopen(route, "r", stdin);
	}
}

int main()
{
	IO();

	fastIO();

	solve();
}