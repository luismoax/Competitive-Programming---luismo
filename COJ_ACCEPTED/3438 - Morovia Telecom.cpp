/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3438 - Morovia Telecom
	Online Judge: COJ
	Idea: ~ 2859 - Open Heart. Sort Intervals + Linear Scan
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

int N, b , f;

struct p
{
    int beg, fin;
    p(){}
    p(int b, int f){beg = b; fin = f;}
};

bool cmp(p a, p b)
{
    if(a.beg == b.beg)
        return a.fin < b.fin;
    return a.beg < b.beg;
}

vector<p> v;

void solve()
{
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> b >> f;
        v.push_back(p(b, f));
    }
	// sort em' all
    sort(v.begin(), v.end(), cmp);
	
	// to store answers (intervals)
    vector<p> answ;
	// to store formed interval at each time
    p last = v[0];

    for(int i = 1; i < v.size(); i++)
    {
        p aux = v[i];
		// if the current interval overlaps the last formed one
		// update the end if joined
        if(aux.beg - 1 <= last.fin)
            last.fin = max(aux.fin, last.fin);
        else
        {
			// store the previous formed interval
            answ.push_back(last);
			// take this as a new interval to form
            last = aux;
        }
    }
    answ.push_back(last);

	// printing answer
    cout << answ.size() << "\n";
    for(int i = 0; i < answ.size(); i++)
        cout << answ[i].beg << " " << answ[i].fin << "\n";
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
