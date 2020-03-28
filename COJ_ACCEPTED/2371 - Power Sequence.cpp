/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 2371 - Power Sequence
	Online Judge: COJ
	Idea: Generate all elements of the sequence, and for each query do binary search.
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
int tc, P, Q;
set<ll> elements;
vector<ll> v;

void preProcess()
{
	// generating elements and inserting them into a set (to avoid repetitions)
    int last = 31623;
    for(int i = 2; i < last; i++)
    {
        ll aux = i * i;
        while(aux <= 1000000000)
        {
            elements.insert(aux);
            aux *= i;
        }
    }
    elements.insert(1);
	// inserting the elements in a vector to do binary search
    for(set<ll>::iterator it = elements.begin(); it != elements.end(); it++)
        v.push_back(*it);
}


void solve()
{
    preProcess();

    cin >> tc;
    int cs = 1;
    while(cs <= tc)
    {
        cin >> P >> Q;
		// doing binary search
        int pos1 = lower_bound(v.begin(), v.end(), P) - v.begin();
        int pos2 = upper_bound(v.begin(), v.end(), Q) - v.begin();

        cout << "Case "<< cs << ": ";
        cout << pos2 - pos1 << "\n";
        cs++;
    }
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
