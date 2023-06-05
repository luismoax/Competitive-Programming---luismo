/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: LISA
	Link: https://www.spoj.com/problems/LISA/
	Online Judge: SPOJ
	Idea: Classic Matrix Chain Multiplication
*/
#include<bits/stdc++.h>
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
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e9;
const int mod = 1e9 + 7;
const int lim = 2e2 + 3;

int tc;
string str;

i64 dpMax[lim][lim];
i64 dpMin[lim][lim];
bool markMax[lim][lim];
bool markMin[lim][lim];

void reset()
{
	memset(dpMax, 0, sizeof dpMax);
	memset(dpMin, 0, sizeof dpMin);
	memset(markMax, 0, sizeof markMax);
	memset(markMin, 0, sizeof markMin);
}

i64 DynamicProgrammingMax(int le, int ri)
{
	if(le == ri)
		return (str[le] - '0');

	if(markMax[le][ri])
		return dpMax[le][ri];

	markMax[le][ri] = 1;

	for(int i = le + 1; i < ri; i+= 2)
	{
		i64 s1 = DynamicProgrammingMax(le, i - 1);
		i64 s2 = DynamicProgrammingMax(i + 1, ri);

		i64 aux = s1 + s2;

		if(str[i] == '*')
			aux = s1 * s2;

		dpMax[le][ri] = max(dpMax[le][ri], aux);
	}
	return dpMax[le][ri];
}


i64 DynamicProgrammingMin(int le, int ri)
{
	if(le == ri)
		return (str[le] - '0');

	if(markMin[le][ri])
		return dpMin[le][ri];

	dpMin[le][ri] = 100000000000000000;
	markMin[le][ri] = 1;

	for(int i = le + 1; i < ri; i+= 2)
	{
		i64 s1 = DynamicProgrammingMin(le, i - 1);
		i64 s2 = DynamicProgrammingMin(i + 1, ri);

		i64 aux = s1 + s2;

		if(str[i] == '*')
			aux = s1 * s2;

		dpMin[le][ri] = min(dpMin[le][ri], aux);
	}
	return dpMin[le][ri];
}


void solve()
{
	cin >> tc;
	while(tc--> 0)
	{
		reset();

		cin >> str;		

		i64 mxDp = DynamicProgrammingMax(0, str.size() - 1);
		i64 mnDp = DynamicProgrammingMin(0, str.size() - 1);

		cout << mxDp << " " << mnDp << endl;
	}
}
 
void fastIO()
{
	io;
}
 
void IO()
{
	const char * route = "c:\\Users\\LUISMO\\lmo.in";

	if(fopen(route, "r") != NULL)
	{
		freopen(route,"r",stdin);
	}
}
 
int main()
{
	IO();
 
	fastIO();
 
	solve();
}