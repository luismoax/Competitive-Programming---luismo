/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3268 - Anders And The Candies
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

const int lim = 1e7 + 7;

int freq[100];

string str;

struct flavor
{
	char f;
	int cnt;
	flavor(char ff, int cc){f= ff; cnt = cc;}
	flavor(){}

	bool operator < (flavor other) const
	{
		if(other.cnt == cnt)
			return f > other.f;
		return cnt > other.cnt;
	}

} arrFlavors[3];

void solve()
{
	// read the string
	cin >> str;
	// length of the string
	int len = str.length();

	// put the frequency of the first value
	freq[str[0]]++;

	char f = str[0]; // current flavor
	int current = 1; // amount of consecutive values of current flavor

	// linear scan
	for(int i = 1; i < len; i++)
	{
		char aux = str[i]; // read the i-th flavor

		// if equals the one before, increase the number of it in a row
		if(aux == f)
			current++;
		// else reset
		else
		{
			f = aux;
			current = 1;
		}

		// updating current flavor best
		if(current > freq[f])
			freq[f] = current;
	}

	// create the values
	arrFlavors[0] = flavor('F', freq['F']);
	arrFlavors[1] = flavor('R', freq['R']);
	arrFlavors[2] = flavor('M', freq['M']);

/*
	for(int i = 0; i < 3 ;i++)
		cout << arr[i].f << " " << arr[i].cnt << endl;
*/

	// sort the 3 values hahahah
	sort(arrFlavors, arrFlavors + 3);

	// printing the amount
	cout << arrFlavors[0].cnt << " ";

	// printing the falvor
	if(arrFlavors[0].f == 'R') cout << "Rat";
	if(arrFlavors[0].f == 'M') cout << "Milk";
	if(arrFlavors[0].f == 'F') cout << "Fish";
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("e:\\lmo.in","r",stdin);
	// freopen("e:\\lmo.out","w",stdout);
}

int main()
{
    // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
