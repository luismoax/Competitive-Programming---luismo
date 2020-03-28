/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1093 - Ghajini
	Online Judge: LightOJ
	Idea: Use a Segment Tree to store min and max, and do interval queries
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
const int lim = 1e5 + 7;

int n, q, a, b, c, d, type, tc;
ll v;

vector<ll> vect;
vector<ll> ccVect;
map<ll, int> ccMap; // for coordinates compression

// >> SEGMENT TREE
int QL, QR; // query bounds
ll tMin[lim * 4];
ll tMax[lim * 4];

void buildTree(int idx, int L, int R)
{
    if(L == R)
    {
        tMin[idx] = tMax[idx] = vect[L];
        return;
    }

    int le = idx*2 + 1;
    int ri = le + 1;
    int mid = (L + R) / 2;

    buildTree(le, L, mid);
    buildTree(ri, mid + 1, R);
    // merge
    tMin[idx] = min(tMin[le], tMin[ri]);
    tMax[idx] = max(tMax[le], tMax[ri]);
}

ll retrieveMin(int idx, int L, int R)
{
    if(L >= QL && R <= QR)
        return tMin[idx];
    if(L > QR || R < QL)
        return inf;

    int le = idx*2 + 1;
    int ri = le + 1;
    int mid = (L + R) / 2;

    return min(retrieveMin(le, L, mid), retrieveMin(ri, mid + 1, R));
}

ll retrieveMax(int idx, int L, int R)
{
    if(L >= QL && R <= QR)
        return tMax[idx];
    if(L > QR || R < QL)
        return -1;

    int le = idx*2 + 1;
    int ri = le + 1;
    int mid = (L + R) / 2;

    return max(retrieveMax(le, L, mid), retrieveMax(ri, mid + 1, R));
}



void solve()
{
    sf("%d", &tc);
    for(int cs = 1; cs <= tc; cs++)
    {
        sf("%d%d", &n, &d);

        vect.clear();
        // reading integers
        for(int i = 0; i < n; i++)
        {
            sf("%lld",&v);
            vect.push_back(v);
        }

        // build the Segment Tree
        buildTree(0, 0, n - 1);

        ll answ = -1;

        for(int i = 1; i < n; i++)
        {
            ll cur = vect[i];

            QR = i - 1; QL = max(0, i - d + 1);

            ll mn = retrieveMin(0, 0, n - 1);
            ll mx = retrieveMax(0, 0, n - 1);

            ll dif = max( abs(cur-mx), abs(cur-mn) );

            answ = max(dif, answ);
        }

        pf("Case %d: %lld\n", cs, answ);
    }
}

int main()
{
	solve();
}
