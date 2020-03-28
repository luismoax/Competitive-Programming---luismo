/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3427 - Lost in the forest
	Online Judge: COJ
	Idea: Case and cases. Geometry 1
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

int N;
struct point
{
	long double x, y;
	point(long double xx, long double yy){x = xx; y = yy;}
	point(){};
};
vector <point> v;

long double slope(point & a, point & b)
{
	return (a.y - b.y) / (a.x - b.x);
}

// true -> left | false -> right
vector<bool> turns;
long double xx, yy;
void solve()
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> xx >> yy;
		point p = point(xx, yy);
		v.push_back(p);
	}

	for(int i = 0; i < N; i++)
	{
		if(i > 1)
		{
			point first = v[i - 2];
			point second = v[i - 1];
			point third = v[i];

			long double slp1 = slope(first, second);
			long double slp2 = slope(second, third);

			// if from left to right
			if(first.x < second.x)
			{
				if(second.x == third.x)
				{
					if(third.y > second.y)
						turns.push_back(true);
					else turns.push_back(false);
				}
				else
				{
					if(third.x > second.x)
					{
						if(slp2 > slp1)
							turns.push_back(true);
						else turns.push_back(false);
					}
					else
					{
						if(slp2 > slp1)
							turns.push_back(false);
						else turns.push_back(true);
					}
				}
			}
			// from right to left
			else if(first.x > second.x)
			{
				if(second.x == third.x)
				{
					if(third.y > second.y)
						turns.push_back(false);
					else turns.push_back(true);
				}
				else if(third.x < second.x)
				{
					if(slp2 > slp1)
						turns.push_back(true);
					else turns.push_back(false);
				}
				else
				{
					if(slp2 > slp1)
						turns.push_back(false);
					else turns.push_back(true);
				}
			}
			// if the same x for the first two points
			else
			{
				if(second.y > first.y)
				{
					if(third.x < second.x)
						turns.push_back(true);
					else turns.push_back(false);
				}
				else
				{
					if(third.x > second.x)
						turns.push_back(true);
					else turns.push_back(false);
				}
			}

		}
	}

	for(int i = 0; i < turns.size(); i++)
		if(turns[i]) cout << "left\n";
		else cout << "right\n";
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
		freopen("d:\\lmo.in","r",stdin);

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
