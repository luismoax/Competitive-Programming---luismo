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
        Problem: 2458 - Numerüzka Trianglezlaya Sequence
        Algorithm: Easy one. Roots of a 2-grade polynomial
    */

    using namespace std;


    int main()
    {
        double n=0;
        while (sf("%lf",&n),n!=0)
        {
        
            double root = sqrt(1+(8*n));
            
            double x = trunc ((-1 + root)/2);

            if(fmod(root,1.0)!=0)
                x++;

            pf("%.lf\n",x);
        }
    }