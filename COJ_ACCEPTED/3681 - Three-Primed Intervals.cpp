/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3681 - Three-Primed Intervals
	Online Judge: COJ
	Idea:
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e6 + 3;

int tc, A, B;

int mark[lim];
vector<int> primes;
int di[lim];

// >> For RMQ
int rmq[lim][20];
// << For RMQ

void sieve()
{
    // >> Eratostenes Sieve
    primes.push_back(2);
    for(int i = 4; i < lim; i+= 2)
        mark[i] = true;

    for(int i = 3; i < lim; i+= 2)
        if(!mark[i])
        {
            primes.push_back(i);
            for(int j = i + i; j < lim; j+= i)
                mark[j] = true;
        }
}

void rmqPreProcess()
{
    // build the RMQ table over the di array
    int len = primes.size();
    for(int i = 0; i < len; i++)
        rmq[i][0] = di[i];
    // for each power of two
    for(int j = 1; (1 << j) <= len; j++)
    {
        // for each possible starting position
        for(int i = 0; i + (1 << j) - 1 < len; i++)
        {
            int k1 = rmq[i][j - 1];
            int k2 = rmq[i + (1 << (j - 1))][j - 1];
            rmq[i][j] = min(k1, k2);
        }
    }
}

int rmqQuery(int a, int b)
{
    if(a > b)
        swap(a, b);
    int sz = log2(b - a + 1);

    int k1 = rmq[a][sz];
    int k2 = rmq[b - (1 << sz) + 1][sz];
    return min(k1, k2);
}

void preProcess()
{
    sieve();
    // fill table with distances
    di[0] = di[1] = INFINITY;
    for(int i = 2; i < primes.size(); i++)
        di[i] = primes[i] - primes[i - 2];
    //
    rmqPreProcess();
}


int binarySearch(int L, int R, int x)
{
    if(L == R)
        return L;

    int mid = (L + R) >> 1;

    if(x <= primes[mid])
        return binarySearch(L, mid, x);
    return binarySearch(mid + 1, R, x);
}



void solve()
{
    preProcess();
    cin >> tc;
    while(tc--)
    {
        cin >> A >> B;

        // this should be improved to LogN with Binary Search
        // int lft = 0, rgt = primes.size() - 1;
        //for(lft; primes[lft] < A && lft < primes.size(); lft++){}
        //for(rgt; primes[rgt] > B && rgt >= 0; rgt--) {}

        int lft = binarySearch(0, primes.size() - 1, A);
        int rgt = binarySearch(0, primes.size() - 1, B);

        if(primes[lft] < A) lft++;
        if(primes[rgt] > B) rgt--;

        lft+= 2;

		int answ = rmqQuery(lft, rgt) + 1;
		if(lft > rgt)
            answ = -1;

		cout << answ << "\n";
    }
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
		//freopen("d:\\lmo.out","w",stdout);
	}
	else if(fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
	}

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
