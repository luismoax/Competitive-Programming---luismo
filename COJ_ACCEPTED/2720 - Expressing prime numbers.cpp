/*
    Author: Luis Manuel Díaz Barón
    Problem: 2720 - Expressing prime numbers
    Online Judge: COJ
    Idea: Eratostenes Sieve

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
#define MAXN 10000001
#define MOD 1000000007
// Types
#define ll long long
#define ull unsigned long long

// IO
#define sf scanf
#define pf printf
#define nint(i) sf("%d",&i);


using namespace std;

bool prime(int n)
{
    if(n < 2) return false;

    if(n ==2 || n==3)
        return true;

    for(int i = 2; i*i <= n; i++)
        if(n%i ==0) return false;

    return true;

}


int N, K;

bool sieve[MAXN];

int main()
{
    // freopen("d:\\lmo.in", "r", stdin);
	// freopen("d:\\lmo.out", "w", stdout);

    sf("%d%d",&N,&K);

    int cnt = 0;

    sieve[0] = true;
    sieve[1] = true;

    int last_prime = 2; // last prime

    for(int i = 2; i <= N; i++)
    {
        if(!sieve[i])
        {
            for(int j = i + i; j <=N; j+=i)
                sieve[j] = true;

            if(i > 2)
            {
				// if can be formed
                if(last_prime + i + 1 <=N &&  prime( last_prime + i + 1 ))                
                    cnt++;                    
                
				// updating prime before
                last_prime = i;
            }
        }
    }

    if(cnt >= K) pf("YES");
    else pf("NO");

    return 0;
}

