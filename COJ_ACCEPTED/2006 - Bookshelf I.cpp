/*
    Author: Luis Manuel Díaz Barón
    Problem: 2006 - Bookshelf I
    Online Judge: COJ
    Idea: Dynamic Programming ~ Palindrome Descomposition
	Use a array mantaining the best height that can be found with the first i books, then when adding a new book
	scan backward what is the best height that can be achieved using the last K books added to the last one 
	(with total width less than L) and the best height for the first N - K books already calculated
	O(N^2)
	

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
#define MAXN 2003
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


int N,L, wi, hi;

ll best_of_all = 0;

ll total_w[MAXN]; // cumulative of width
ll best_h[MAXN]; // best heigth for the first i books
ll heights[MAXN];

int main()
{
	// freopen("d:\\lmo.in", "r", stdin);
	// freopen("d:\\lmo.out", "w", stdout);

    sf("%d%d",&N,&L);

    for(int i = 1; i <= N; i++)
    {
        sf("%d%d",&hi, &wi); // reading height and width

        heights[i] = hi; // current height

        total_w[i] = total_w[i-1] + wi; // updating the total width

        ll mx = hi; // maximun height found when running backwards
        for(int j = i - 1; j >=0 && total_w[i] - total_w[j] <= L; j--)
        {
            int current = mx + best_h[j]; //
			
			// updating the best height
            if(best_h[i] <= 0 || best_h[i] > current)
                best_h[i] = current;
			// updating next best height
            mx = max(mx, heights[j]);
        }
    }
	// answer
    pf("%d\n",best_h[N]);
}
