/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Find the Running Median
	Online Judge: hackerrank.com
	Idea: Use two priority queues. See implementation for details
    Classic known technique
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
// IOn
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"

using namespace std;

typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 1e3 + 3;

int n, x;

priority_queue<int> pqLeft;
priority_queue<int> pqRight;

void solve()
{
    cin >> n;
    while(n-- > 0)
    {
        cin >> x;
        pqLeft.push(x);
        if(pqLeft.size() - pqRight.size() > 1)
        {
            
            int k = -pqLeft.top(); pqLeft.pop();
            pqRight.push(k);
        }

        if(pqLeft.size() > 0 && pqRight.size() > 0)
        {
            int topLe = pqLeft.top();
            int topRi = -pqRight.top();
            
            if(topLe > topRi)
            {
                
                pqLeft.pop();
                pqRight.pop();

                pqLeft.push(topRi);
                pqRight.push(-topLe);
            }
        }        

        double median = pqLeft.top();
        
        if( (pqLeft.size() + pqRight.size() ) % 2 == 0)
        {
            median += -pqRight.top();
            median /= 2.0;
        }    
        cout.precision(1);    
        cout << fixed << median << endl;
    }   
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	if(fopen("c:\\USERS\\LUISMO\\lmo.in","r") != NULL)
	{
		freopen("c:\\USERS\\LUISMO\\lmo.in","r",stdin);
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