/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3294 - Querying an array
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
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 1e5 + 2;

int N, Q, type, a, b, x;


bool isPrime(int p)
{
    if(p < 2)
        return false;
    for(int i = 2; i * i <= p; i++)
        if(p % i == 0)
            return false;
    return true;
}

int arr[lim];

// >> SEGMENT TREE
int tprime[4*lim];
int tMxNpr[4*lim];

void buildTree(int idx, int L, int R)
{
    if(L == R)
    {
        if(isPrime(arr[L]))
        {
            tprime[idx] = 1;
            tMxNpr[idx] = -1;
        }
        else
        {
            tprime[idx] = 0;
            tMxNpr[idx] = arr[L];
        }
        return;
    }

    int le = 2 * idx + 1;
    int ri = le + 1;
    int mid = (L + R) / 2;

    // build both subtrees
    buildTree(le, L, mid);
    buildTree(ri, mid + 1, R);

    // merge
    tprime[idx] = tprime[le] + tprime[ri];
    tMxNpr[idx] = max(tMxNpr[le], tMxNpr[ri]);
}

void update(int idx, int L, int R, int upd, int ii)
{
    if(L == R)
    {
        if(isPrime(upd))
        {
            tprime[idx] = 1;
            tMxNpr[idx] = -1;
        }
        else
        {
            tprime[idx] = 0;
            tMxNpr[idx] = upd;
        }
        return;
    }

    int le = 2 * idx + 1;
    int ri = le + 1;
    int mid = (L + R) / 2;

    if(ii <= mid)
        update(le, L, mid, upd, ii);
    else update(ri, mid + 1, R, upd, ii);

    // merge
    tprime[idx] = tprime[le] + tprime[ri];
    tMxNpr[idx] = max(tMxNpr[le], tMxNpr[ri]);
}


int retriveCount(int idx, int L, int R, int QL, int QR)
{
    // if countained
    if(L >= QL && R <= QR)
        return tprime[idx];
    // if outside
    if(R < QL || L > QR)
        return 0;

    int le = 2 * idx + 1;
    int ri = le + 1;
    int mid = (L + R) / 2;

    int c1 = retriveCount(le, L, mid, QL, QR);
    int c2 = retriveCount(ri, mid + 1, R, QL, QR);

    return c1 + c2;
}

int retriveMaxPrime(int idx, int L, int R, int QL, int QR)
{
    // if countained
    if(L >= QL && R <= QR)
        return tMxNpr[idx];
    // if outside
    if(R < QL || L > QR)
        return -1;

    int le = 2 * idx + 1;
    int ri = le + 1;
    int mid = (L + R) / 2;

    int c1 = retriveMaxPrime(le, L, mid, QL, QR);
    int c2 = retriveMaxPrime(ri, mid + 1, R, QL, QR);

    return max(c1, c2);
}

// << SEGMENT TREE


void solve()
{
    cin >> N >> Q;
    // reading elements
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    buildTree(0, 0, N - 1);

    // reading queries
    for(int i = 0; i < Q; i++)
    {
        cin >> type;
        if(type == 1)
        {
            cin >> a >> x;
            a--;

            update(0, 0, N - 1, x, a);
        }
        else if(type == 2)
        {
            cin >> a >> b;
            a--; b--;

            int answ = retriveCount(0, 0, N - 1, a, b);

            cout << answ << endl;
        }
        else
        {
            cin >> a >> b;
            a--; b--;

            int answ = retriveMaxPrime(0, 0, N - 1, a, b);

            if(answ == -1)
                cout << "NO ANSWER" << endl;
            else cout << answ << endl;
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
