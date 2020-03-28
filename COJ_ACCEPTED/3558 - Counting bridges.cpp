/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3558 - Counting bridges
	Online Judge: COJ
	Idea: Sweep Line + Segment Tree. 
	Two types of events.
	1 - Points, the first and the last point of a horizontal segment are stored (Y2 = -1)
	2 - Segments, the vertical segments are stored
	
	There are 2 boxes each box stores the Points of a circuit and the vertical segment of the other. Both boxes are swept
	When sweeping a box I use a Segment Tree to store active points of the other circuit
	(activate when opening point and deactivate when closing point). And each time a take a vertical segment I query the Segment Tree, active points will be the number of "crossings".	
	
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 6e4 + 7;

int M, x,y;

vector<pair <int , int> > pts;

struct event
{
    int X, Y1, Y2;
    event()
    {}

    event(int xx, int yy1, int yy2)
    {
        X = xx; Y1 = yy1; Y2 = yy2;
    }
};

bool cmp(event a, event b)
{
    if(a.X == b.X)
        return a.Y2 < b.Y2;
    return a.X < b.X;
}

vector<event> boxes[2];

// >> SEGMENT TREE
inline int ls(int idx) {return (idx << 1) + 1;}
inline int rs(int idx) {return (idx << 1) + 2;}
inline int mp(int l, int r){return (l + r) >> 1;}

struct node
{
    int L, R;
    int val;
    node(){}
} t[lim << 2];

void buildTree(int idx, int L, int R)
{
    t[idx].L = L; t[idx].R = R;
    t[idx].val = 0;
    // if leaf
    if(L == R)
        return;
    int mid = mp(L, R);
    buildTree(ls(idx), L, mid);
    buildTree(rs(idx), mid + 1, R);
}

void update(int idx, int ii)
{
    int le = ls(idx), ri = rs(idx), mid = mp(t[idx].L, t[idx].R);
    // if leaf
    if(t[idx].L == t[idx].R)
    {
        t[idx].val^= 1;
        return;
    }
    // if to the left
    if(ii <= mid)
        update(le, ii);
    else update(ri, ii);
    // merge
    t[idx].val = t[le].val + t[ri].val;
}

int retrive(int idx, int QL, int QR)
{
    if(QL > QR) return 0;

    int le = ls(idx), ri = rs(idx), mid = mp(t[idx].L, t[idx].R);
    // if contained
    if(t[idx].L >= QL && t[idx].R <= QR)
        return t[idx].val;
    // if outside
    if(t[idx].L > QR || t[idx].R < QL)
        return 0;
    return retrive(le, QL, QR) + retrive(ri, QL, QR);
}
// << SEGMENT TREE


void readCircuit(int circ)
{
    pts.clear();

    cin >> M;
    int px, py;
    for(int i = 0; i < M; i++)
    {
        cin >> x >> y;
        if(i > 0)
        {
            px = pts[i - 1].first;
            py = pts[i - 1].second;
            // if a vertical line
            if(x == px)
            {
                event e = event(x, min(y, py), max(y, py));
                boxes[circ].push_back(e);
            }
            else
            {
                event e1 = event(x, y, -1);
                event e2 = event(px, y, -1);
                boxes[circ^1].push_back(e1);
                boxes[circ^1].push_back(e2);
            }
        }
        // add the point
        pts.push_back(make_pair(x, y));
    }
    // last closing segment

    // if a vertical line
    px = pts[0].first;
    py = pts[0].second;
    if(x == px)
    {
        event e = event(x, min(y, py), max(y, py));
        boxes[circ].push_back(e);
    }
    else
    {
        event e1 = event(x, y, -1);
        event e2 = event(px, y, -1);
        boxes[circ^1].push_back(e1);
        boxes[circ^1].push_back(e2);
    }
}

int sweepLine(int circ)
{
    int ret = 0;
    // build the Segment Tree
    buildTree(0, 0, lim);
    // assuming they are sorted
    for(int i = 0; i < boxes[circ].size(); i++)
    {
        event e = boxes[circ][i];
        // if vertical event -> query
        if(e.Y2 != -1)
        {
            int aux = retrive(0, e.Y1 + 1, e.Y2 - 1);
            ret += aux;
        }
        // else if the endpoint of a horizontal line update (flip value {0, 1})
        else
        {
            update(0, e.Y1);
        }
    }
    return ret;
}

void solve()
{
    readCircuit(0);
    readCircuit(1);

    // sort em all
    sort(boxes[0].begin(), boxes[0].end(), cmp);
    sort(boxes[1].begin(), boxes[1].end(), cmp);

    int k1 = sweepLine(1);
    int k2 = sweepLine(0);

    // cout << k1 << " " << k2 << endl;

    cout << k1 + k2;
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
