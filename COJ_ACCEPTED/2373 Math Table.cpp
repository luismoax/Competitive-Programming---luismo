#include <iostream>
#include <cstdio>

#define sf scanf
#define pf printf

using namespace std;

int main()
{
    float a,b,c,d;
    sf("%f%f%f%f",&a,&b,&c,&d);
    int turns = 0;
    float max = a/b + c/d;

    if(c/a+d/b > max)
    {
        max = c/a+d/b;
        turns= 1;
    }

    if(d/c+b/a > max)
    {
        max = d/c+b/a;
        turns= 2;
    }

    if(b/d+a/c > max)
    {
        max = b/d+a/c;
        turns= 3;
    }
    pf("%d",turns);

}
