/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1187 - Lining up Students
	Online Judge: LightOJ
	Idea: Binary Search over a Fenwick Tree. The ith student can take at most position
	N - arr[i], say it kth, so problem reduces to find the kth active bit in the Fenwick Tree
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

typedef pair<int, int> pii;

const int inf = 1e9 + 7;
const int mod = 1e9 + 7;
const int lim = 1e5 + 3;

int tc, N;
int arr[lim];
int sol[lim];

// >> FENWICK TREE
int len = lim;
int tree[lim];
void build()
{
    for(int i = 0; i < len; i++)
        tree[i] = 0;
}

int lowBit(int i){return (i&-i);}

void update(int idx, int upd)
{
    for(int i = idx; i <= len; i+= lowBit(i))
        tree[i] += upd;
}

int retrieve(int idx)
{
    int sum = 0;
    for(int i = idx; i > 0; i-= lowBit(i))
        sum += tree[i];
    return sum;
}

int retrieve(int a, int b)
{
    return retrieve(b) - retrieve(a - 1);
}
// << FENWICK TREE

void solve()
{
    sf("%d", &tc);
    for(int cs = 1; cs <= tc; cs++)
    {
        sf("%d", &N);
        // reading data
        for(int i = 0; i < N; i++)
            sf("%d", &arr[i]);

        // build the Fenwick Tree
        build();
        // add 1 to every position
        for(int i = 1; i <= N; i++)
            update(i, 1);

        // sweep backwards

        // amount of processed students
        int cnt = N;
        for(int i = N - 1; i >= 0; i--)
        {
            // number of taller students to the left
            int x = arr[i];

            // kth to search
            int kth = cnt - x;

            // binary search over the Fenwick Tree
            int le = 1, ri = N;
            while(le != ri)
            {
                int mid = (le + ri) / 2;

                int am = retrieve(le, mid);

                if(am >= kth)
                    ri = mid;
                else
                {
                    kth -= am;
                    le = mid + 1;
                }
            }
            // update in the Fenwick Tree
            update(le, -1);
            sol[i] = le;

            // decrease the amount of processed students
            cnt--;
        }
        // print answer
        pf("Case %d: %d\n", cs, sol[0]);
    }
}

int main()
{
	solve();
}
