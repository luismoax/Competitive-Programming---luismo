/*
    Author: Luis Manuel Díaz Barón
    Problem: 2842 - Lazy Cat
    Online Judge: COJ
    Idea: Sieve for prime numbers plus cummulative table

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
#define MAXN 10000001
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

bool primes[MAXN];
int cumul[MAXN];

bool palindrome(int n)
{
    int k = log10(n) + 1;
    char str[k];
    int idx = 0;
    while(n > 0)
    {
        str[idx++] = n%10;
        n/=10;
    }

    for(int i =0; i < k / 2; i++)
        if(str[i] != str[k - 1 - i])
            return false;

    return true;
}

void sieve()
{
    primes[0] = true;
    primes[1] = true;

    // deleting even numbers greater than 2
    for(int i = 4; i < MAXN; i+=2)
        primes[i] = true;

    for(int i = 3; i * i < MAXN; i++)
        if(!primes[i])
            for(int j = i*i; j < MAXN; j+= i )
                primes[j] = true;
}

int N, i, j;

void solve()
{
    sieve(); // precumpute

    // cumulative table
    cumul[2] = 1;
    // updating the cumulative table
    for(int i = 3; i < MAXN; i++)
        if(!primes[i] && palindrome(i))
            cumul[i] = cumul[i - 1] + 1;
        else cumul[i] = cumul[i - 1];

    sf("%d",&N);
    while(N--)
    {
        sf("%d%d",&i,&j);
        pf("%d\n",cumul[j] - cumul[i - 1]);
    }
}

int main()
{    
    solve();
}
