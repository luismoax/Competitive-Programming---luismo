/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 4182 - Palindrome Pairs
	Online Judge: COJ
	Idea: Use a Map and bits manipulation. Masks will represent equivalence classes for strings. Each equivalence class will contain active the i-th bit if the i-th letter has an odd frequency
	in the string
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
const int lim = 2e5 + 2;

int N;
map<int, ll> m;
int alph[26];
string str;

bool isPowerOfTwo(int x)
{
    for(int i = 0; i < 31; i++)
        if( (1<<i) == x )
            return true;
    return false;
}

void solve()
{
    cin >> N;
    for(int t = 0; t < N; t++)
    {
        cin >> str;
		
        for(int i = 0; i < str.size(); i++)
            alph[str[i] - 'a']++;

        int mask = 0;
        for(int i = 0; i < 26; i++)
        {
			// activate the bit in the mask if there is an odd frequency of letters number i
            if(alph[i] % 2 == 1)
            {                
                mask = (mask|(1<<i));
            }
            alph[i] = 0;
        }
        m[mask]++;
    }

    ll answ = 0;

    map<int, ll>::iterator it;
    for(it = m.begin(); it != m.end(); it++)
    {
        int mask = it->first;
        ll cnt = it->second;

        answ += (cnt*(cnt-1))/2;

        for(int i = 0; i < 30; i++)
        {
            // if bit active
            if( ((1<<i)&mask) != 0)
            {
				// the result of deactivate it
                int km = mask^(1<<i);
				// checking in the map
                answ += cnt * m[km];
            }
        }
    }
	// print the answer
    cout << answ << endl;
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
	else if(fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
	}
}

int main()
{
	IO();

	fastIO();

	solve();
}
