#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>


#define pf printf
#define sf scanf

#define PI 3.1415926

/*
    Author: Luismo
    Problem: 1301 Herman
    Solution: Taxicab Geometry, a bit rought for rounding
*/

using namespace std;

int main(void)
{
    double r=0;
    sf("%lf",&r);
    double eucl_a = acos(-1)*r*r;
    double herm_a = 2*r*r;

    eucl_a *= 10000;
    eucl_a = trunc(eucl_a);

    pf("%.4lf\n%.4lf",eucl_a/10000,herm_a);

    return 0;
}
