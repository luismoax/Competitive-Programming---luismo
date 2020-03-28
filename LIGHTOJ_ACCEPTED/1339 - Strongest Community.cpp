/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1339 - Strongest Community
	Online Judge: LightOJ
	Idea: Use a Segment Tree to find the greatest subsegment with equal values
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
const ll inf = 1e18 + 3;
const int mod = 1e9 + 7;
const int lim = 100000;


int tc, N, C, Q;
int arr[lim];

// >> SEGMENT TREE
int QL, QR;
struct node
{
    node(){}
    int leWing, riWing, mx;

} t[lim * 4];

int ls(int i){return (i * 2) + 1;}
int mp(int L, int R){ return (L + R) / 2; }

void buildTree(int idx, int L, int R)
{
    if(L == R)
    {
        t[idx].leWing = t[idx].riWing = t[idx].mx = 1;
        return;
    }

    int le = ls(idx);
    int ri = le + 1;
    int mid = mp(L, R);

    // build both subtrees
    buildTree(le, L, mid);
    buildTree(ri, mid + 1, R);

    // merge
    int aux = 0;
    bool flag = arr[mid] == arr[mid + 1];
    if(flag)
        aux = t[le].riWing + t[ri].leWing;

    t[idx].mx = max(aux, max(t[le].mx, t[ri].mx));
    // updating left wing
    if(t[le].mx == (mid-L+1) && flag)
        t[idx].leWing = aux;
    else t[idx].leWing = t[le].leWing;
    // updating right wing
    if(t[ri].mx == (R-(mid+1)+1) && flag)
        t[idx].riWing = aux;
    else t[idx].riWing = t[ri].riWing;
}

node retrieve(int idx, int L, int R)
{
    node ret;
    // if contained
    if(L >= QL && R <= QR)
    {
        ret.mx = t[idx].mx;
        ret.leWing = t[idx].leWing;
        ret.riWing = t[idx].riWing;
        return ret;
    }
    // if outside
    if(L > QR || R < QL)
    {
        ret.mx = -1;
        return ret;
    }
    // pointers
    int le = ls(idx);
    int ri = le + 1;
    int mid = mp(L, R);


    node fle = retrieve(le, L, mid);
    node fri = retrieve(ri, mid + 1, R);

    // if the left part was outside the bounds
    if(fle.mx == -1)
        return fri;
    // if the right part was outside the bounds
    if(fri.mx == -1)
        return fle;


    // merge
    int aux = 0;
    bool flag = (arr[mid] == arr[mid+1]);

    if(flag)
        aux = fle.riWing + fri.leWing;

    ret.mx = max(aux, max(fle.mx, fri.mx));

    ret.leWing = fle.leWing;
    if(fle.mx == (mid-L+1) && flag)
        ret.leWing = aux;

    ret.riWing = fri.riWing;
    if(fri.mx == (R-(mid+1)+1) && flag)
        ret.riWing = aux;

    //
    return ret;
}

// << SEGMENT TREE


void solve()
{
    int cs = 1;
    // cin >> tc;
    sf("%d", &tc);
    while(tc-- > 0)
    {
        // cin >> N >> C >> Q;
        sf("%d%d%d", &N, &C, &Q);
        // reading N elements
        for(int i = 0; i < N; i++)
            // cin >> arr[i];
            sf("%d", &arr[i]);

        // build the SegmentTree
        buildTree(0, 0, N - 1);

        // cout << "Case " << cs << ":\n"; cs++;
        pf("Case %d:\n", cs); cs++;
        // reading queries
        for(int i = 0; i < Q; i++)
        {
            int a, b;
            // cin >> a >> b;
            sf("%d%d", &a, &b);
            a--; b--;
            QL = a; QR = b;

            // answer
            node answ = retrieve(0, 0, N - 1);
            // cout << answ.mx << "\n";
            pf("%d\n", answ.mx);
        }
    }
}

int main()
{

	solve();
}
