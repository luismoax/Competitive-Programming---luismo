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
        Problem: 2140 - Free Tickets
		Online Judge: COJ
        Algorithm: Easy generate the whole sequence (until 8000) and query O(1)
    */

using namespace std;


bool is_vowel(char c)
{
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

// Global Variables
vector<int> vec;

int main()
{
    //freopen("d:\\lmo.in","r",stdin);

    vec.push_back(5);
    int pw = 2;

    while(vec.size() < 8000)
    {

        int val = pow(5,pw);
        vec.push_back(val);
        int len = vec.size() - 1;
        for(int i = 0; i < len; i++)
            vec.push_back(val + vec[i]);

        pw++;
    }

    int tc;
    sf("%d",&tc);

    while(tc-->0)
    {
        int n;
        sf("%d",&n);
        pf("%d\n",vec[n-1]);
    }



    return 0;
}
