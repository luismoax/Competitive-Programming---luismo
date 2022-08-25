/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Counting Lucky Numbers
	Link: https://www.spoj.com/problems/CNT_LUCK/
	Online Judge: SPOJ
	Idea: Bits + Combinatorics.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define i64 unsigned long long int
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
const int mod = 1e9 + 3;
const int lim = 65;

int tc;

i64 pascal[lim][lim];

void preProcess()
{
	pascal[0][0] = 1;
	for(int i = 1; i < lim; i++)
	{
		pascal[i][0] = pascal[i][i] = 1;
		for(int j = 1; j < i; j++)
			pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
	}
}

i64 Combinations(int n, int k)
{
	return pascal[n][k];
}

vector<int> toBin(i64 x)
{
	vector<int> ret;
	while(x > 0)
	{
		ret.push_back(x % 2);
		x /= 2;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

i64 F(i64 x)
{
	vector<int> binary = toBin(x);

	int active = 0;
	for(int i = 0; i < binary.size(); i++)
		active += binary[i];

	i64 ret = 0;
	if(active == 4 || active == 7 || active == 44 || active == 47)
		ret++;
	
	int used = 0;

	for(int i = 0; i < binary.size(); i++)
	{
        // if this bit is active
		if(binary[i])
		{
			int posLeft = binary.size() - 1 - i;
			ret += pascal[posLeft][4 - used];
			ret += pascal[posLeft][7 - used];
			ret += pascal[posLeft][44 - used];
			ret += pascal[posLeft][47 - used];
			used++;
		}
	}
	return ret;
}

void solve()
{
	preProcess();

	cin >> tc;
	while(tc-- > 0)
	{
		i64 a, b;
		cin >> a >> b;

		i64 ri = F(b);
		i64 le = (a == 0) ? 0 : F(a - 1);

		cout << ri - le << endl;		
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