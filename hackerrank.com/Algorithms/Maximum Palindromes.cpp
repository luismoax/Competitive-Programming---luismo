/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Maximum Palindromes
	Link: 
	Online Judge: hackerrank.com
	Idea: For each letter keep a cumulative table of it's frequencies
    For each query find the number of letters that can be used in the left half of the palindorme (the right one will be
    the mirror), that number is half the frequency of that letter in the interval. Apply the formula of permutations with
    repetitions in order to obtain the number of different left halves (and thus palindromes) that can be constructed.
    Multiply it by the number of frequencies that were odd (a letter can be put in the middle of the constructed palindrome)
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

string s;
int q;
int l, r;
ll fact[lim];
ll invFact[lim];

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


void preProcess()
{
	fact[0] = 1;
	invFact[0] = 1;
	for(ll i = 1; i < lim; i++)
	{
		fact[i] = (i * fact[i-1]) % mod;
		invFact[i] = binPow(fact[i], mod - 2);
	}
}

ll cumul[30][lim];

void solve()
{
	cin >> s >> q;

	preProcess();

	for(int i = 0; i < s.size(); i++)
	{
		int idx = s[i] - 'a';
		cumul[idx][i+1]++;
	}

	for(int i = 0; i < 26; i++)
	{
		for(int j = 1; j <= s.size(); j++)
			cumul[i][j] += cumul[i][j-1];
	}

	while(q-- > 0)
	{
		cin >> l >> r;

		ll answ = 1;
		ll sm = 0;
		ll odd = 0; // odd frequencies

		for(int i = 0; i < 26; i++)
		{
			ll cc = cumul[i][r] - cumul[i][l-1];

			// if the lenght is odd half of them will be used in the word a the remainder as a middle point
			if(cc % 2 == 1)
				odd++;

			sm += cc / 2;
			// multiply by inverse factorials of frequencies first (denominator)
			answ = (answ * invFact[cc / 2]) % mod;
		}
		// multiply by factorial of all letters (numerator)
		answ = (answ * fact[sm]) % mod;

		if(odd != 0)
			answ = (answ * odd) % mod;

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

	if(fopen("c:\\Competitive Programming\\lmo.in","r") != NULL)
	{
		freopen("c:\\Competitive Programming\\lmo.in","r",stdin);
		freopen("c:\\Competitive Programming\\lmo.out","w",stdout);
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