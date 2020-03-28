/*
    Author: Luis Manuel Díaz Barón
    Problem: 2861 - Lazy Cat II
    Online Judge: COJ
    Idea: Sieve for prime numbers plus cummulative table, then Combinatorics using pascal Triangle
	~ analog of the problem: Given the set S={1....N}. How many ways can I pick K values of S such
	that there are no two consecutives. Solution C(N - K + 1, K)

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
int Q, i, j, K;
const int p_lim = 801;

// to store cumulative prime palindorme sum
bool primes[MAXN];
int cumul[MAXN];
// pascal triangle
int pascal[p_lim][p_lim];

void open_file()
{
    freopen("d:\\lmo.in", "r", stdin);
}

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
            for(int j = i*i; j < MAXN; j+= i+i )
                primes[j] = true;
}

void generate_pascal()
{
    pascal[0][0] = 0;

    for(int i = 1; i < p_lim; i++)
    {
        pascal[i][0] = 1; pascal[i][i] = 1;
        for(int j = 1; j < i; j++)
        {
            pascal[i][j] = (pascal[i - 1][j] + pascal[i - 1][j - 1]) % MOD;
        }
    }
}



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

    // generate Pascal Triangle
    generate_pascal();

    sf("%d",&Q);
    while(Q--)
    {
        sf("%d%d%d",&i,&j, &K);

        // pf("%d\n",cumul[j] - cumul[i - 1]);

        int N = cumul[j] - cumul[i - 1]; // palindrome prime numbers found
        if(N - K + 1 <= 0)
            pf("0\n");
        else pf("%d\n",pascal[N - K + 1][K]);
    }
}

int main()
{
    // open_file();

    solve();
}
