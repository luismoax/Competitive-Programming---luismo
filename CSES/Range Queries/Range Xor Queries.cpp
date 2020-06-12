/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Range Xor Queries
	Link: https://cses.fi/problemset/task/1650/
	Online Judge: CSES
	Idea: Basic use of a Segment Tree
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
#define x first
#define y second
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;

int n, q;
int arr[lim];

// >> SEGMENT TREE
int t[lim << 2];

void buildTree(int idx, int L, int R)
{
	int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	if(L == R)
	{
		t[idx] = arr[L];
		return;
	}
	buildTree(le, L, mid);
	buildTree(ri, mid + 1, R);
	// merge
	t[idx] = t[le] ^ t[ri];
}

ll retrieve(int idx, int L, int R, int QL, int QR)
{
	int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	if(L >= QL && R <= QR)
		return t[idx];
	if(L > QR || R < QL)
		return 0;
	int s1 = retrieve(le, L, mid, QL, QR);
	int s2 = retrieve(ri, mid + 1, R, QL, QR);
	return s1 ^ s2;
}
// << SEGMENT TREE

void solve()
{
	cin >> n >> q;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	buildTree(0, 0, n - 1);
	
	while(q--)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		cout << retrieve(0, 0, n - 1, a, b) << endl;
	}
}
 
void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}
 
void IO()
{
	if(fopen("c:\\Users\\LUISMO\\lmo.in","r") != NULL)
	{
		freopen("c:\\Users\\LUISMO\\lmo.in","r",stdin);
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