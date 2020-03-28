/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3948 - Range queries
	Online Judge: COJ
	Idea: SQRT Decomposition
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

int N, Q, a, b, lwr, upr, type;
ll v;

ll arr[lim];

// >> SQRT Decomposition

vector<ll> decomp[1000];
int blockLen;
int blocksCount;

void toDecompose()
{
    blockLen = floor(sqrt(N));
    blocksCount = blockLen;

    if(floor(sqrt(N)) != ceil(sqrt(N)))
        blocksCount++;

    // for each block
    for(int b = 0; b < blocksCount; b++)
    {
        int ini = b * blockLen;

        // copying data
        for(int i = 0; i < blockLen; i++)
        {
            // if in the range, insert the value
            if(i + ini < N)
                decomp[b].push_back(arr[i + ini]);
        }

        // sort this block
        sort(decomp[b].begin(), decomp[b].end());
    }
}

void update(int pos, ll upd)
{
    // finding the number of the block
    int b = pos / blockLen;

    // update in the array
    arr[pos] = upd;

    // erase the whole block
    decomp[b].clear();

    // copy the whole block again (already updated)
    int ini = b * blockLen;

    for(int i = 0; i < blockLen; i++)
        decomp[b].push_back(arr[ini + i]);
    // sort the block again
    sort(decomp[b].begin(), decomp[b].end());
}


int retrieve(int QL, int QR, int lwr, int upr)
{
    // answer
    int answ = 0;


    int bini = QL / blockLen; // initial block
    int bend = QR / blockLen; // final block

    // for each inner block calculate
    // (since they are ordered and fully contained in the query interval)
    for(int i = bini + 1; i < bend; i++)
    {
        int p1 = lower_bound(decomp[i].begin(), decomp[i].end(), lwr)
                    - decomp[i].begin();
        int p2 = upper_bound(decomp[i].begin(), decomp[i].end(), upr)
                    - decomp[i].begin();
        // update answer
        answ += p2 - p1;
    }

    // if they are in the same block
    if(bini == bend)
    {
        for(int i = QL; i <= QR; i++)
            if(arr[i] >= lwr && arr[i] <= upr)
                answ++;
    }
    // other wise
    else
    {
        // for the initial block (in the original array)
        for(int i = QL; i < (bini + 1) * blockLen; i++)
            if(arr[i] >= lwr && arr[i] <= upr)
                answ++;

        // for the last block (in the original array)
        for(int i = QR; i >= bend * blockLen; i--)
            if(arr[i] >= lwr && arr[i] <= upr)
                answ++;
    }
    // return the answer
    return answ;
}


void printSQRTDecomposition()
{
    cout << "bc "<< blocksCount << endl;
    for(int i = 0; i < blocksCount; i++)
    {
        for(int j = 0; j < decomp[i].size(); j++)
            cout << decomp[i][j] << " ";
        cout << "\n";
    }
}
// << SQRT Decomposition


void solve()
{
    cin >> N >> Q;
    // reading integers
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    toDecompose();

    // printSQRTDecomposition();

    // for each  query
    for(int i = 0; i < Q; i++)
    {
        cin >> type;
        if(type == 1)
        {
            cin >> a >> b >> lwr >> upr;
            a--; b--;
            int answ = retrieve(a, b, lwr, upr);
            cout << answ << "\n";
        }
        else
        {
            cin >> a >> v;
            a--;
            update(a, v);
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
