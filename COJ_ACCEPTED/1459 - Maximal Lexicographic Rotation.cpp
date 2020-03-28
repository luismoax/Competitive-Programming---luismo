/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 1459 - Maximal Lexicographic Rotation
    Online Judge: COJ
    Idea: Basic use of a Suffix Array
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

const int lim = 1e6 + 1;

struct entry
{
    int first, second, position;
};

// comparer
bool cmp(entry a, entry b)
{
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int sa[lim]; // suffix array
entry arr[lim]; // array of entries

string str;

void build_sa(string str)
{
    int len = str.length(); // lenght of the string
    // setting prefixes of lenght 2^0 = 1
    for(int i = 0; i < len; i++)
        sa[i] = str[i] - 'a';

    for(int pw = 1; (1 << (pw-1)) <= len; pw++ ) // logN
    {
        // for each position build prefix of lenght 2^pw
        for(int i = 0; i < len; i++) // N
        {
            int fir = sa[i];
            int sec = -1;
            if(i + (1 << (pw - 1)) < len)
                sec = sa[i + (1 << (pw - 1))];
			// building current entry
            entry p;
            p.first = fir;
            p.second = sec;
            p.position = i;

            arr[i] = p;
        }

        // sort prefixes
        sort(arr, arr + len, cmp); // NlogN

        // setting values into the sa
        for(int i = 0; i < len; i++) // N
        {
			// two entries with the same rank must be labaeled equally
            if(i > 0 && arr[i].first == arr[i - 1].first && arr[i].second == arr[i -1].second)
				sa[arr[i].position] = sa[ arr[i - 1].position];            
            else sa[arr[i].position] = i;
        }
    }
}

int solve()
{
    cin >> str;

    str = str + str; // concatenation 

    build_sa(str);

	int idx_best= 0, best = sa[0];
	for(int i = 0; i < str.length(); i++)
		if(sa[i] > best)
		{
			best = sa[i]; idx_best = i;
		}

	printf("%d\n", idx_best);
}

void open_file()
{
    // freopen("//media//luismo//Trabajo//lmo.in","r",stdin);
	freopen("d:\\lmo.in","r",stdin);
}

int main()
{
    // open_file();

    solve();
}
