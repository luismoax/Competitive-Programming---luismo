/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: 3636 - Tobby Bones
	Online Judge: COJ
	Idea: Use SQRT Decomposition.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 6e5 + 7;

int N, Q, type, a, b, upd;
int infinite = 7e6;

int arr[lim]; // array of values
vector<int> decomp[1000];

int blockLen;
int blocks;

void toDecompose()
{
    blockLen = floor(sqrt(N));
    blocks = blockLen;

    if(floor( sqrt(N) ) != ceil( sqrt(N) ))
        blocks++;

	fill(arr, arr + N, infinite);
		
    for(int b = 0; b < blocks; b++)
    {
        // first clear the block
        decomp[b].clear();

        int ini = b * blockLen;
        int fin = min(ini + blockLen, N);
        // for each valid index in the block
        for(int i = ini; i < fin; i++)
            decomp[b].push_back(arr[i]);
    }
}

int query(int QL, int QR, int x)
{
    int iniBlock = QL / blockLen; // initial block
    int finBlock = QR / blockLen; // ending block

    int answ = 0;
    // for each intermediate block
    for(int b = iniBlock + 1; b < finBlock; b++)
    {
        int k = upper_bound(decomp[b].begin(), decomp[b].end(), x) - decomp[b].begin();
        answ += k;
    }

    // for the initial block
    int bound = min(iniBlock * blockLen + blockLen, QR + 1);
    for(int i = QL; i < bound; i++)
        if(arr[i] <= x)
            answ++;
    if(iniBlock != finBlock)
    {
        bound = max(QL, finBlock * blockLen);
        for(int i = QR; i >= bound; i--)
            if(arr[i] <= x)
                answ++;
    }
    return answ;
}

void update(int idx, int upd)
{
    int b = idx / blockLen;
    arr[idx] = upd;
    int fin = min(b * blockLen + blockLen, N);
    decomp[b].clear();
    for(int i = b * blockLen; i < fin; i++)
        decomp[b].push_back(arr[i]);
    // sort values in the block
    sort(decomp[b].begin(), decomp[b].end());
}

void printBlocks()
{
    for(int b = 0; b < blocks; b++)
    {
        for(int i = 0; i < decomp[b].size(); i++)
            cout << decomp[b][i] << " ";
        if(b < blocks - 1) cout << " --- ";
    }
    cout << endl;
}

void solve()
{
    while(cin >> N >> Q)
    {        
        toDecompose();
        // reading queries
        for(int i = 0; i < Q; i++)
        {
            // printBlocks();

            cin >> type >> a >> b;
            if(type == 0)
            {
                update(a, b);
            }
            else
            {
                cin >> upd;
                int answ = query(a, b, upd);

                cout << answ << "\n";
            }
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
