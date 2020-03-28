/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1014 - Ifter Party
	Online Judge: LightOj
	Idea:
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

int tc;
ll P, L;
vector<int> v;

void solve()
{
    int cs = 1;
    cin >> tc;
    while(tc-- > 0)
    {
        cin >> P >> L;
        ll r = P - L;

        v.clear();

        for(ll i = 1; i * i <= r; i++)
        {
            if(r % i == 0)
            {
                if(i > L)
                    v.push_back(i);
                if(i != r / i && r / i > L)
                    v.push_back(r / i);
            }
        }
        sort(v.begin(), v.end());
        cout << "Case " << cs++ << ": ";
        if(v.size() == 0)
            cout << "impossible" << endl;
        else
        {
            for(int i = 0; i < v.size(); i++)
            {
                if(i > 0)
                    cout << " ";
                cout << v[i];
            }
            cout << endl;
        }
    }
}



int main()
{

	solve();
}
