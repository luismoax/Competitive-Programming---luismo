#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

        int IsPrime(int n)
        {
            if (n < 2) return 0;
            if (n == 2) return 1;
            if (n % 2 == 0 ) return 0;


            for (int i = 3; i*i<=n; i+=2)
            {
                if (n % i == 0) return 0;
            }
            return 1;
        }


int main()
{
    int a = 0;
    scanf("%d",&a);
    while(a!=0)
    {
        int flag = 0;
        for (int i = 3; i <=a/2; i+=2)
         {
            if (IsPrime(i)==1 && IsPrime(a - i)==1)
            {
                printf("%d = %d + %d\n",a,i,a-i);
                flag = 1;
                break;
            }
         }
         if(flag==0)
            cout<<"Goldbach's conjecture is wrong."<<endl;
         scanf("%d",&a);
    }
}
