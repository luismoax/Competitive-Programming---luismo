#include <iostream>
#include <cstdio>

using namespace std;

// Author: Luismo

bool IsPrime(int n)
{
    if(n<2)
        return false;
    if(n==2 || n==3)
        return true;
    if(n%2==0 || n%3==0)
        return false;

    for(int i=5;i*i<=n;i++)
        if(n%i==0)
            return false;

    return true;
}

int main()
{
    int M,n;
    scanf("%d",&M);
    for(int c=0;c<M;c++)
    {
        scanf("%d",&n);

        if(IsPrime(n))
            printf("%d %d\n",n,n);
        else
        {
            int left=-1,right = -1;
            int cursor =n;
            if(cursor%2==0)
                cursor--;
            for(;!IsPrime(cursor);cursor--){}
            left = cursor;

            cursor =n;
            if(cursor%2==0)
                cursor++;
            for(;!IsPrime(cursor);cursor++){}
            right = cursor;
            printf("%d %d\n",left,right);
        }

    }


}
