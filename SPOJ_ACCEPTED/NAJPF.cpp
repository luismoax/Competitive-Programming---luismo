/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: NAJPF
	Online Judge: SPOJ
	Idea: Simple use of KMP
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
const int lim = 1e6 + 2;

int tc;

string text, pattern;
int pi[lim];
vector<int> shifts;

void buildPrefix()
{
    for(int i = 0; i < pattern.size(); i++)
        pi[i] = 0;
    int cnt = 0; // matched
    for(int i = 1; i < pattern.size(); i++)
    {
        while(cnt > 0 && pattern[i] != pattern[cnt])
            cnt = pi[cnt-1];
        if(pattern[i] == pattern[cnt])
        {
            cnt++;
            pi[i] = cnt;
        }
    }
}



vector<int> findShifts()
{
    shifts.clear();

    int cnt = 0;
    for(int i = 0; i < text.size(); i++)
    {
        while(cnt > 0 && text[i] != pattern[cnt])
            cnt = pi[cnt - 1];

        if(text[i] == pattern[cnt])
        {
            cnt++;
            if(cnt == pattern.size())
            {
                shifts.push_back(i-pattern.size()+1);
                cnt = pi[cnt];
            }
        }
    }
    return shifts;
}

// << KMP

void solve()
{
    cin >> tc;
    while(tc-- > 0)
    {
        cin >> text >> pattern;
        buildPrefix();
        vector<int> answ = findShifts();

        if(answ.size() > 0)
        {
            cout << answ.size() << endl;
            for(int i = 0; i < answ.size(); i++)
                cout << answ[i] + 1 << " ";
        }
        else cout << "Not Found";

        cout << endl << endl;
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