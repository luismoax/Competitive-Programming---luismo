/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem:
	Online Judge:
	Idea:
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
const ll infinite = 1e18 + 3;
const int mod = 1e9 + 7;
const int lim = 2e5 + 2;

int tc, N, P, Q;

struct event
{
    int pos;
    bool open;
    int id;
    event(){}
    event(int i, int p, bool op){id = i; pos = p; open = op;}
};

bool cmp(event a, event b)
{
    if(a.pos == b.pos)
        return a.open && !b.open;
    return a.pos < b.pos;
}
vector<event> events;

vector<pii> interv;


void solve()
{
    cin >> tc;
    while(tc--)
    {
        events.clear();
        interv.clear();

        cin >> N;
        // reading intervals
        for(int i = 0; i < N; i++)
        {
            cin >> P >> Q;
            interv.push_back(make_pair(P, Q));
        }

        // sort the intervals
        sort(interv.begin(), interv.end());

        // pushing events()
        for(int i = 0; i < interv.size(); i++)
        {
            events.push_back(event(i+1, interv[i].first, true));
            events.push_back(event(i+1, interv[i].second, false));
        }

        // sort events
        sort(events.begin(), events.end(), cmp);

        int currCnt = 0;
        int finnCnt = 0;

        int answ = 0;
        // sweep line
        for(int i = 0; i < events.size(); i++)
        {
            event e = events[i];

            // if opening event
            if(e.open)
            {
                currCnt++;
            }
            else
            {
                if(e.id > finnCnt)
                {
                    finnCnt = currCnt;
                    answ++;
                }
            }
        }
        cout << answ << endl;
    }
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
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

	fastIO();

	solve();
}
