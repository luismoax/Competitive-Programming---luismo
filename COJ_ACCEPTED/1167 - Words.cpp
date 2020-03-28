/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1167 - Words
	Online Judge: COJ
	Idea: DP + Bitmask. Recurrece. dp[idx][mask] is the greatest chain I can form using the active bits in "mask", and starting at "idx"
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

typedef pair<int, int> pii;
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 17;

int N, M, tc;
string str;

vector<string> words;
int szs[lim];

int dp[lim][1<<lim];
int mark[lim][1<<lim];

int DynamicProgramming(int idx, int mask, int tm)
{
	// if current state has been processed
    if(mark[idx][mask] == tm)
        return dp[idx][mask];

    int answ = 0;

    for(int i = 0; i < words.size(); i++)
    {
        if(i != idx && ((1<<i)&mask) == 0)
        {
            if(words[i][szs[i]-1] == words[idx][0])
            {
                int k = DynamicProgramming(i, mask|(1<<i), tm);
                answ = max(answ, k);
            }
        }
    }
    answ += szs[idx];
    dp[idx][mask] = answ;
    mark[idx][mask] = tm;

    return dp[idx][mask];
}


void solve()
{
    cin >> tc;
    int tm = 0;
    while(tc-- > 0)
    {
        words.clear();
        // reading words
        cin >> M;
        for(int i = 0; i < M; i++)
        {
            cin >> str;
            words.push_back(str);
            szs[i] = str.size();
        }
		
        int answ = 0;
        // perform DP
        for(int i = 0; i < M; i++)
        {
            int k = DynamicProgramming(i, (1<<i), ++tm);
            answ = max(answ, k);
        }
        cout << answ << "\n";
    }
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
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

	fastIO();

	solve();
}
