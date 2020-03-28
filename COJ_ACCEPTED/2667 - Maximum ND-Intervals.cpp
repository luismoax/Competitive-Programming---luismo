/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 2667 - Maximum ND-Intervals
	Online Judge: COJ
	Idea: Use a Segment Tree. Build a ST storing in each node the frequency of the values from 1 -> 99 in the interval.
	When querying find if exits a value with frequency 1 such that no multiple of it occurs in the interval (the frequency)
	of each multiple of it is 0)
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e3 + 7;

int arr[lim], K;

struct node
{
	int L, R;
	int nmb[100];
	node(){}
} t[lim << 2];

inline int ls(int i){return (i << 1) + 1;}
inline int rs(int i){return (i << 1) + 2;}
inline int middle(int l, int r){ return (l + r) >> 1;}
int QL, QR;

void buildTree(int idx, int L, int R)
{
	t[idx].L = L; t[idx].R = R;
	// if leaf
	if(L == R)
	{
		t[idx].nmb[arr[L]] = 1;
		return;
	}
	int mid = middle(L, R);
	int le = ls(idx), ri = rs(idx);

	buildTree(le, L, mid);
	buildTree(ri, mid + 1, R);

	// merge
	for(int i = 0; i < 100; i++)
		t[idx].nmb[i] = t[le].nmb[i] + t[ri].nmb[i];
}

node retrieve(int idx)
{
	// if contained
	if(t[idx].L >= QL && t[idx].R <= QR)
		return t[idx];

	// if outside
	if(t[idx].L > QR || t[idx].R < QL)
	{
		node ret;
		ret.L = -1;
		ret.R = -1;
		return ret;
	}

	int le = ls(idx), ri = rs(idx);

	node left = retrieve(le);
	node right = retrieve(ri);

	// if no left
	if(left.L == -1)
		return right;

	if(right.L == -1)
		return left;

	// merge
	node ret;

	for(int i = 0; i < 100; i++)
		ret.nmb[i] = left.nmb[i] + right.nmb[i];

	return ret;
}

void solve()
{
	cin >> K;
	// reading integers
	for(int i = 0; i < K; i++)
		cin >> arr[i];

	// build the Segment Tree
	buildTree(0, 0, K - 1);

	vector<int> ini; // start points of the intervals of the solution
	int mxSz = 1; // maximum found size

	for(int i = 0; i < K; i++)
	{
		for(int j = mxSz; i + j - 1 < K; j++)
		{
			bool flag = false;
			QL = i, QR = i + j - 1;

			node q = retrieve(0);

			// for each with freq 1
			for(int f = 0; f < 100; f++)
			{
				bool works = true;
				if(q.nmb[f] == 1)
				{
					for(int kk = f + f; kk < 100; kk+= f)
						if(q.nmb[kk] > 0)
						{
							works = false;
							break;
						}
				}
				else works = false;

				if(works)
				{
					flag = true;
					break;
				}
			}
			
			// if a valid interval
			if(flag)
			{			
				if(j == mxSz)
					ini.push_back(i);
				else if(j > mxSz)
				{
					ini.clear();
					ini.push_back(i);

					mxSz = j;
				}
			}
		}
	}

	cout << mxSz << " " << ini.size() << "\n";
	for(int i = 0; i < ini.size(); i++)
		cout << ini[i] + 1 << " " << ini[i] + mxSz << "\n";
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
		freopen("d:\\lmo.in","r",stdin);

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
