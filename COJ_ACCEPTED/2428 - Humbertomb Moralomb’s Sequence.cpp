    #include <iostream>
    #include <cstdio>
    #include <vector>
    #include <cstring>
    #include <map>
    #include <algorithm>
    #include <cmath>

    #define pf printf
    #define sf scanf

    #define INFINITY 10000

    /*
        Author: Luismo
        Problem: 2428 - Humbertomb Moralomb’s Sequence
        Algorithm:
    */

    using namespace std;


    int main()
    {
        

        long long n;
        while(true)
        {
            sf("%lld",&n);
            if(n==0)
                break;
            double root = trunc( sqrt(n));
            if(root*root == n)
                pf("%.lf\n",root);
            else pf("%.lf\n",floor(root+1));
        }
    }

