/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 2000 - Overplanting II
	Online Judge: COJ
	Idea: Sweep Line. 
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
int N;
int X1, Y1, X2, Y2;

struct event
{
    bool open;
    int X, beg, fin;
    event(){}
    event(int x, int yy1, int yy2, bool op)
    {X = x; beg = yy1; fin = yy2; open = op;}
};

bool cmp(event a, event b)
{
    if(a.X == b.X)
    {
        if(a.beg == b.beg)
            return a.fin < b.fin;
        return a.beg < b.beg;
    }
    return a.X < b.X;
}
vector<event> events;

// for Linear Scan
set< pair<int, int> > rbTree;

// Linear Scan to find the total vertical values covered
ll horizontalSweep()
{
    set< pair<int, int> > :: iterator it;
    // to return
    ll sum = 0;
    int beg = -1000000000, fin = -1000000000;
    for(it = rbTree.begin(); it != rbTree.end(); it++)
    {
        int b = it->first;
        int f = it->second;

        if(b <= fin)
            fin = max(f, fin);
        else
        {
            if(beg != -1000000000)
                sum += fin - beg;

            beg = b;
            fin = f;
        }
    }
    sum+= (fin - beg);
    return sum;
}

void printAllEvents()
{
    for(int i = 0; i < events.size(); i++)
    {
        cout << "X:" << events[i].X << " b:" << events[i].beg << " f:" << events[i].fin;
        cout << "\n";
    }
}

void solve()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> X1 >> Y1 >> X2 >> Y2;
        events.push_back( event(X1, Y2, Y1, true) );
        events.push_back( event(X2, Y2, Y1, false) );
    }
    // sort events by X
    sort(events.begin(), events.end(), cmp);

    // final answer
    ll answ = 0;
    // auxiliar for X
    int aux = -1;
    // for each event
    for(int i = 0; i < events.size(); i++)
    {
        // current event
        event e = events[i];

        // horizontal sweep line
        ll sum = horizontalSweep();

        // update the answer (if not the first rectangle)
        if(aux != -1)
            answ += (e.X - aux) * sum;

        // update the last X
        aux = e.X;
        // if an opening event
        if(e.open)
            rbTree.insert( make_pair(e.beg, e.fin) );
        else
            rbTree.erase( make_pair(e.beg, e.fin) );

    }
	// print the answer
    cout << answ;
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
