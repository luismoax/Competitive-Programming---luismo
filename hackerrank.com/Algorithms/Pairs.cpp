/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: Pairs
    Link: hackerrank.com/challenges/pairs/problem
    Online Judge: hackerrank.com
    Idea: Store each number in a Red-Black Tree and iterate over them again trying to find iff number i-k was stored in the 
    Red-Black Tree
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define x first
#define y second
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;

int n;
ll k;
set<ll> rbTree;

void solve()
{
    cin >> n >> k;
    vector<ll> vect(n);
    for(int i = 0; i < n; i++)
    {
        ll aux = 0;
        cin >> aux;
        vect[i] = aux;
        rbTree.insert(aux);
    }

    ll answ = 0;

    for(int i = 0; i < n; i++)
    {
        int targ = vect[i] - k;
        
        if(rbTree.find(targ) != rbTree.end())
            answ ++;
    }
    cout << answ;
}
 
void fastIO()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
}
 
void IO()
{

    if(fopen("c:\\Competitive Programming\\lmo.in","r") != NULL)
    {
        freopen("c:\\Competitive Programming\\lmo.in","r",stdin);
    }
    else if(fopen("d:\\lmo.in","r") != NULL)
    {
        freopen("d:\\lmo.in","r",stdin);
    }
    else if(fopen("media/Beijing/lmo.in","r") != NULL)
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