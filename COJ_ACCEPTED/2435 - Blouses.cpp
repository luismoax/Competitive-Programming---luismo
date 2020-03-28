#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <cmath>

#define pf printf
#define sf scanf


#define INF 1000000

/*
    Author: Luismo
    Problem: 2435 - Blouses
    Algorithm: Implementation
*/

using namespace std;

struct _interval
{
    int left,right, _color;
    _interval(){}
    _interval(int l,int r, int color)
    {
        left = l;
        right = r;
        _color = color;
    }
};

void print_arr(int arr[],int n)
{
    for(int i=0;i<n;i++)
        pf("%d",arr[i]);
    pf("\n");
}

void print_arr_bool(bool arr[],int n)
{
    for(int i=0;i<n;i++)
        pf("%d",arr[i]);
    pf("\n");
}

void print_vector(vector<int> vect)
{
    for(int i=0;i<vect.size();i++)
        if(i==0)
            pf("%d",vect[i]);
        else pf(" %d",vect[i]);
}

int main()
{
    //freopen("d:\\lmo.in","r",stdin);

    int c,q,k,tc=0;
    sf("%d%d%d",&c,&q,&k);
    while(c+q+k !=0)
    {

        // reading intervals
        char str[256];
        int cnt = 1; // amount of blouses
        int right;

        _interval arr[c];

        // reading colors
        for(int i =0;i<c;i++)
        {
            sf("%s",str);
            sf("%d",&right);
            // adding the new interval
            arr[i] = _interval(cnt,cnt+right-1,i);

            cnt+=right;
        }
        pf("Case #%d:\n",++tc);

        int q_len = max(7,k);
        // reading the queries
        for(int i=0;i < q; i++)
        {
            int _query[q_len]; // array for query

            // reading the used blouses
            for(int j=0;j< q_len;j++)
            {
                sf("%d",&_query[j]);
            }

            // array for used blouses
            bool used [cnt];
            // set all blouses aviables
            memset(used,false,sizeof used);



            // mark the last k blouses as used
            for(int j=0;j<k;j++)
                used[ _query[q_len-1- j] ] = true;

            // mark the blouse used 7 days ago
            int idx = _query[q_len-7];
            used[idx] = true;

            // find the interval of the last day's blouse
            idx = _query[q_len-1];
            // scanning intervals
            for(int j=0;j<c;j++)
            {
                _interval _current = arr[j];
                if(idx>=_current.left && idx<=_current.right)
                {
                    for(int k=_current.left;k<=_current.right;k++)
                        used[k] = true;
                    break;
                }
            }

            //print_arr_bool(used,cnt);
            vector<int> the_ones;
            for(int j=1;j<cnt;j++)
            {
                if(!used[j])
                    the_ones.push_back(j);
            }

            if(the_ones.empty())
                pf("Buy other blouse");
            else print_vector(the_ones);
            pf("\n");
        }

        pf("\n");
        // read again
        sf("%d%d%d",&c,&q,&k);
    }

}
