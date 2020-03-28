/*
    Author: Luis Manuel Díaz Barón
    Problem: 2857 - GCD Again
    Online Judge: COJ
    Idea: Find foreach number all its divisor and mark the frequency of each one on an array
	return the greatest with frequency greater than 1

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
#define MOD 10000007
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define nint(i) sf("%d",&i);
#define nlong(i) sf("%lld",&i);

using namespace std;
void open_file()
{
    freopen("d:\\lmo.in", "r", stdin);

}

int marks[1000001], n;
void solve()
{
    int greatest_gcd = 1;
    // reading integers
    while(sf("%d",&n) != EOF)
    {
        // find all its divisors
        for(int i = 1; i * i <= n; i++)
        {
            if(n%i==0)
            {
                marks[i]++;
                if(i*i != n)
                    marks[n/i]++;
                if(marks[i] > 1)
                    greatest_gcd = max(greatest_gcd, i);
                if(marks[n/i] > 1)
                    greatest_gcd = max(greatest_gcd, n/i);
            }
        }
    }
    pf("%d\n",greatest_gcd);
}

int main()
{
    // open_file();

    solve();
}