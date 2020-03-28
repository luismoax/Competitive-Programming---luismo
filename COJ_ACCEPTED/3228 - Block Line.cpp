/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3228 - Block Line
	Online Judge: COJ
	Idea: SQRT Descomposition. Beautiful.
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

int N, Q;
ll a, b, c;
char cc;
ll arr[lim];

vector<ll> decomp[lim]; // SQR Descomposition

int len, blocks;
void toDecompose()
{
    len = floor(sqrt(N));
    blocks = len;

    if(ceil(sqrt(N)) != floor(sqrt(N)))
        blocks++;

    for(int b = 0; b < blocks; b++)
    {
        int sta = b * len; // start
        int fin = sta + len - 1; // finnish
        // in case is the last block and has less than len elements
        fin = min(fin, N - 1);

        for(int i = sta; i <= fin; i++)
            decomp[b].push_back(arr[i]);

        // sort the block
        sort(decomp[b].begin(), decomp[b].end());
    }
}

int query(int QL, int QR, ll x)
{
    int blToStart = QL / len;
    int blToFin = QR / len;

    int answ = 0;
    // for each intermediate block
    for(int i = blToStart + 1; i < blToFin; i++)
    {
        int idx = upper_bound(decomp[i].begin(), decomp[i].end(), x) - decomp[i].begin();
        answ+= idx;
    }

    int bound = (blToStart * len) + len;
	bound = min(bound, QR + 1);
    for(int i = QL; i < bound; i++)
        if(arr[i] <= x) answ++;

    if(blToFin != blToStart)
    {
        bound = blToFin * len;
		bound = max(bound, QL);
        for(int i = QR; i >= bound; i--)
            if(arr[i] <= x) answ++;
    }
    return answ;
}

void update(int idx, ll upd)
{
    arr[idx] = upd;
    int b = idx / len;

    int sta = b * len;
    int fin = sta + len - 1;
    // in case is the last block and has less than len elements
    fin = min(fin, N - 1);

    decomp[b].clear();

    for(int i = sta; i <= fin; i++)
        decomp[b].push_back(arr[i]);
    // sort em all
    sort(decomp[b].begin(), decomp[b].end());
}

void solve()
{
    cin >> N >> Q;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    toDecompose(); // like Cannibal Corpse

    for(int i = 0; i < Q; i++)
    {
        cin >> cc;
        if(cc == 'Q')
        {
            cin >> a >> b >> c;
            a--; b--;

            if(a > b)
                swap(a, b);

            int answ = query(a, b, c);

            cout << answ << "\n";
        }
        else
        {
            cin >> a >> b;
            a--;
            update(a, b);
        }
    }
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
