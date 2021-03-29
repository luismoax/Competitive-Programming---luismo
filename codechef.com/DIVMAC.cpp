/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: DIVMAC
	Link: https://www.codechef.com/SEPT16/problems/DIVMAC
	Online Judge: Codechef
	Idea: The maximun number of updates to be performed over a value is no more than 20 before turning into 1. Therefor I used a Set 
    to store indexes which values have yet to become 1 and a Segment Tree to keep max value per ranges
    0 - Binary Search over the set and iterate for each positio not yet 1, and manually update it on the array, and then on the
    Segment Tree
    1 - Classic Query on Segment Tree
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
#define fi first
#define se second
#define M_PI 2.0 * acos(0)
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 1e6 + 3;

int tc, N, M;

// >> Erathostenes Sieve
ll sieve[lim];
void buildSieve()
{
	sieve[1] = 1;
	for(ll i = 2; i < lim; i+= 2)
		sieve[i] = 2;
	for(ll i = 3; i < lim; i+= 2)
	{
		if(sieve[i] == 0)
		{
			sieve[i] = i;
			for(ll j = i * i; j < lim; j += i)
				if(sieve[j] == 0)
					sieve[j] = i;
		}		
	}
}
// << Erathostenes Sieve


// MIN / MAX SegmentTree - Point Update
struct SegmentTree
{

	vector<int> mx;
	vector<int> mn;

	SegmentTree(int len)
	{
		mx.resize(len << 2 + 3, 0);
		mn.resize(len << 2 + 3, 0);
	}

	void update(int idx, int L, int R, int ii, int upd)
	{
		if(L == R)
		{
			mx[idx] = mn[idx] = upd;
			return;
		}
		int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
		if(ii <= mid)
			update(le, L, mid, ii, upd);
		else update(ri, mid + 1, R, ii, upd);
		// merge
		mx[idx] = max(mx[le], mx[ri]);
		mn[idx] = min(mn[le], mn[ri]);
	}

	pii retrieve(int idx, int L, int R, int QL, int QR)
	{
		if(L >= QL && R <= QR)
			return mkp(mx[idx], mn[idx]);

		if(L > QR || R < QL)
			return mkp(-1, mod + 59);

		int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;

		pii s1 = retrieve(le, L, mid, QL, QR);
		pii s2 = retrieve(ri, mid + 1, R, QL, QR);
		// merge
		pii ret = mkp(max(s1.first, s2.first), min(s1.second, s2.second));
		return ret;
	}

};

void printArr(vector<ll>& arr)
{
	for(auto item: arr)
		cout << item << " ";
	cout << endl;
}


void solve()
{
	buildSieve();

	cin >> tc;

	while(tc -- > 0)
	{
		cin >> N >> M;

		vector<ll> arr(N);

		SegmentTree st = SegmentTree(N);

		set<int> rbTree;
		for(int i = 0; i < N; i++)
		{
			cin >> arr[i];

			st.update(0, 0, N - 1, i, sieve[arr[i]]);

			rbTree.insert(i);
		}

		while(M--)
		{
			int ty, a, b;
			cin >> ty >> a >> b;
			a--; b--;

			if(ty == 1)
			{
				pii k = st.retrieve(0, 0, N - 1, a, b);
				int answ = k.first;
				cout << answ << " ";
				// cout << endl;
			}
			else
			{
				set<int>::iterator it = rbTree.lower_bound(a);

				vector<int> del;
				while(it != rbTree.end() && *it <= b)
				{
					int idx = *it;

					arr[idx] = arr[idx] / sieve[arr[idx]];

					if(arr[idx] == 1)
						del.push_back(idx);

					st.update(0, 0, N - 1, idx, sieve[arr[idx]]);
				
					it++;
				}

				for(auto item: del)
				{
					rbTree.erase(rbTree.find(item));
				}
			}
		}
		cout << endl;
	}
}
 
void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}
 
void IO()
{

	if(fopen("c:\\Competitive Programming\\lmo.in","r") != NULL)
	{
		freopen("c:\\Competitive Programming\\lmo.in","r",stdin);
	}
	else if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
		// freopen("d:\\lmo.out","w",stdout);
	}
	else if(fopen("/Wolfburg/lmo.in","r") != NULL)
	{
		freopen("/Wolfburg/lmo.in", "r", stdin);
	}
}
 
int main()
{
	IO();
 
	fastIO();
 
	solve();
}