/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3379 - I Don't Want Strawberry
	Online Judge: COJ
	Idea: Follow the procedure described here, whenever a person is served:
	a) if from the special queue -> check in the Fenwick Tree how many have been served with a greater index.
	b) not from the special queue -> update its value on the Fenwick Tree,
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
string que;
string ice;

// >> FENWICK TREE
int tree[lim];
inline int lowBit(int i){return i & -i;}

void update(int idx)
{
    for(int i = idx; i < lim; i+= lowBit(i))
        tree[i]++;
}

int retrieve(int idx)
{
    int sum = 0;
    for(int i = idx; i > 0; i-= lowBit(i))
        sum+= tree[i];
    return sum;
}

int retrieve(int L, int R)
{
    if(L > R) swap(L, R);
    return retrieve(R) - retrieve(L - 1);
}

// << FENWICK TREE


vector<int> special;
vector<int> specialOriPos;
int spIdx = 0;
int qIdx = 0;
int iceIdx = 0;

// to store answers
int answ[lim];

void solve()
{
    cin >> N >> que >> ice;
    reverse(que.begin(), que.end());
    reverse(ice.begin(), ice.end());

    while(iceIdx < ice.length())
    {
        // serve the special queue
        while(spIdx < special.size() && special[spIdx] == (ice[iceIdx] - '0'))
        {
            int pos = specialOriPos[spIdx];

            answ[pos] = retrieve(pos, lim - 1);

            spIdx++;
            iceIdx++;
        }

        // while can't serve the current element
        while(qIdx < N && que[qIdx] != ice[iceIdx])
        {
            special.push_back(que[qIdx] - '0');
            specialOriPos.push_back(qIdx + 1);
            qIdx++;
        }

        // i can serve the current
        answ[qIdx + 1] = 0;
        update(qIdx + 1);
        qIdx++;
        iceIdx++;
    }

    // printing the answer
    for(int i = 1; i <= N; i++)
        cout << answ[i] << "\n";
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
