#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int mod = 10000;
    int N,U,Q;
    scanf("%d%d%d",&N,&U,&Q);
    int cells[N];

    for(int c=0;c<=N;c++)
        cells[c] = 0;

    // Reading Updates
    for(int c=0;c<U;c++)
    {
        int i,k;
        scanf("%d%d",&i,&k);
        //printf("%d %d\n",i,k);

        if(i>1)
            cells[i-1]+= (k%mod);
        if(i< N)
            cells[i+1]+= (k%mod);

        cells[i] += (k+1)%mod;
    }

    int sums[N];

    for(int c=0;c<=N;c++)
        sums[c] = 0;
    for(int c=1;c<=N;c++)
        sums[c] = (sums[c-1]+cells[c])%mod;

    // Reading queries
    for(int c=0;c<Q;c++)
    {
        int i,k;
        scanf("%d%d",&i,&k);
        printf("%d\n",(sums[k]-sums[i-1]+mod)%mod  );
    }

}
