/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: 4293 - How many inversions?
	Online Judge: COJ
	Idea: Use Merge Sort to count inversions
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
const int lim = 2e5 + 2;

int tc;

int N;

vector<int> v;
vector<int> aux;

ll MergeSort(int le, int ri)
{
    if(le == ri)
        return 0;

    int mid = (le + ri) / 2;

    ll s1 = MergeSort(le, mid);
    ll s2 = MergeSort(mid + 1, ri);

    // merging
    aux.clear();

    ll s3 = 0;
    int idxLe = le;
    int idxRi = mid + 1;

    while(idxLe <= mid || idxRi <= ri)
    {
        //
        while(idxLe > mid && idxRi <= ri)
            aux.push_back(v[idxRi++]);

        while(idxRi > ri && idxLe <= mid)
            aux.push_back(v[idxLe++]);

        if(idxLe <= mid && idxRi <= ri)
        {
            if(v[idxLe] <= v[idxRi])
                aux.push_back(v[idxLe++]);
            else
            {
                aux.push_back(v[idxRi++]);
                s3 += mid - idxLe + 1;
            }
        }
    }

    // copyyyy
    for(int i = 0; i < aux.size(); i++)
        v[le + i] = aux[i];

    ll ret = s1 + s2 + s3;
    return ret;
}




void solve()
{
    while(cin >> N)
    {
        if(N == 0)
            return;

        v.clear();

        for(int i = 0; i < N; i++)
        {
            int x; cin >> x;
            v.push_back(x);
        }
        ll answ = MergeSort(0, N - 1);
        cout << answ << endl;
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
	else if(fopen("/media/Beijing/lmo.in","r") != NULL)
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
