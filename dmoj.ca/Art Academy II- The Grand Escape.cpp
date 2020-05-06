/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Art Academy II: The Grand Escape
	Link: https://dmoj.ca/problem/art2
	Online Judge: dmoj.ca
	Idea: Basic use of Modular Inverse
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
#define M_PI 3.14159265358979323846

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e16 + 3;
const ll mod = (1LL << 32);
const int lim = 3e5 + 3;

ll N, M;
ll hhi;

// >>

ll phi = (1LL << 31);

ll binPow(ll bs, ll exp)
{
	if(exp == 0)
		return 1;
	ll aux = binPow(bs, exp / 2);
	aux = (aux * aux) % mod;
	if(exp % 2 == 1)
		aux = (aux * bs) % mod;
	return aux;
}
// modular inverse
ll invMod = binPow(2654435761, phi - 1);

// <<

void solve()
{
	cin >> N >> M;
	vector<ll> vect;
	while(N-- > 0)
	{
		cin >> hhi;

		ll k = (hhi * invMod) % mod;
		
		vect.push_back(k);
	}
	sort(vect.begin(), vect.end());

	ll answ = 0;
	for(int i = vect.size() - 1; M > 0 && i >= 0; i--, M--)
	{
		answ += vect[i];
	}
	cout << answ << endl;
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