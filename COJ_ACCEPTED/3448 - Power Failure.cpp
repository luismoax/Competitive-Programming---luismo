/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3448 - Power Failure
	Online Judge: COJ
	Idea:
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e2 + 7;

int N, M, P, Q, tc;

vector<int> adj[lim];

// >> FOR AP
int level[lim];
bool ap[lim];
int totalAP;

int DFS(int idx)
{
    int ret = INFINITY;

    // JUST FOR THE ROOT
    int childs = 0;
    // for each adjacent
    for(int i = 0; i < adj[idx].size(); i++)
    {
        int nxt = adj[idx][i];

        // if the next element has not been discovered
        if(level[nxt] == -1)
        {
            childs++;

            level[nxt] = level[idx] + 1;
            //
            int k = DFS(nxt);
            // if this is an AP
            if(idx != 0 && k >= level[idx])
            {
                if(!ap[idx])
                {
                    ap[idx] = true;
                    totalAP++;
                }
            }
            //
            ret = min(ret, k);
        }
        else ret = min(ret, level[nxt]);
    }

    return ret;
}
// << FOR AP

void reset()
{
    for(int i = 0; i < lim; i++)
    {
        adj[i].clear();
        level[i] = -1;
        ap[i] = false;
    }
    totalAP = 0;
}


int cs = 1;

void solve()
{
    cin >> tc;
    while(tc--)
    {
        reset();
        cin >> N >> M;
        // reading edges
        for(int i = 0; i < M; i++)
        {
            cin >> P >> Q;
            P--; Q--;
            // setting adjacency
            adj[P].push_back(Q);
            adj[Q].push_back(P);
        }

        level[0] = 0;
        DFS(0);

        // printing answer
        cout << "Case #" << cs++ << ": " << totalAP << " ";
        // printing APs
        for(int i = 0; i < lim; i++)
            if(ap[i])
                cout << i + 1 << " ";

        cout << "\n";
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
