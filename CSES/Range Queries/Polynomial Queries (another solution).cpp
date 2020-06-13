/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Polynomial Queries
	Link: https://cses.fi/problemset/task/1736
	Online Judge: CSES
	Idea: Use a Segment Tree which updates in ranges with values 1, 2, 3, .... N.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
// IO
#define sf scanf
#define pf prllf
#define mkp make_pair
#define x first
#define y second
#define endl "\n"
 
using namespace std;
 
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll lim = 2e5 + 3;
 
ll n, q;
ll arr[lim];
 
// >> SEGMENT TREE
ll t[lim << 2];
ll lazy[lim << 2];
ll upds[lim << 2]; 
 
ll F(ll len, ll bs, ll cnt)
{
	return (len * bs) + (cnt * ((len * (len - 1)) / 2));
}
 
void buildTree(ll idx, ll L, ll R)
{
	ll le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	if(L == R)
	{
		t[idx] = arr[L];
		return;
	}
	buildTree(le, L, mid);
	buildTree(ri, mid + 1, R);
	// merge
	t[idx] = t[le] + t[ri];
}
 
 
void propagate(ll idx, ll L, ll R)
{
	ll le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	ll len = R - L + 1;
	if(upds[idx] > 0)
	{
		ll k = F(len, lazy[idx], upds[idx]);
 
		t[idx] += k;
 
		if(L != R)
		{
			lazy[le] += lazy[idx];
			upds[le] += upds[idx];
 
			ll half = (len % 2 == 0)?(len / 2):(len / 2 + 1);
 
			lazy[ri] += lazy[idx] + half * upds[idx];
			upds[ri] += upds[idx];
		}
	}
	lazy[idx] = upds[idx] = 0;	
}
 
void update(ll idx, ll L, ll R, ll QL, ll QR)
{
	ll le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	ll len = R - L + 1;
 
	propagate(idx, L, R);
 
	if(R < QL || L > QR)
		return;
		
	// if contained
	if(L >= QL && R <= QR)
	{
		ll k = F(len, L - QL + 1, 1);
 
		t[idx] += k;
 
		if(L != R)
		{
			lazy[le] += L - QL + 1;
			upds[le]++;
					
			lazy[ri] += mid + 1 - QL + 1;
			upds[ri]++;
		}
		return;
	}
 
	update(le, L, mid, QL, QR);
	update(ri, mid + 1, R, QL, QR);
 
	t[idx] = t[le] + t[ri];
}
 
ll retrieve(ll idx, ll L, ll R, ll QL, ll QR)
{	
	ll le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	ll len = R - L + 1;
 
	propagate(idx, L, R);
 
	if(R < QL || L > QR)
		return 0;
 
	// if contained
	if(L >= QL && R <= QR)
		return t[idx];
 
	ll s1 = retrieve(le, L, mid, QL, QR);
	ll s2 = retrieve(ri, mid + 1, R, QL, QR);
 
	return s1 + s2;
}
 
void DFS(ll idx, ll L, ll R)
{
	if(L == R)
	{
		cout << L << "," << R << ": " << t[idx] << " " << lazy[idx] << " " << upds[idx] << endl;
		return;
	}
	ll le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	DFS(le, L, mid);
	DFS(ri, mid + 1, R);
	cout << L << "," << R << ": " << t[idx] << " " << lazy[idx] << " " << upds[idx] << endl;
} 
// << SEGMENT TREE
 
void solve()
{
	cin >> n >> q;
	for(ll i = 0; i < n; i++)
		cin >> arr[i];
 
	buildTree(0, 0, n - 1);
	
	while(q--)
	{
		ll t, a, b;
		cin >> t >> a >> b;
		a--; b--;
		if(t == 1)					
			update(0, 0, n - 1, a, b);		
		else				
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