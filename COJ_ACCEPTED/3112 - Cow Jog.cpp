/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3112 - Cow Jog
    Online Judge: COJ
    Idea: Easy, linear scan
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

struct cow
{
	int pos, speed;
	cow(){}
	cow(int p, int s){pos = p; speed = s;}
};

const int lim = 1e5 + 5;

cow herd[lim];

bool cmp(cow a, cow b)
{
	return a.pos < b.pos;
}

int N;

void solve()
{
	cin >> N;

	// reading cows
	for(int i = 0; i < N; i++)
		cin >> herd[i].pos >> herd[i].speed;

	sort(herd, herd + N, cmp);

	// linear scan
	int cnt = 1;

	for(int j = N - 1; j > 0; j--)
	{
		int idx= j - 1;
		for(int i = j - 1; i >= 0; i--)
		{
			idx = i;

			if(herd[i].speed <= herd[j].speed)
			{
				cnt++;
				break;
			}
		}

		j = idx + 1;
	}

	cout << cnt;
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("d:\\lmo.in","r",stdin);
}

int main()
{
    // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
