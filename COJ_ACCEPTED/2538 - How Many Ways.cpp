/*
--------------------------------------
Author: Luis Manuel Díaz Barón
Problem: 2538 - How Many Ways
Online Judge: COJ
Idea: Dynamic. Read all numbers keeping track of the amount of sets that can be
made which sum leave remainder 0, 1, 2.  
--------------------------------------
*/


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

#define MAXN 100001
#define MOD 1000000000
// io
#define sf scanf
#define pf printf


using namespace std;

int N;

int main()
{
    sf("%d",&N);
    // number of possible set with sum modulus 0, 1, 2
    int one=0,two=0,zero=0;
    int k; //
    for(int i = 1;i <= N; i++)
    {
        sf("%d",&k); // read current value

        int mod = k % 3; // 
	// foreach possible remainder
	// calculate how many new possible sets can be formed foreach
	// possible remainder
        if(mod == 0)
        {
            zero = (2 * zero) + 1;
            one  = 2 * one;
            two = 2 * two;
        }
        else if(mod == 1)
        {
            int aux = one;

            one  = (one + zero + 1) % MOD;

            zero = (zero + two) % MOD;

            two = (two + aux) % MOD;

        }
        else
        {
            int aux = two;

            two = (two + zero + 1) % MOD;

            zero = (zero + one) % MOD;

            one = (one + aux) % MOD;
        }
        one%=MOD;
        two%=MOD;
        zero%=MOD;
    }

    pf("%d\n",zero);

    return 0;
}
