/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3646 - Tobby on Tree II
	Online Judge: COJ
	Idea: Use Heavy Light Descomposition. Use a SegmentTree of GCD for each chain.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 5e4 + 7;

int N, u, v, q, type;

// >> GRAPH
vector<int> adj[lim];

struct node
{
    int level, father;
    int gss, gssIdx;
    int ch, chIdx;
    int val;
    node()
    {
        level = gss = ch = 0;
        gssIdx = father = chIdx = -1;
    }
} nodes[lim];
// << GRAPH

vector<int> chains[lim]; // chains for the descomposition
int cntChains= 0;


struct nodeST
{
    int L, R, gcd;
    nodeST(){}
};
struct SegmentTree
{
    int ch;// chain to which it belogns
    nodeST * t; // tree

    inline int ls(int i){return (i << 1) + 1;}
    inline int rs(int i){return (i << 1) + 2;}
    inline int middle(int L, int R){return (L + R)>>1;}

    SegmentTree(){}
    SegmentTree(int cchh)
    {
        ch = cchh;
        int sz = chains[ch].size();
        // build the segment tree over the idx-th chain
        t = new nodeST[sz << 2];
        // build the SegmentTree
        buildTree(0, 0, sz - 1);
    }

    void buildTree(int idx, int L, int R)
    {
        int le = ls(idx), ri = rs(idx), mid = middle(L, R);

        t[idx].L = L, t[idx].R = R;
        if(L == R)
        {
            t[idx].gcd = nodes[chains[ch][L]].val;
            return;
        }
        // build both sunbtrees
        buildTree(le, L, mid);
        buildTree(ri, mid + 1, R);
        // merge
        t[idx].gcd = __gcd(t[le].gcd, t[ri].gcd);
    }

    void update(int idx, int ii, int upd)
    {
        int le = ls(idx), ri = rs(idx), mid = middle(t[idx].L, t[idx].R);

        if(t[idx].L == t[idx].R)
        {
            t[idx].gcd = upd;
            return;
        }
        if(ii <= mid)
            update(le, ii, upd);
        else update(ri, ii, upd);
        // merge
        t[idx].gcd = __gcd(t[le].gcd, t[ri].gcd);
    }

    int retrieve(int idx, int QL, int QR)
    {
        int le = ls(idx), ri = rs(idx);
        // if contained
        if(t[idx].L >= QL && t[idx].R <= QR)
            return t[idx].gcd;
        // if outside
        if(t[idx].L > QR || t[idx].R < QL)
            return 0;
        return __gcd(retrieve(le, QL, QR), retrieve(ri, QL, QR));
    }
} sTrees[lim];


// >> HLD
int DFS(int idx)
{
    int total = 0;
    for(int i = 0; i < adj[idx].size(); i++)
    {
        int nxt = adj[idx][i];

        // if not its father
        if(nxt != nodes[idx].father)
        {
            nodes[nxt].level = nodes[idx].level + 1;
            nodes[nxt].father = idx;

            int k = DFS(nxt);
			// update the value if the greatest subtree size
            if(k >= nodes[idx].gss)
            {
                nodes[idx].gss = k;
                nodes[idx].gssIdx = nxt;
            }
            total += k;
        }
    }
    return total + 1;
}

void HeavyLightDescomposition(int root)
{
    DFS(root);

    // for each possible head
    for(int i = 0; i < N; i++)
    {
        if(nodes[i].father == -1 || nodes[ nodes[i].father ].gssIdx != i)
        {
            int idx = i;
            // set the head
            chains[cntChains].clear();
            // adding elements to the chains
            while(idx != -1)
            {
                nodes[idx].ch = cntChains;
                nodes[idx].chIdx = chains[cntChains].size();
                // insert the element in the chain
                chains[cntChains].push_back(idx);
                idx = nodes[idx].gssIdx;
            }
            // build the SegmentTree
            sTrees[cntChains] = SegmentTree(cntChains);

            cntChains++;
        }
    }
}


int LCA(int a, int b)
{
    int chA = nodes[a].ch;
    int chB = nodes[b].ch;

    int gcd = 0;
	// while both nodes in different chains
    while(chA != chB)
    {
        int headA = chains[chA][0]; // head of the chain of A
        int headB = chains[chB][0]; // head of the chain of B
        if(nodes[headA].level > nodes[headB].level)
        {
            gcd = __gcd(gcd, sTrees[chA].retrieve(0, 0, nodes[a].chIdx));
            a = nodes[ headA ].father;
            chA = nodes[a].ch;
        }
        else
        {
            gcd = __gcd(gcd, sTrees[chB].retrieve(0, 0, nodes[b].chIdx));
            b = nodes[ headB ].father;
            chB = nodes[b].ch;
        }
    }

    if(nodes[a].chIdx > nodes[b].chIdx) swap(a, b);

    gcd = __gcd(gcd, sTrees[chA].retrieve(0, nodes[a].chIdx, nodes[b].chIdx));
    return gcd;
}

// << HLD

void reset()
{
    cntChains = 0;
    for(int i = 0; i < N; i++)
    {
        adj[i].clear();
        chains[i].clear();
        sTrees[i] = SegmentTree();
        nodes[i] = node();
    }
}

void printNode(int i)
{
    cout << i << endl;
    cout << "l:" << nodes[i].level << " f:" << nodes[i].father << endl;
    cout << "gss:" << nodes[i].gss << " gssIdx:" << nodes[i].gssIdx << endl;
    cout << "ch:" << nodes[i].ch << " chIdx:" << nodes[i].chIdx << endl;
    cout << "----------------------------------------------\n";
}

void solve()
{
    while(cin >> N)
    {
        reset();

        // reading
        for(int i = 0; i < N; i++)
            cin >> nodes[i].val;
        // reading edges
        for(int i = 0; i < N - 1; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        HeavyLightDescomposition(0);

        // reading queries
        cin >> q;
        for(int i = 0; i < q; i++)
        {
            cin >> type >> u >> v;
            if(type == 1)
            {
                // query from U to V
                int answ = LCA(u, v);
                cout << answ << "\n";
            }
            else
            {
                // update the value in U by V
                int ch = nodes[u].ch;
                int chIdx = nodes[u].chIdx;
				// update in its SegmentTree
                sTrees[ch].update(0, chIdx, v);
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
