/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 2897 - GCD and Longest Subsequence II
	Online Judge: COJ
	Idea: Bitmask
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
const ll inf = 1e18 + 3;
const int mod = 1e9 + 7;
const int lim = 2e5 + 7;

int N, x;

int freq[30];
vector<int> vect;

// mask for each element
// (active bits are the indexes of the coprimes with current element)
int adj[30];

string toBinary(int x)
{
    string ret = "";
    int k = x;
    while(k > 0)
    {
        ret = (char)('0' + (k%2)) + ret;
        k/=2;
    }
    return ret;
}

void solve()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> x;
        freq[x]++;
    }

    for(int i = 1; i <= 25; i++)
        if(freq[i] != 0)
            vect.push_back(i);

    // setting adjacency
    for(int i = 0; i < vect.size(); i++)
    {
        adj[i] |= (1<<i);
        for(int j = 0; j < vect.size(); j++)
        {
            int xi = vect[i];
            int xj = vect[j];
            if(__gcd(xi, xj) == 1)
            {
                adj[i] |= (1 << j);
            }
        }
    }

    int sz = vect.size();
    // answer
    int answ = 1;
    for(int mask = 0; mask < (1 << sz); mask++)
    {
        int cnt = 0;
        for(int i = 0; i < sz; i++)
        {
            // if active
            if( ((1<<i)&mask) != 0 )
            {
                // if this mask suits on i-th element
                if((adj[i]&mask) == mask)
                {
                    cnt++;
                }
                else
                {
                    cnt = -1;
                    break;
                }
            }
        }
        // if this is a possible answer, update
        if(cnt != -1)
        {
            if(cnt > answ)
            {
                answ = cnt;
            }
        }
    }

    // add the ones
    if(freq[1] > 0)
       answ = (answ + freq[1] - 1);

    cout << answ;
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
