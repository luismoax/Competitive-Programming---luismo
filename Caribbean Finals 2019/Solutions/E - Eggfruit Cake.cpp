/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: E - Eggfruit Cake
	Online Judge:
	Idea: Ad-Hoc. For each possible slice see how many can be added to the "right"
	if picked consecutive
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
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
const int mod = 1000000009;
const int lim = 2e5 + 2;

string str;
ll S;

int ne[lim];

void solve()
{
	cin >> str >> S;
	// concatenate the string to itself to "simulate" circular behaviour
	string kstr = str + str;
    
	int lst = -1;
	ll cntE = 0;
	for(int i = kstr.size(); i >= 0; i--)
	{
		if(kstr[i] == 'E')
		{
			cntE++;
			lst = i;
			ne[i] = -1;
		}
		else
		{
			ne[i] = lst;			
		}		
	}

	cntE /= 2; // actual number of Es
	// for each E I could pick S slices to the left
	ll answ = cntE * S;
	
	for(int i = str.size() - 1; i >= 0; i--)
	{
		// if found a P
		if(str[i] == 'P' && ne[i] != -1)
		{
			ll k = ne[i] - i;
			answ += max(0ll, S - k);
		}
	}
    // print the answer
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
	else if(fopen("/media/Beijing/lmo.in","r") != NULL)
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
