/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3626 - Strongest Digit
	Online Judge: COJ
	Idea: Segment Tree. Store in each node the frequency of each digit in the represented interval. Careful when updating
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e5 + 7;
int N, Q, type, a, b;
string str;


int upd[10];
int answ[10];

inline int ls(int i){return (i << 1) + 1;}
inline int rs(int i){return (i << 1) + 2;}
inline int middle(int L, int R){return (L + R) >> 1;}

struct node
{
    int L, R;
    int arr[10];
    int lazy[10];
    bool clean = false;    
} t[lim << 2];


void propagate(int idx, int L, int R)
{
    // if to propagate
    if(!t[idx].clean)
    {
        for(int i = 0; i < 10; i++)
        {
            t[idx].arr[i] = t[idx].lazy[i] * (R - L + 1);
            // reset lazyness
            t[idx].lazy[i] = 0;
        }

        // if has kids
        if(L != R)
        {
            int le = ls(idx), ri = rs(idx);
            for(int i = 0; i < 10; i++)
            {
                t[le].lazy[i] = t[idx].arr[i] / (R - L + 1);
                t[ri].lazy[i] = t[idx].arr[i] / (R - L + 1);
            }
            t[le].clean = t[ri].clean = false;
        }
    }
    t[idx].clean = true;
}

// update
void update(int idx, int L, int R, int QL, int QR)
{
    propagate(idx, L, R);
    // if contained in the interval
    if(L >= QL && R <= QR)
    {
        // update
        for(int i = 0; i < 10; i++)
            t[idx].arr[i] = upd[i]  * (R - L + 1);

        // if has kids -> load Lzyness
        if(L != R)
        {
            int le = ls(idx), ri = rs(idx);
            for(int i = 0; i < 10; i++)
            {
                t[le].lazy[i] = t[idx].arr[i] / (R - L + 1);
                t[ri].lazy[i] = t[idx].arr[i] / (R - L + 1);
            }
            t[le].clean = t[ri].clean = false;
        }
        return;
    }

    // if outside
    if(L > QR || R < QL)
        return;

    int le = ls(idx), ri = rs(idx);
    int mid = middle(L, R);

    update(le, L, mid, QL, QR);
    update(ri, mid + 1, R, QL, QR);

    // merging solution
    for(int i = 0; i < 10; i++)
        t[idx].arr[i] = t[le].arr[i] + t[ri].arr[i];
}

void retrieve(int idx, int L, int R, int QL, int QR)
{
    propagate(idx, L, R);
    // if contained
    if(L >= QL && R <= QR)
    {
        // add to the solution
        for(int i = 0; i < 10; i++)
            answ[i] += t[idx].arr[i];
        return;
    }
    // if outside
    if(L > QR || R < QL)
        return;

    int le = ls(idx), ri = rs(idx);
    int mid = middle(L, R);

    retrieve(le, L, mid, QL, QR);
    retrieve(ri, mid + 1, R, QL, QR);
}

void resetUpd()
{
    for(int i = 0; i < 10; i++) upd[i] = 0;
}
void resetAnsw()
{
    for(int i = 0; i < 10; i++) answ[i] = 0;
}

void printAnsw()
{
    cout << "ANSWER:\n";
    // print the answer array
    for(int i = 0; i < 10; i++)
        cout << answ[i] << " ";
    cout << "\n";
}

void solve()
{
    cin >> N >> Q;
    // reading integers
    for(int i = 0; i < N; i++)
    {
        cin >> str;

        resetUpd();

        for(int m = 0; m < str.length(); m++)
            upd[str[m] - '0']++;

        // update in the Segment Tree
        update(0, 0, N - 1, i, i);
    }

    // reading queries
    for(int q = 0; q < Q; q++)
    {
        cin >> type >> a >> b;
        a--; b--;

        if(type == 0)
        {
            resetAnsw();

            retrieve(0, 0, N - 1, a, b);

            int mx = -1;
            int mxSize = -10;

            for(int i = 0; i < 10; i++)
            {
                if(answ[i] > 0)
                {
                    if(mx == -1 || mxSize < answ[i])
                    {
                        mx = i;
                        mxSize = answ[i];
                    }
                }
            }

            //printAnsw();

            cout << mx << "\n";
        }
        else
        {
            cin >> str;

            resetUpd();

            for(int i = 0; i < str.length(); i++)
                upd[str[i] - '0']++;

            update(0, 0, N - 1, a, b);
        }
    }
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
	}

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
