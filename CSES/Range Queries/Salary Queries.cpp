/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Salary Queries
	Link: https://cses.fi/problemset/task/1144
	Online Judge: CSES
	Idea: Offline Queries + Coordinates Compression + Fenwick Tree. All values of salaries, salary updates and query bounds, should be compressed
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define x first
#define y second
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;

int n, q;
int arr[lim]; // salaries

// >> Coordinates Compression
vector<int> toComp;
// >> Coordinates Compression

class FenwickTree
{
    private:
        vector<ll> tree;
        inline int lowBit(int i) {return i&-i;}
    public:

        FenwickTree(){}

        FenwickTree(int len)
        {
            tree.resize(len, 0);
        }

        FenwickTree(int len, int v)
        {
            tree.resize(len, v);
        }

        void update(int idx, ll upd)
        {
            for(int i = idx; i < tree.size(); i+= lowBit(i))
                tree[i]+= upd;
        }

        ll retrieve(int idx)
        {
            ll sum = 0;
            for(int i = idx; i > 0; i-= lowBit(i))
                sum += tree[i];
            return sum;
        }

        ll retrieve(int a, int b)
        {
            if(a > b)
                return 0;
            return retrieve(b) - retrieve(a - 1);
        }
};
FenwickTree * ft;

struct Query
{
	char type;
	int x, y;
	Query(){}
} queries[lim];

void solve()
{
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		toComp.push_back(arr[i]);
	}

	// reading queries
	for(int i = 0; i < q; i++)
	{
		cin >> queries[i].type >> queries[i].x >> queries[i].y;
		if(queries[i].type == '!')
			toComp.push_back(queries[i].y);
		else
		{
			toComp.push_back(queries[i].x);
			toComp.push_back(queries[i].y);
		}		
	}

	// compress
	sort(toComp.begin(), toComp.end());
	unique(toComp.begin(), toComp.end());
	
	// maximun size for the FenwickTree
	int mx = toComp.size()+ 1;

	ft = new FenwickTree(mx + 1);

	for(int i = 1; i <= n; i++)
	{
		int v = lower_bound(toComp.begin(), toComp.end(), arr[i]) - toComp.begin();
		ft->update(v + 1, 1);
	}

	for(int i = 0; i < q; i++)
	{		
		if(queries[i].type == '!')
		{			
			int c = arr[queries[i].x];
			int v = lower_bound(toComp.begin(), toComp.end(), c) - toComp.begin();
			ft->update(v + 1, -1);

			int s = lower_bound(toComp.begin(), toComp.end(), queries[i].y) - toComp.begin();
			
			ft->update(s + 1, 1);
			arr[queries[i].x] = queries[i].y;			
		}
		else
		{
			int a = lower_bound(toComp.begin(), toComp.end(), queries[i].x) - toComp.begin();
			int b = lower_bound(toComp.begin(), toComp.end(), queries[i].y) - toComp.begin();
			// print answer
			cout << ft->retrieve(a + 1, b + 1) << endl;
		}		
	}
}
 
void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}
 
void IO()
{
	if(fopen("c:\\Users\\LUISMO\\lmo.in","r") != NULL)
	{
		freopen("c:\\Users\\LUISMO\\lmo.in","r",stdin);
	}
	else if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("media/Beijing/lmo.in","r") != NULL)
	{
		freopen("/media/Beijing/lmo.in", "r", stdin);
	}
}
 
int main()
{
	IO();
 
	fastIO();
 
	solve();
}