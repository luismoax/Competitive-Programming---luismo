/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3702 - Queries and LCPs
	Online Judge: COJ
	Idea: Use a Segment Tree. In each node store a string containing the LCP of the elements in the interval represented by the node.
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

string LCP(string & a, string & b)
{
    string ret = "";
    for(int i = 0; i < min(a.length(), b.length()); i++)
        if(a[i] != b[i])
            break;
        else ret+= a[i];
    return ret;
}

vector<string> coll;

int ls(int idx){return (idx << 1) + 1;}
int rs(int idx){return (idx << 1) + 2;}
int middle(int L, int R) {return (L + R) >> 1;}

struct node
{
    string lcp, lazy;
    int L, R;
} t[lim << 2];

void buildTree(int idx, int L, int R)
{
    t[idx].L = L; t[idx].R = R;
    if(L == R)
    {
        t[idx].lcp = coll[L];
        return;
    }
    int mid = middle(L, R);
    int le = ls(idx), ri = rs(idx);

    buildTree(le, L, mid);
    buildTree(ri, mid + 1, R);
    // merge    
	t[idx].lcp = "";
    for(int i = 0; i < min(t[le].lcp.length(), t[ri].lcp.length()); i++)
        if(t[le].lcp[i] != t[ri].lcp[i])
            break;
        else t[idx].lcp+= t[le].lcp[i];
}

void propagate(int idx)
{
    if(t[idx].lazy.length() > 0)
    {
        t[idx].lcp = t[idx].lazy;
        if(t[idx].L != t[idx].R)
        {
            t[ls(idx)].lazy = t[idx].lazy;
            t[rs(idx)].lazy = t[idx].lazy;
        }
    }
    t[idx].lazy = "";
}

string retrieve(int idx, int QL, int QR)
{
    propagate(idx);

    if(t[idx].L >= QL && t[idx].R <= QR)
        return t[idx].lcp;
    if(t[idx].L > QR || t[idx].R < QL)
        return "$";

    int mid = middle(t[idx].L, t[idx].R);
    int le = ls(idx), ri = rs(idx);

    string str1 = retrieve(le, QL, QR);
    string str2 = retrieve(ri, QL, QR);

    if(str1 == "$")
        return str2;
    if(str2 == "$")
        return str1;
    // return LCP
	string ret = "";
    for(int i = 0; i < min(str1.length(), str2.length()); i++)
        if(str1[i] != str2[i])
            break;
        else ret+= str1[i];
    return ret;
}


string upd;
void update(int idx, int QL, int QR)
{
    propagate(idx);

    int mid = middle(t[idx].L, t[idx].R);
    int le = ls(idx), ri = rs(idx);

    // if contained
    if(t[idx].L >= QL && t[idx].R <= QR)
    {
        t[idx].lcp = upd;
        if(t[idx].L != t[idx].R)
        {
            t[le].lazy = upd;
            t[ri].lazy = upd;
        }
        return;
    }

    if(t[idx].L > QR || t[idx].R < QL)
        return;

    update(le, QL, QR);
    update(ri, QL, QR);
    // merge    
	t[idx].lcp = "";
    for(int i = 0; i < min(t[le].lcp.length(), t[ri].lcp.length()); i++)
        if(t[le].lcp[i] != t[ri].lcp[i])
            break;
        else t[idx].lcp+= t[le].lcp[i];
}


int N, M;
string str;
int type, a, b;

void solve()
{
    cin >> N >> M;
    // reading strings
    for(int i = 0; i < N; i++)
    {
        cin >> str;
        coll.push_back(str);
    }

    buildTree(0, 0, N - 1);

    // reading queries
    for(int i = 0; i < M; i++)
    {
        cin >> type >> a >> b;
        a--; b--;
        if(type == 1)
        {
            string answ = retrieve(0, a, b);
            //cout << answ<<" " <<  answ.length() << "\n";
            cout << answ.length() << "\n";
        }
        else
        {
            cin >> upd;

            update(0, a, b);
        }
    }
}


int main()
{
	if(fopen("d:\\lmo.in","r") != NULL ||
	fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
		// freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
		// freopen("d:\\lmo.out","w",stdout);
	}

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
