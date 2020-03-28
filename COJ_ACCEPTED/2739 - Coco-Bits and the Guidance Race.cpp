/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 2739 - Coco-Bits and the Guidance Race
    Online Judge: COJ
    Idea: Backtrack at the face
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
struct pnt
{
	int id;
	double x, y;
	pnt(){}
	pnt(int i, double xx, double yy)
	{id = i; x = xx; y = yy;}
} points[10];

bool taken[10];
int perm[10];

double best = 10e15;

int first, last;

void backtrack(int idx, double sum)
{
	if(idx == N)
	{
		if(points[perm[0]].id == first && points[perm[N - 1]].id == last)
			best = min(best, sum);
		return;
	}

	for(int i = 0; i < N; i++)
	{
		if(!taken[i])
		{
			taken[i] = true;
			perm[idx] = i;

			double k = 0;

			if(idx > 0)
			{
				pnt p = points[perm[idx - 1]];

				pnt pp = points[perm[idx]];

				k = sqrt((p.x - pp.x)*(p.x - pp.x) + (p.y - pp.y)*(p.y - pp.y));
			}

			backtrack(idx + 1, sum + k);

			taken[i] = false;
		}
	}
}

void solve()
{
	cin >> N;
	// reading points
	for(int i = 0; i < N; i++)
		cin >> points[i].id >> points[i].x >> points[i].y;
	// first and last points
	cin >> first >> last;
	// backtrack
	backtrack(0, 0);

	cout << setprecision(2) << fixed << best;
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("d:\\lmo.in","r",stdin);
	// freopen("d:\\lmo.out","w",stdout);
}

int main()
{
    // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
