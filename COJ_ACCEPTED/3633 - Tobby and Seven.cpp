/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem:
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

const int lim = 60 + 7;

ll N, k, x;
vector<int> pos;

int mask[lim];

int conver(ll x)
{
    int p = 0;
    while(x > 0)
    {
        if(x % 2 == 1)
            mask[p] = 1;
        x/= 2;
        p++;
    }
    return p - 1;
}

void printBinary(int lg)
{
    // printing binary rep
    for(int i = lg; i >= 0; i--)
        cout << mask[i] << " ";
    cout << "\n";
}


ll maskToInt()
{
    ll answ = 0;
    for(int i = 0; i < lim; i++)
        if(mask[i])
            answ+= (1ll << i);
    return answ;
}

ll best = 0;
void rec(int idx, int ones, ll carry)
{
    if(ones == 0)
    {
        if(carry % 7 == 0)
            best = max(best, carry);
        return;
    }

    if(idx == k)
        return;

    if(ones > 0)
    {
        mask[pos[idx]] = 1;
        rec(idx + 1, ones - 1, carry + (1ll << pos[idx]));
        mask[pos[idx]] = 0;
    }

    rec(idx + 1, ones, carry);
}

void solve()
{
    while(cin >> N)
    {
        pos.clear();

        fill(mask, mask + lim, 0);
        best = 0;
        // reading
        cin >> k;
        // reading positions
        for(int i = 0; i < k; i++)
        {
            cin >> x;
            pos.push_back(x);
        }

        int lg = conver(N);

        // printBinary(lg);
        ll aux = N;

        // checking swpped positions
        int ones = 0;
        for(int i = 0; i < k; i++)
        {
            if(mask[pos[i]] != 0)
            {
                ones++;
                aux-= (1ll << pos[i]);
            }

            // reseting for the bitMask
            mask[pos[i]] = 0;
        }
        // Bit Mask
        rec(0, ones, aux);

        cout << best << "\n";
    }
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
		// freopen("d:\\lmo.out","w",stdout);
	}
	else if(fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
	}

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
