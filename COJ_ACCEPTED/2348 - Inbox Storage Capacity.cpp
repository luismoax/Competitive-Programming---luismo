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
        Problem: 2348 - Inbox Storage Capacity
        Online Judge: COJ
		Algorithm:
    */

using namespace std;


struct _mail
{
    long long A,B,weight;
    _mail(){}
    _mail(long long _a,long long _b,long long w)
    {
        A = _a;
        B = _b;
        weight = w;
    }


    bool operator < ( const _mail &other)const
    {
        if(B == other.B)
            return A > other.A;
        return B > other.B;
    }

    void prtn()
    {
        pf("%lld %lld -> %lld\n",A,B,weight);
    }
};

bool mail_comparer(_mail m1, _mail m2)
{
    if(m1.A == m2.A)
        return m1.B <= m2.B;
    return m1.A<= m2.A;
}

int main()
{

    //freopen("d:\\lmo.in","r",stdin);


    int tc;
    sf("%d\n",&tc);
    while(tc-->0)
    {
        int n;
        long long c;

        sf("%d%lld",&n,&c);
        vector<_mail> mails;

        for(int i=0;i<n;i++)
        {
            long long a,b,w;
            sf("%lld%lld%lld",&a,&b,&w);

            _mail m (a,b,w);
            mails.push_back(m);
        }


        // sort mails with the comparer
        sort(mails.begin(),mails.end(),mail_comparer);

        //for(int i=0;i< n;i++)
            //mails[i].prtn();

        long long max=0;

        priority_queue<_mail> q;

        long long aux=0; // value of the mails into the queue

        // each mail goes into the queue
        for(int i=0;i<n;i++)
        {
            q.push(mails[i]);

            // current mail, last enqueued
            _mail m = mails[i];
		
	    // while there still mail with no overlapping with current pop them
	    // and substract its value
            while(q.top().B < m.A)
            {
                //pf("%lld %lld -> %lld\n",q.front().A,q.front().B,q.front().weight);
                aux-=q.top().weight;
                //pf("less %lld\n",q.top().weight);
                q.pop();
            }
            aux+=m.weight;

            // if this had more size
            if(aux > max)
                max = aux;

        }
        // 90% percent of C

        // Answer
        if(max>c)
            pf("BLOCKED %lld\n",max -c);
        // if overloaded
        else if(max > 0.9*c)
        {
            long long D = floor(max/0.9);
            if(D*0.9 != max)
                D++;

            pf("OVERLOAD %lld\n", D-c);
        }

        else pf("OK\n");
    }

}
