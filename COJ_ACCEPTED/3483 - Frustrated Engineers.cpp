/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3483 - Frustrated Engineers
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

const int lim = 1e5 + 7;
const int mod = 1e9 + 7;

int N, K, ai, bi;

int answ = 0;

// grapah
vector<int> adj[lim];

int bits[30]; // for bit Mask

bool visited[30]; // for DFS
int DFS(int idx)
{
	int ret = 0;
	visited[idx] = true;
	for(int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i];
		// if not visited and is not marked int the bit array
		if(!visited[nxt] && bits[nxt] == false)
		{
			int k = DFS(nxt);
			ret += k;
		}
	}
	return ret + 1;
}



void bitMask(int idx, int taken)
{
	// base case
	if(taken == K)
	{
		fill(visited, visited + 25, false); // reset the visited array
		// run a DFS from the last taken
		int cc = -1;
		for(int i = 0; i < N; i++)
		if(!bits[i])
		{
			cc = DFS(i);
			break;
		}
		// if CC == N - taken: is a valid way
		if(cc == N - taken)
		{
			answ = (answ + 1) % mod;
			/*
			// DEBUG
			for(int i = 0; i < N; i++)
			{
				if(bits[i])
					cout << i+1 <<" ";
			}
			cout << "\n";
			*/
		}

		return;
	}
	//
	if(idx == N)
	{
		return;
	}

	// take it
	bits[idx] = 1;
	bitMask(idx + 1, taken + 1);
	// unmark
	bits[idx] = 0;
	bitMask(idx + 1, taken);
}

void solve()
{
	//cin >> N >> K;
	sf("%d%d", &N, &K);
	// reading graph
	for(int i = 0; i < N - 1; i++)
	{
		//		cin >> ai >> bi;
		sf("%d%d", &ai, &bi);
		ai--; bi--;

		// add adjacency
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}

	answ = 0;
	// bit mask
	bitMask(0, 0);

	//cout << answ << "\n";
	pf("%d\n", answ);
}


int main()
{
	solve();
}

