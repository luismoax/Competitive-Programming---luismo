/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3656 - Salary Inequity
	Online Judge: COJ
	Idea: DFS, to represent the tree on an array, then use a Segment Tree to query intervals. Check implemenation
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e6 + 7;
ll infinite = 10000000000;

int N, tc, x, Q, a;
char type;

vector<int> adj[lim]; // adjacency of the tree

// >> SegmentTree
int QL, QR;
ll upd;
inline int ls(int idx){return (idx << 1) + 1;}
inline int rs(int idx){return (idx << 1) + 2;}
inline int mp(int L, int R){return (L + R) >> 1;}

ll tmin[lim << 2]; // Tree
ll tmax[lim << 2]; // Tree
ll lazy[lim << 2];

void propagate(int idx, int L, int R)
{
    int le = ls(idx), ri = rs(idx), mid = mp(L, R);
    if(lazy[idx] > 0)
    {
        tmin[idx] += lazy[idx];
        tmax[idx] += lazy[idx];
        // if not leaf
        if(L != R)
        {
            // propagate lazyness
            lazy[le]+= lazy[idx];
            lazy[ri]+= lazy[idx];
        }
    }
    lazy[idx] = 0;
}

void update(int idx, int L, int R)
{
    int le = ls(idx), ri = rs(idx), mid = mp(L, R);
    // first of all propagete
    propagate(idx, L, R);

    // if contained
    if(L >= QL && R <= QR)
    {
        // update this node
        tmin[idx]+= upd;
        tmax[idx]+= upd;

        // if not leaf
        if(L != R)
        {
            lazy[le]+= upd;
            lazy[ri]+= upd;
        }
        return;
    }
    // if outside
    if(L > QR || R < QL)
        return;

    update(le, L, mid);
    update(ri, mid + 1, R);
    // merge solution
    tmin[idx] = min(tmin[le], tmin[ri]);
    tmax[idx] = max(tmax[le], tmax[ri]);
}

ll retrieveMin(int idx, int L, int R)
{
    int le = ls(idx), ri = rs(idx), mid = mp(L, R);
    // first of all propagete
    propagate(idx, L, R);

    // if contained
    if(L >= QL && R <= QR)
        return tmin[idx];

    // if outside
    if(L > QR || R < QL)
        return infinite;

    ll k1 = retrieveMin(le, L, mid);
    ll k2 = retrieveMin(ri, mid + 1, R);

    return min(k1, k2);
}

ll retrieveMax(int idx, int L, int R)
{
    int le = ls(idx), ri = rs(idx), mid = mp(L, R);
    // first of all propagete
    propagate(idx, L, R);

    // if contained
    if(L >= QL && R <= QR)
        return tmax[idx];

    // if outside
    if(L > QR || R < QL)
        return 0;

    ll k1 = retrieveMax(le, L, mid);
    ll k2 = retrieveMax(ri, mid + 1, R);

    return max(k1, k2);
}
// >> SegmentTree


struct node
{
    ll salary;
    int leftBound, rightBound;
    node(){}
} n[lim];

int cnt = -1;

/*
int DFS(int idx)
{
    cnt++;
    n[idx].leftBound = cnt;

    // insert this value in the tree
    QL = QR = cnt;
    upd = n[idx].salary;
    update(0, 0, N - 1);
    //

    for(int i = 0; i < adj[idx].size(); i++)
    {
        int nxt = adj[idx][i];

        DFS(nxt);
    }
    n[idx].rightBound = cnt;
}
*/

int dfsIndexes[lim];
void DFS(int root)
{
    cnt = 0;
    stack<int> stk;

    stk.push(root);
    n[root].leftBound = 0;

    QL = QR = 0;
    upd = n[0].salary;
    update(0, 0, N - 1);

    while(stk.size() > 0)
    {
        int tp = stk.top();

        if(dfsIndexes[tp] < adj[tp].size())
        {
            int nxt = adj[tp][ dfsIndexes[tp] ];
            stk.push(nxt);
            dfsIndexes[tp]++; // increase

            cnt++;

            n[nxt].leftBound = cnt;

            // update
            QL = QR = cnt;
            upd = n[nxt].salary;
            update(0, 0, N - 1);
        }
        else
        {
            // if no more childs
            n[tp].rightBound = cnt;

            // pop this node away
            stk.pop();
        }
    }
}


void reset()
{
    for(int i = 0; i < N; i++)
    {
        adj[i].clear();
        n[i].leftBound = n[i].rightBound = n[i].salary = -1;
    }
    fill(tmin, tmin + (N << 2), 0);
    fill(tmax, tmax + (N << 2), 0);
    fill(lazy, lazy + (N << 2), 0);
    fill(dfsIndexes, dfsIndexes + N, 0);

    cnt = -1;
}


void solve()
{
    cin >> tc;
    while(tc--)
    {
        cin >> N;

        reset();

        // reading adjacency
        for(int i = 0; i < N - 1; i++)
        {
            cin >> x; x--;
            adj[x].push_back(i + 1);
        }

        // reading salaries
        for(int i = 0; i < N; i++)
            cin >> n[i].salary;

        // on the
        DFS(0);

        // reading queries
        cin >> Q;
        for(int i = 0; i < Q; i++)
        {
            cin >> type >> a;
            a--;

            QL = n[a].leftBound;
            QR = n[a].rightBound;

            if(type == 'Q')
            {

                ll mn = retrieveMin(0, 0, N - 1);
                ll mx = retrieveMax(0, 0, N - 1);

                cout << mx - mn << "\n";
            }
            else
            {
                cin >> upd;

                update(0, 0, N - 1);
            }
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
