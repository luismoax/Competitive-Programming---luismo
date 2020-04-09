/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: DMOPC '19 Contest 6 P3 - Grade 11 Math
    Link: https://dmoj.ca/problem/dmopc19c6p3
	Online Judge: dmoj.ca
	Idea: Use a Segement Tree storing powers of two
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
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 500000 + 3;

int len, Q;
string str;

int arr[lim];
int t[lim << 2];
int lz[lim << 2];

ll binPow(ll b, ll exp)
{
	if(exp == 0)
		return 1;
	ll aux = binPow(b, exp / 2);
	aux = (aux * aux) % mod;
	if(exp % 2 == 1)
		aux = (aux * b) % mod;
	return aux;
}

ll sums[lim];
void preProcess()
{
	for(int i = 0; i < len; i++)
	{
		int idx = len - 1 - i;
		ll k = binPow(2, i);
		
		sums[idx] = (k + sums[idx + 1]) % mod;
	}
}

void build(int idx, int L, int R)
{
	int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	if(L == R)
	{
		if(arr[L] == 1)
		{
			int pw = len - 1 - L;
			t[idx] = binPow(2, pw);			
		}
		return;
	}
	build(le, L, mid);
	build(ri, mid + 1, R);
	t[idx] = ( t[le] + t[ri] ) % mod;
}


void propagate(int idx, int L, int R)
{
	int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	if(lz[idx] == 1)
	{
		t[idx] = sums[L] - sums[R + 1] + mod;
		t[idx] %= mod;
		if(L != R)
		{
			lz[le] = 1;
			lz[ri] = 1;
		}
	}
	lz[idx] = 0;
}

void update(int idx, int L, int R, int QL, int QR)
{
	int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	propagate(idx, L, R);
	if(L >= QL && R <= QR)
	{
		t[idx] = sums[L] - sums[R + 1] + mod;
		t[idx] %= mod;
		if(L != R)
		{			
			lz[le] = 1;
			lz[ri] = 1;
		}
		return;
	}
	if(L > QR || R < QL)
		return;
	update(le, L, mid, QL, QR);
	update(ri, mid + 1, R, QL, QR);

	t[idx] = (t[le] + t[ri]) % mod;
}

ll retrieve(int idx, int L, int R, int QL, int QR)
{
	int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	propagate(idx, L, R);
	if(L >= QL && R <= QR)
	{
		return t[idx];
	}
	if(L > QR || R < QL)
		return 0;
	ll s1 = retrieve(le, L, mid, QL, QR);
	ll s2 = retrieve(ri, mid + 1, R, QL, QR);
	return (s1 + s2) % mod;
}

void solve()
{
	cin >> len >> Q;
	cin >> str;
	for(int i = 0; i < len; i++)
		arr[i] = (str[i] - '0');

	preProcess();
	build(0, 0, len - 1);
	
	// cout << retrieve(0, 0, len - 1, 0, len - 1) << endl;
	// for(int i = 0; i < len; i++)
	// 	cout << sums[i] << endl;
	// cout << "OK"; return;
	while(Q-- > 0)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		// cout << a << " " << b << endl;
		update(0, 0, len - 1, a, b);
		ll answ = retrieve(0, 0, len - 1, 0, len - 1);
		cout << answ << endl;
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
}

int main()
{
	IO();

	fastIO();

	solve();
}