/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3632 - Tobby and Query
	Online Judge: COJ
	Idea: Use a Segment Tree, storing whether the number [1...9] appears.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e5 + 3;

int N, Q, arr[lim], a, b;

struct node
{
    int L, R;
    bool mark[10];
} t[lim << 2];


inline int ls(int i){return (i << 1) + 1;}
inline int rs(int i){return (i << 1) + 2;}
int middle(int L, int R){return (L + R) >> 1;}

void buildTree(int idx, int L, int R)
{
    t[idx].L = L; t[idx].R = R;
    for(int i = 0; i < 10; i++)
        t[idx].mark[i] = false;
    // if leaf
    if(L == R)
    {
        t[idx].mark[arr[L]] = true;
        return;
    }
    int le = ls(idx), ri = rs(idx);
    int mid = middle(L, R);
    // build both subtrees
    buildTree(le, L, mid);
    buildTree(ri, mid + 1, R);
    // merge
    for(int i = 0; i < 10; i++)
        t[idx].mark[i] = t[le].mark[i] || t[ri].mark[i];
}


bool answ[10];
void retrieve(int idx, int QL, int QR)
{
    // if outside
    if(t[idx].L > QR || t[idx].R < QL)
        return;
    // if contained
    if(t[idx].L >= QL && t[idx].R <= QR)
    {
        for(int i = 0; i < 10; i++)
            answ[i] = answ[i] || t[idx].mark[i];
        return;
    }
    int mid = middle(t[idx].L, t[idx].R);
    int le = ls(idx), ri = rs(idx);

    retrieve(le, QL, QR);
    retrieve(ri, QL, QR);
}

void solve()
{
    while(cin >> N)
    {
        for(int i = 0; i < N; i++)
            cin >> arr[i];

        buildTree(0, 0, N - 1);

        cin >> Q;
        for(int i = 0; i < Q; i++)
        {
            cin >> a >> b;
            a--; b--;
            for(int i = 0; i < 10; i++) answ[i] = false;
            retrieve(0, a, b);
            int cnt = 0;
            for(int i = 0; i < 10; i++)
                if(answ[i])
                    cnt++;

            cout << cnt << "\n";
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
