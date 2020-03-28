/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3283 - Alice and Array in Flames
    Online Judge: COJ
    Idea: Segment Tree
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e5;
int N, Q, a, b, c;
int arr[lim];

// >> Segment Tree
struct node
{
	int L, R;

	/*
	 * 0 - mess
	 * 1 - non decreasing
	 * 2 - strictly increasing
	 */
	int value;

	node(){}
} t[lim << 2];

inline int ls(int idx){return  (idx << 1) + 1;}
inline int rs(int idx){return  (idx << 1) + 2;}

// merges in a node
void merge(int idx)
{
	int mid = (t[idx].L + t[idx].R) >> 1;
	// if both subtrees are STRICTLY INCREASING
	// and joining them it stills STRICTLY INCREASING
	if(t[ls(idx)].value == 2 && t[rs(idx)].value == 2 && arr[mid] < arr[mid + 1])
		t[idx].value = 2;
	// if cannot be strictly increasing and can be non-decreasing
	else if(t[ls(idx)].value > 0 && t[rs(idx)].value > 0 && arr[mid] <= arr[mid + 1])
		t[idx].value = 1;
	else t[idx].value = 0;
}

void buildTree(int idx, int L, int R)
{
	t[idx].L = L; t[idx].R = R;
	// if leaf
	if(L == R)
	{
		t[idx].value = 2;
		return;
	}
	int mid = (L + R) >> 1;
	buildTree(ls(idx), L, mid);
	buildTree(rs(idx), mid + 1, R);

	// merge
	merge(idx);
}

void update(int idx, int ii, int upd)
{
	// if leaf node
	if(t[idx].L == t[idx].R)
	{
		// update the value in the array
		arr[t[idx].L] = upd;
		return;
	}
	int mid = (t[idx].L + t[idx].R) >> 1;

	if(ii <= mid)
		update(ls(idx), ii, upd);
	else update(rs(idx), ii, upd);

	// merge the solution
	merge(idx);
}

int retrieve(int idx, int QL, int QR)
{
	// if contained into the Query Interval
	if(t[idx].L >= QL && t[idx].R <= QR)
		return t[idx].value;

	// if not contained (treat SPECIALLY)
	if(t[idx].L > QR || t[idx].R < QL)
		return -1;

	int left = retrieve(ls(idx), QL, QR);
	int right = retrieve(rs(idx), QL, QR);

	// merging solution

	// if the LEFT node was not included into the interval
	if(left == -1)
		return right;
	// if the RIGHT node was not included into the interval
	if(right == -1)
		return left;
	// midpoint of the node
	int mid = (t[idx].L + t[idx].R) >> 1;

	if(left == 2 && right == 2 && arr[mid] < arr[mid + 1])
		return 2;
	else if(left > 0 && right > 0 && arr[mid] <= arr[mid + 1])
		return 1;
	return 0;
}

// << Segment Tree



void solve()
{
	cin >> N >> Q;
	// reading integers
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	// build the segment tree
	buildTree(0, 0, N - 1);

	// reading queries
	for(int i = 0; i < Q; i++)
	{
		cin >> a >> b >> c;
		if(a == 1)
		{
			b--;
			update(0, b, c);
		}
		else
		{
			b--; c--;
			int aux = retrieve(0, b, c);

			if(aux == 0)
				cout << "0\n";
			else if(aux == 1)
				cout << "1\n";
			// strictly increasing
			else if(aux == 2)
				cout << "2\n";

			else cout << "Errors on the way my friend\n";
		}
	}
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	// freopen("d:\\lmo.in","r",stdin);
	// freopen("d:\\lmo.out","w",stdout);

}

int main()
{
   // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
