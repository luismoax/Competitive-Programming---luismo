/*
    Author: Luis Manuel Díaz Barón
    Problem: 2749 - Find the Password
    Online Judge: COJ
    Idea: Manacher algorithm, and scan over its array

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
#define MAXN 10001
#define MOD 1000000007
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define nint(i) sf("%d",&i);
#define nlong(i) sf("%lld",&i);

#define M 10001
#define INVCICLE(i,a,b,c) for(int i = (a); i >= (b); i -= (c))
#define CICLE(i,a,b,c) for(int i=(a); i<=(b); i += (c))

using namespace std;

int N,K;

// MANACHER
char str[MAXN]; // string
char MAN[2*MAXN + 2];
int P[2*MAXN + 2];
int man_len;


inline void manacher(char str[])
{
    int len = strlen(str); // length of the string

    // transform input to MAN
    man_len = 2*len + 2;

    MAN[0] = '$'; MAN[man_len - 1] = '#';

    for(int i =0; i < len; i++)
    {
        MAN[2*i + 1] = '#';
        MAN[2*i+ 2] = str[i];
    }
	// end transform input to MAN
	
    // index of the palindrome
	// with right most extension
    int id = 1;
	// extension
	int mx = P[id]+ id;

    for(int i = id; i < man_len; i++)
    {
		// if i contained into the right most palindrome wing
		// update P[i] with mirrored value
        if(i < mx)
        {
            int f = mx - i;
            int s = P[2*id - i];
            (f < s)? P[i] = f: P[i] = s;
        }
        else P[i] = 1;

        // expanding palindrome
        while(i + P[i] < man_len && MAN[i + P[i]] == MAN[i - P[i] ])
            P[i]++;
        // updating right most centered palindrome
        if(i + P[i] > mx)
        {
            mx = i + P[i];
            id = i;
        }
    }

}
// END MANACHER

inline int pal_greater()
{
    int cnt = 0;
    for(int i = 2; i < man_len; i++)
    {
        int len = P[i] - 1; // length of the palindrome centered at i
        if(len >= K)
            cnt+= 1 + (len - K)/2;
    }
    return cnt;
}

int main()
{
    sf("%d%d",&N,&K);
	
	// lowest and greatest values
    int LW = 1000000000, GR = 0;
	
    while(N--)
    {

        sf("%s",&str); // read string

        manacher(str); // apply manacher

        int tmp = pal_greater(); // counter

        if(tmp < LW) LW = tmp;
        if(tmp > GR) GR = tmp;
    }

    pf("%d %d\n",LW,GR);
}
