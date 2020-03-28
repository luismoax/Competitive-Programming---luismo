/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3334 - Dr. B - Tree I
    Online Judge: COJ
    Idea: Easy greedy
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

string P, S;
int N, L;

void solve()
{
	cin >> N >> S >> L >> P;

	int idx = 0;
	int cnt = 0;
	for(int i = 0; i < N; i++)
	{
		if(S[i] == P[idx])
		{
			if(idx == L - 1)
				cnt++;

			idx++; idx %= L;
		}
	}
	if(cnt == 0)
		cout << -1;
	else cout << N - (L * cnt);
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("d:\\lmo.in","r",stdin);
	// freopen("d:\\lmo.out","w",stdout);
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
