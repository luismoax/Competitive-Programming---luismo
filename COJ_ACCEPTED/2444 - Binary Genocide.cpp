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
    Problem: 2444 - Binary Genocide
    Algorithm: Implementation
*/

using namespace std;


int number_of_ones(int n)
{
    int cnt = 0;
    while(n>0)
    {
        cnt+=(n%2);
        n/=2;
    }
    return cnt;
}

int main()
{
    int n,cnt=0;
    while(sf("%d",&n) !=EOF)
        if(number_of_ones(n)%2==0)
            cnt++;

    pf("%d\n",cnt);

}