/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 
	Link: 
	Online Judge: 
	Idea: 
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
#define M_PI 2.0 * acos(0)
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 1e5 + 3;

int data[5];
bool taken[5];
int aux[5];
bool backTrack(int idx)
{
	if(idx == 5)
	{
		int G = aux[0];
		int W = aux[1];
		int D = aux[2];
		int L = aux[3];
		int Pts = aux[4];

		if(G == (W + D + L) && Pts == (3 * W + D))
		{
			cout << G << " ";
			cout << W << " ";
			cout << D << " ";
			cout << L << " ";
			cout << Pts;
			return true;
		}

		return false;
	}

	for(int i = 0; i < 5; i++)
	{
		if(!taken[i])
		{
			taken[i] = true;
			aux[idx] = data[i];
			bool flag = backTrack(idx + 1);
			if(flag) return true;
			taken[i] = false;
		}
	}

	return false;
}

void solve()
{
	cin >> data[0];
	cin >> data[1];
	cin >> data[2];
	cin >> data[3];
	cin >> data[4];

	backTrack(0);

	cout << endl;
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