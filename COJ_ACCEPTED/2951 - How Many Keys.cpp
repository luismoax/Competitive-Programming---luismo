/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 2951 - How Many Keys
    Online Judge: COJ
    Idea:
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

// method used to read faster in C++
inline int read_int () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

int N;

char str [40];

string to_string(char s[])
{
	string ret = "";
	int len = strlen(s);
	for(int i= 0; i < len; i++)
		ret+= s[i];
	return ret;
}

void solve()
{

	set<string> rbtree;


	sf("%d", &N);

	while(N--)
	{
		sf("%s", &str);

		sort(str, str + strlen(str));

		string s = to_string(str);

		rbtree.insert(s);
	}

	pf("%d\n", rbtree.size());
}

void open_file()
{
    freopen("//media//Trabajo//lmo.in","r",stdin);
	// freopen("d:\\lmo.in","r",stdin);
}

int main()
{
    // open_file();

    solve();
}
