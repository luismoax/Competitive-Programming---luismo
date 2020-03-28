/*
    Author: Luis Manuel Díaz Barón
    Problem: 2752 - Incredible Penguins
    Online Judge: COJ
    Idea: Easy, ad-hoc

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

struct _penguin
{
    char name[11];
    int ID;
    _penguin(){}

};

int N;
char name[11];
_penguin birds[MAXN];
bool _paired[MAXN];

int main()
{    
    sf("%d",&N);

    // reading penguins
    for(int i = 0 ; i < N; i++)
    {
        sf("%s %d",&birds[i].name, &birds[i].ID); // i-th penguin
    }

    pf("FOREVER ALONE ones:\n");

    // O(N^2)
    for(int i = 0; i < N; i++)
    {
        bool flag = true;
        // scan if there's another penguin to mathch the i-th one
        for(int j = 0; j < N; j++)
        {
            if(i!=j && birds[i].ID == -birds[j].ID){flag = false; break;}
        }

        if(flag)
            pf("%s\n", birds[i].name);
    }

    return 0;
}
