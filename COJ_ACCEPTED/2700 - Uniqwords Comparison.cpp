/*
    Author: Luis Manuel Díaz Barón
    Problem: 2700 - Uniqwords Comparison
    Online Judge: COJ
    Idea: Easy 

*/
#include <iostream>
#include <cstdio>
// Containers
#include <vector>
#include <map>
#include <stack>
#include <queue>
// Algorithm
#include <algorithm>
#include <cstring>
#include <cmath>
// Constants
#define MAXN 1000003
#define MOD 1000003
// Types
#define ll long long
#define ull unsigned long long

// IO
#define sf scanf
#define pf printf
#define nint(i) sf("%d",&i);
#define nlong(i) sf("%lld",&i);

using namespace std;

int alph[27];

char word_fir[27];
char word_sec[27];

int main()
{
    // freopen("d:\\lmo.in", "r", stdin);
	// freopen("d:\\lmo.out", "w", stdout);

	sf("%s", word_fir);
	sf("%s", word_sec);

	int len_fir = strlen(word_fir);
	int len_sec = strlen(word_sec);

	for(int i =0; i < len_fir; i++)
        alph[word_fir[i] - 'A' ] = 1;

    for(int i =0; i < len_sec; i++)
        alph[word_sec[i] - 'A' ]+=2;

    pf("First:");
    for(int i =0; i < 26; i++)
        if(alph[i] == 1)
        {
            pf("%c", (char)('A'+ i));
        }

    pf("\n");

    pf("Second:");
    for(int i =0; i < 26; i++)
        if(alph[i] == 2)
        {
            pf("%c", (char)('A'+ i));
        }

    pf("\n");

    pf("First&Second:");
    for(int i =0; i < 26; i++)
        if(alph[i] == 3)
        {
            pf("%c", (char)('A'+ i));
        }

    return 0;

}
