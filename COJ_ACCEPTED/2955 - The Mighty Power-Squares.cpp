/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 2955 - The Mighty Power-Squares
    Online Judge:
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

int P(int x)
{
	if(x == 0)
		return 0;
	int pw = floor( log2( floor(sqrt(x)) ) ) ;
	return (1 << pw);
}

double log4(int x)
{
	return log(x) / log(4);
}

ll M(int i)
{
	ll cnt = 0;

	while(i > 0)
	{
		ll pi = P(i);
		ll qq = pow(4, floor( log4(i) ) );

		ll inc = pi * (i - qq + 1);
		cnt+= inc;

		i = qq - 1;
	}
	return cnt;
}


ll tc, a, b;
void solve()
{
/*
	int arr[2000];
	memset(arr, 0, sizeof arr);

	for(int i = 1; i <= 200; i++)
	{
		arr[i] = arr[i-1] + P(i);
	}
*/
	// cout<< arr[200]<< " "<< arr[99] << endl;

	// cout<< arr[10]<< " "<< arr[0] << endl;

	// cout << arr[10] - arr[0] << endl <<arr[200] - arr[99] << endl << arr[99] << " " << arr[200] << endl;
	// cout << " "<< P(11) << endl;
/*
	for(int i = 0; i < 1500; i++)
	{
		cout << i << " P(i):" << P(i)<<endl;
	}
*/

// cout << "---------\n";


	sf("%d\n", &tc);

	while(tc--)
	{
		sf("%d%d", &a, &b);
		ll answ = M(b) - M(a - 1);
		cout << answ << "\n";
	}
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("d:\\lmo.in","r",stdin);
}

int main()
{
    // open_file();

    solve();
}
