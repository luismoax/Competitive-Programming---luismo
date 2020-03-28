/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3482 - An Interesting List
    Online Judge: COJ
    Idea: DP + (Fenwick Tree or Segment Tree)
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 3e3 + 7;
const int mod = 1e9 + 7;

int N, L, M;

// dp[i][j] the amount of strings of length i that end at digit j
ll dp[lim][lim];

// >> Fenwick Tree
struct FenwickTree
{
	ll arr[lim];
	// builder
	FenwickTree(){ fill(arr, arr + lim, 0); }

	inline int lowBit(int idx){return idx & -idx;}

	void update(int idx, ll upd)
	{
		for(int i = idx; i < lim; i+= lowBit(i))
			arr[i] = (upd + arr[i]) % mod;
	}

	ll retrieve(int idx)
	{
		ll sum = 0;
		for(int i = idx; i > 0; i -= lowBit(i))
			sum = (sum + arr[i]) % mod;
		return sum;
	}

	ll retrieve(int a, int b)
	{
		if(a > b)
			return 0;
		return (retrieve(b) - retrieve(a - 1) + mod) % mod;
	}
};
// << Fenwick Tree



// >> Segment Tree
struct node
{
	int L, R;
	ll sum;
	node(){}
};

struct SegmentTree
{
	node * t;

	SegmentTree(int len)
	{
		t = new node[len << 2];
		buildTree(0, 0, len - 1);
	}

	inline int ls(int i){return (i << 1) + 1;}
	inline int rs(int i){return (i << 1) + 2;}
	int middle(int l, int r){return (l + r) >> 1;}

	// build the Segment Tree
	void buildTree(int idx, int L, int R)
	{
		t[idx].L = L; t[idx].R = R;
		// if leaf
		if(L == R)
		{
			t[idx].sum = 0;
			return;
		}
		int mid = middle(L, R);
		int le = ls(idx), ri = rs(idx);
		buildTree(le, L, mid);
		buildTree(ri, mid + 1, R);
		t[idx].sum = 0;
	}


	void update(int idx, int ii, ll upd)
	{
		// if leaf
		if(t[idx].L == t[idx].R)
		{
			t[idx].sum = (t[idx].sum + upd) % mod;
			return;
		}
		int mid = middle(t[idx].L, t[idx].R);
		int le = ls(idx), ri = rs(idx);
		if(ii <= mid)
			update(le, ii, upd);
		else update(ri, ii, upd);
		t[idx].sum = (t[le].sum + t[ri].sum) % mod;
	}

	ll retrieve(int idx, int QL, int QR)
	{
		// if outside
		if(t[idx].L > QR || t[idx].R < QL)
			return 0;
		// if contained
		if(t[idx].L >= QL && t[idx].R <= QR)
			return t[idx].sum;

		ll lft = retrieve(ls(idx), QL, QR);
		ll rgt = retrieve(rs(idx), QL, QR);
		// merge
		return (lft + rgt) % mod;
	}
};
// << Segment Tree



void printMt(int L, int N)
{
	for(int len = 0; len <= L; len++)
	{
		for(int dig = 0; dig <= N; dig++)
			cout << dp[len][dig] << " ";
		cout << "\n";
	}
}

void resetAll()
{
	for(int i = 0; i <= N; i++)
		for(int j = 0; j <= L; j++)
			dp[j][i] = 0;
}

int tc;

void solveFenwickTree()
{
	cin >> tc;
	while(tc--)
	{
		cin >> N >> L >> M;

		// DP
		// base
		// reset the Binary Indexed Tree
		resetAll();
		FenwickTree ft;

		for(int i = 1; i < lim; i++)
		{
			dp[1][i] = 1;
			ft.update(i, 1);
		}
		// Dynamic procedure
		for(int len = 2; len <= L; len++)
		{
			for(int dig = 1; dig <= N; dig++)
			{
				int before = max(1, dig - M);
				int after = min(N, dig + M);

				ll k = ft.retrieve(before, after);

				// updating DP
				dp[len][dig] = (dp[len][dig] + k) % mod;
			}

			// updating in the tree
			for(int dig = 1; dig <= N; dig++)
			{
				ll aux = (dp[len][dig] - dp[len - 1][dig] + mod) % mod;

				ft.update(dig, aux);
			}
		}
		cout << ft.retrieve(1, N) << endl;
	}
}

void solveSegmentTree()
{
	//cin >> tc;
	sf("%d", &tc);
	while(tc--)
	{
		//cin >> N >> L >> M;
		sf("%d%d%d", &N, &L, &M);

		// DP
		resetAll();

		SegmentTree st = SegmentTree(lim + 1);

		for(int i = 1; i < lim; i++)
		{
			dp[1][i] = 1;
			st.update(0, i, 1);
		}
		// Dynamic procedure
		for(int len = 2; len <= L; len++)
		{
			for(int dig = 1; dig <= N; dig++)
			{
				int before = max(1, dig - M);
				int after = min(N, dig + M);

				ll k = st.retrieve(0, before, after);

				// updating DP
				dp[len][dig] = (dp[len][dig] + k) % mod;
			}

			// updating in the tree
			for(int dig = 1; dig <= N; dig++)
			{
				ll aux = (dp[len][dig] - dp[len - 1][dig] + mod) % mod;

				st.update(0, dig, aux);
			}
		}
		//cout << st.retrieve(0, 1, N) << "\n";
		pf("%lld\n",st.retrieve(0, 1, N));
	}
}

void solveBrute()
{
	cin >> tc;

	while(tc--)
	{
		cin >> N >> L >> M;

		resetAll();

		// DP[i][j] = Cantidad de maneras de crear listas
		// de longitud i que terminan en j

		// base case
		for(int i = 1; i <= N; i++)
			dp[1][i] = 1;

		// Dynamic procedure
		for(int len = 2; len <= L; len++)
		{
			for(int dig = 1; dig <= N; dig++)
			{
				int before = max(1, dig - M);
				int after = min(N, dig + M);

				for(int k = before; k <= after; k++)
					dp[len][dig] = (dp[len][dig] + dp[len - 1][k]) % mod;
			}
		}

		ll answ = 0;

		for(int i = 1; i <= N; i++)
			answ = (answ + dp[L][i]) % mod;

		cout << answ << "\n";
	}
}


int main()
{
    
    //solveFenwickTree();
    solveSegmentTree();
    //solveBrute();
}
