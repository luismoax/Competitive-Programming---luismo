/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3232 - Penalty Calculation
    Online Judge: COJ
    Idea: Easy Ad-Hoc
*/
#include <ctime>
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

struct submission
{
	int minute;
	string verdict;
} sub[101];

bool cmp(submission f, submission s)
{
	return f.minute < s.minute;
}

string data[] = {"WA", "CE", "RTE", "AC", "TLE"};

bool takenNumbers[301];

void generate()
{
	freopen("e:\\lmo.in","w",stdout);
	memset(takenNumbers, false, sizeof takenNumbers); // reset

	int NN = 20;
	// generate
	cout << 100 << endl;
	for(int i = 0; i < 100; i++)
	{
		bool flag = true;
		while(flag)
		{
			int x = rand() % 300 + 1;
			int idx = rand() % 5;
			if(!takenNumbers[x])
			{
				takenNumbers[x] = true;
				cout << x << " " << data[idx] << "\n";
				flag = false;
			}
		}
	}
	//fclose(stdout);
}

void S()
{
	//freopen("e:\\lmo.in", "r", stdin);
	// solve problem
	int n;
	cin >> n;
	// reading submissions
	for(int i = 0; i < n; i++)
	{
		cin >> sub[i].minute >> sub[i].verdict;
	}
	// sort them all
	sort(sub, sub + n, cmp);
	int penalty = 0;
	int idx = 0;
	while(idx < n && sub[idx].verdict != "AC")
		idx++;

	if(idx < n)
		penalty = sub[idx].minute + idx * 20;
	cout << penalty;
}

void solve()
{
	//srand(time(0));

	// generate();
	S();	
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	// freopen("e:\\lmo.in","r",stdin);
}

int main()
{
    // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
