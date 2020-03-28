/*
    Author: Luis Manuel Díaz Barón
    Problem: 2711 - Shinigami Sword
    Online Judge: COJ
    Idea: 

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
#define MOD 1000009
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define nint(i) sf("%d",&i);


using namespace std;

struct shini
{
    int pw, id;
    shini(){}
};

bool _comp(shini f, shini s)
{
    return f.pw > s.pw;
}

int N, P;
shini arr[1001];

int main()
{    
    sf("%d",&N);

    for(int i = 0 ; i < N ; i++)
    {
        int k=0;
        sf("%d",&k);
        arr[i].id = i+1;
        arr[i].pw = k;
    }

    sort(arr, arr+N, _comp);

    for(int i = 0 ; i < N ; i++)
    {
        pf("%d\n", arr[i].id);
    }
	
    return 0;
}
