/*
    Author: Luis Manuel Díaz Barón
    Problem: 2747 - Dobri
    Online Judge: COJ
    Idea: Dynamic, ad-hoc. Keep an array P where P[K] = 1 if value K can be achieved with the sum of 2 of the first i
	elements. Then the ith value could be achieved if P[arr[i] - arr[j]] == 1 for 0<=j<=i.
	As we have negative values P will have a greater size and values in P will be set on a ratio (see variable zero
	on implementation)

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
#define MAXN 10002
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

int N;

int P[400001]; // 
int zero = 200000; // middle point
int arr[5001]; // array with values

int cnt = 0; // counter


int main()
{    
    // freopen("d:\\lmo.in", "r", stdin);

    scanf("%d",&N);

    for(int i = 0; i < N; i++)
    {
        // read the ith number
        sf("%d",&arr[i]);

        // if there a pair achieved before
        // with the sum equals arr[i] - arr[j]
        for(int j =0; j < i; j++)
        {
            if(P[zero + arr[i] - arr[j] ] == 1)
            {
                cnt++;
                break;
            }
        }

        // updating pairs sums that can be achieved
        for(int j = 0; j <= i; j++)
        {
            int k = arr[j] + arr[i];
            // setting the value (sum of pair arr[i] + arr[j]) as found
            P[zero + k] = 1;
        }
    }

    pf("%d\n",cnt);

    return 0;
}

