#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>

#define pf printf
#define sf scanf


#define INF 1000000
#define LEN 50000

    /*
        Author: Luismo
        Problem: 1525 - Symmetry
        Algorithm: Easy recursive solution. But is the same of adding powers of 4, which is faster than this, also accepted.
    */

using namespace std;


long long Recursion(long long n,long long m)
{
    if(n%2==0 || m%2==0)
        return 0;
    if(n==1 && m==1)
        return 1;

    return 1 + 4*Recursion(n/2,m/2);
}

int main()
{

    //freopen("d:\\lmo.in","r",stdin);

    long long n,m;
    sf("%lld%lld",&n,&m);

    pf("%lld\n",Recursion(n,m));

}
