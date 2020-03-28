/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 2675 - Pair Match
	Online Judge: COJ
	Idea: Sorting Searching approach
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e6 + 7;

int N, M, D, xi;

vector<int> AA;
vector<int> BB;

void solve()
{
    cin >> N >> M >> D;
    // reading first N toys
    for(int i = 0; i < N; i++)
    {
        cin >> xi; AA.push_back(xi);
    }

    for(int i = 0; i < M; i++)
    {
        cin >> xi; BB.push_back(xi);
    }

    sort(AA.begin(), AA.end());
    sort(BB.begin(), BB.end());

    int cnt = 0;

    int idxAA = 0, idxBB = 0;
    while(idxAA < AA.size() && idxBB < BB.size())
    {
        int xa = AA[idxAA];
        int xb = BB[idxBB];

        if(abs(xa - xb) <= D)
        {
            cnt++;
            idxAA++;
            idxBB++;
        }
        else if(xa < xb)
            idxAA++;
        else idxBB++;
    }

    cout << cnt << "\n";
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
