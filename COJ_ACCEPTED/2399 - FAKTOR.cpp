#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <cmath>

#define pf printf
#define sf scanf

#define INF 10000

/*
    Author: Luismo
    Problem: 2399 - FAKTOR
    Algorithm:
*/

using namespace std;



int main()
{
    //freopen("d:\\lmo.in","r",stdin);

    int a,i;
    scanf("%d%d",&a,&i);
    pf("%d\n", ( a*(i-1) )+1 );
}
