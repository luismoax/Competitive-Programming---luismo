/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: Record Keeping
    Online Judge: COJ
    Idea: Ad-Hoc
*/
#include <iostream>
#include <cstdio>
// Containers
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
// Algorithm
#include <algorithm>
#include <cstring>
#include <cmath>
// Constants
#define MAXN 1000001
#define MOD 1000000007
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define nint(i) sf("%d",&i);
#define nlong(i) sf("%lld",&i);

using namespace std;

const int lim = 1e5 + 5;


int N;

vector<string> vect;
string str;

map<string, int> MAP;

int cnt = 0;

void solve()
{
	cin >> N;

	for(int i = 0; i < N; i++)
	{
		vect.clear();
		for(int m = 0; m < 3; m++)
		{
			cin >> str; vect.push_back(str);
		}

		sort(vect.begin(), vect.end());
		str = "";

		for(int i = 0; i < vect.size(); i++)
			str+= vect[i];

		MAP[str]++;

		cnt  = max(cnt, MAP[str]);
	}
	cout << cnt;
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("e:\\lmo.in","r",stdin);
	// freopen("e:\\lmo.out","w",stdout);
}

int main()
{
    open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
