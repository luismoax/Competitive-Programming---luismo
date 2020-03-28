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
#define MAXN 10001

    /*
        Author: Luismo
        Problem: 1464 - Vasha Plug&Plug
        Online Judge: COJ
        Algorithm: Brute Force
    */

using namespace std;


// Global Variables

int main()
{
    // freopen("d:\\lmo.in","r",stdin);

    int tc;
    sf("%d",&tc);
	// foreach test case
    for (int t = 0; t < tc; t++)
	{
        char s[MAXN];
        cin >> s;

		bool flag =true;
		// while still found pairs of consecutive equal values
		while (flag)
		{
            flag = false;
			char tmp[MAXN] = "";
			int idx = 0;

            int slength = strlen(s);
			
			// if found a pair of consecutive equal char, jump it
			for (int i = 0; slength >= 2 &&  i < slength; i++)
			{
                if(i < slength-1 && s[i] == s[i+1])
				{
                    i++;
                    flag = true;
                }
				else tmp[idx++]=s[i];
            }
			// if found no pair of consecutive equal chars, then tmp is the answer
			if(!flag)
                break;

            fill(s, s + MAXN, 0);
            // updating s
            for(int i =0 ; i < strlen(tmp) ; i ++)
                s[i] = tmp[i];
        }
		// answer
        cout<<s<<endl;
    }

    return 0;
}
