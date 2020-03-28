/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 4122 - Computing queries
	Online Judge: COJ
	Idea: Mo's Algorithm. ~DQUERY and KQUERY. Sort + Segment Tree
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 1e6 + 2;


int N, Q;

// >> SEGMENT TREE
int t[lim<<2];

void update(int idx, int L, int R, int ii, int upd)
{
    // if leaf
    if(L == R)
    {
        t[idx] = upd;
        return;
    }
    int le = idx * 2 + 1;
    int ri = le + 1;
    int mid = (L + R) / 2;
    if(ii <= mid)
        update(le, L, mid, ii, upd);
    else update(ri, mid + 1, R, ii, upd);
    // merge
    t[idx] = max(t[le], t[ri]);
}

int retrieve(int idx, int L, int R, int QL, int QR)
{
    // if contained
    if(L >= QL && R <= QR)
        return t[idx];
    // if outside
    if(L > QR || R < QL)
        return 0;
    int le = idx * 2 + 1;
    int ri = le + 1;
    int mid = (L + R) / 2;
    return max(retrieve(le, L, mid, QL, QR),
               retrieve(ri, mid + 1, R, QL, QR));
}

// << SEGMENT TREE
int arr[lim];

struct query
{
    int ord, idx, answ;
    query(){}
    query(int o, int i, int a)
    {ord = o; idx = i; answ = a;}
};

bool cmp(query a, query b)
{
    return a.idx < b.idx;
}
vector<query> queries;

// to print the answer
int prit[lim];

void solve()
{
    cin >> N >> Q;
	// reading integers
    for(int i = 0; i < N; i++)
        cin >> arr[i+1];
	
	// reading and storing the queries
    for(int i = 0; i < Q; i++)
    {
        int x; cin >> x;
        query q = query(i + 1, x, -1);
        queries.push_back(q);
    }

	// sort 'em all
    sort(queries.begin(), queries.end(), cmp);

	// linear scan Mo
    int iq = 0;
    for(int i = 1; i <= N; i++)
    {
	
        while(iq < Q && queries[iq].idx == i)
        {
			// the the value at the queried index
            int v = arr[queries[iq].idx];
			// take the value with greater index lower than v (from the processed ones)
            int mx = retrieve(0, 0, lim, 0, v - 1);
			
			// update the answer of the current query
            if(mx == 0)
                queries[iq].answ = -1;
            else queries[iq].answ = arr[mx];

            iq++;
        }
		// update the current value in the tree
        update(0, 0, lim, arr[i], i);
    }
	// set the order of the answer
    for(int i = 0; i < Q; i++)
        prit[queries[i].ord] = queries[i].answ;
	// print the answer
    for(int i = 1; i <= Q; i++)
        cout << prit[i] << endl;
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
	}
}

int main()
{
	IO();

	fastIO();

	solve();
}
