/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1971 - Islands
	Online Judge:
	Idea: Custom Segment Tree. For each different height store the indexes where it appears. In the Segment Tree each node stores the number of islands in the interval it represents.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e5 + 3;

int N;
int arr[lim];
int arrAux[lim];
// 
map<int, vector<int> > m;

// >> SEGMENT TREE
int t[lim << 2];
inline int ls(int i){return (i << 1) + 1;}
inline int rs(int i){return (i << 1) + 2;}
inline int mp(int L, int R) {return (L + R) >> 1;}

void merge(int idx, int L, int R)
{
    int le = ls(idx), ri = rs(idx), mid = mp(L, R);
	// the number of islands of this node is the numbers in the left child and 
    t[idx] = t[le] + t[ri];
	// if the heights in the middle match they should count as a single island
    if(arrAux[mid] == arrAux[mid + 1] && arrAux[mid] == 1)
        t[idx]--;
}

// build the Segment Tree initially there is only one island
void build(int idx, int L, int R)
{
    int le = ls(idx), ri = rs(idx), mid = mp(L, R);
    t[idx] = 1;
    if(L == R)
    {
        arrAux[L] = 1;
        return;
    }
    build(le, L, mid);
    build(ri, mid + 1, R);
}

// update "sink"
void update(int idx, int L, int R, int ii)
{
    int le = ls(idx), ri = rs(idx), mid = mp(L, R);
    if(L == R)
    {
        t[idx] = 0;
        arrAux[L] = 0;
        return;
    }
	// if to the left
    if(ii <= mid)
        update(le, L, mid, ii);
    else update(ri, mid + 1, R, ii);
    // merge
    merge(idx, L, R);
}

int retrive()
{
    return t[0];
}
// << SEGMENT TREE

void solve()
{
    cin >> N;
    // reading heights
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
        m[arr[i]].push_back(i);
    }

    // build the Segment Tree
    build(0, 0, N - 1);

    int answ = 1;

    // for each
    map<int, vector<int> >:: iterator it;
    for(it = m.begin(); it != m.end(); it++)
    {
        // for each position in IT
        for(int i = 0; i < it->second.size(); i++)
        {
            int idx = it->second[i];

            // update
            update(0, 0, N - 1, idx);
        }
        // take current amount of islands
        int k = retrive();
        // update answer
        answ = max(answ, k);
    }
    // print final answer
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
