/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: CCC '00 S5 - Sheep and Coyotes
	Link: https://dmoj.ca/problem/ccc00s5
	Online Judge:	
	Idea: Tricky text, and difficult to understand basically what is says is:
    A sheep can be eaten if there exists at least one point on the fence 
    such that the distance from that point to this sheep to this point 
    is less than or equal to the distance from that point to any other sheep.
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
#define fi first
#define se second
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e7 + 3;
const int mod = 1e9 + 7;
const int lim = 2e5 + 2;

int n;

vector< pair<ld, ld> > sheep;

// Pythagorean Distance
ld pythagDist(pair<ld, ld> pa, pair<ld, ld> pb)
{
	ld k = (pa.fi-pb.fi) * (pa.fi-pb.fi) + (pa.se-pb.se) * (pa.se-pb.se);
	return sqrt(k);
}

void solve()
{
	cin >> n;

	sheep.resize(n, mkp(0, 0));
	for(int i = 0; i < n; i++)
	{
		cin >> sheep[i].fi >> sheep[i].se;
        // multiply by 100 each coordinate in order to avoid rounding problems
		sheep[i].fi *= 100;
		sheep[i].se *= 100;
	}

	set<pair<ld, ld> > answ;
    // for each possible point (remember coordinates are multiplied by 100)
	for(int i = 0; i < 100000; i++)
	{
		vector< pair<ld,ld> > aux;
		ld mnDist = inf;
        // find the number of sheep whose distance to point <i,0> is minimmum
		for(int j = 0; j < sheep.size(); j++)
		{
			ld auxD = pythagDist(sheep[j], mkp(i, 0));
			if(auxD == mnDist)
			{
				aux.push_back(sheep[j]);
			}
			else if(auxD < mnDist)
			{
				mnDist = auxD;
				aux.clear();
				aux.push_back(sheep[j]);
			}
		}

		for(int i = 0; i < aux.size(); i++)
			answ.insert(aux[i]);
	}
    // set precision
	cout.precision(2);
    // print answer
	for(auto item: answ)
	{
		cout << fixed << "The sheep at (" << item.fi/100.0 << ", " << item.se/100.0 << ") might be eaten.";
		cout << endl;
	}

}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	if(fopen("c:\\Users\\LUISMO\\lmo.in","r") != NULL)
	{
		freopen("c:\\Users\\LUISMO\\lmo.in","r",stdin);
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
