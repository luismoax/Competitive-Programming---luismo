/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: B. Kuroni and Simple Strings
	Online Judge: http://codeforces.com/contest/1305/problem/B
	Idea: Just pick brackets greedily from ends, 
            forming as large simple string as you can.
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
const int mod = 1e9 + 7;
const int lim = 2e5 + 2;

string str;
void solve()
{
	cin >> str;
	int len = str.size();
	int firstClosing = -1;
	int lastOpening = -1;

	queue<int> open;
	stack<int> clos;

	for(int i = 0; i < len; i++)
	{	
		if(str[i] == '(')
			open.push(i);
		else clos.push(i);				
	}

	vector<int> answ;
	while(open.size() > 0 && clos.size() > 0 && open.front() < clos.top())
	{
		int o = open.front(); open.pop();
		int c = clos.top(); clos.pop();
		answ.push_back(o);
		answ.push_back(c);
	}
	
	if(answ.size() == 0)
	{
		cout << 0; return;
	}

	cout << 1 << endl;
	cout << answ.size() << endl;
	sort(answ.begin(), answ.end());
	for(auto i: answ)
		cout << i+1 << " ";
}


void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
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
