/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 2666 - Maximum D-Intervals
	Online Judge: COJ
	Idea: Use the same idea of the problem Largest Rectangle In Histogram.
	For each element calculate the largest continuous subsequence to the left and the largest
	continuous subsequence to the right, such that the current element divides them all.
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

typedef pair<int, int> pii;

int K;

int arr[lim];

stack<int> stk;

int lftW[lim];
int rghW[lim];


void solve()
{
    cin >> K;
    // reading integers
    for(int i = 0; i < K; i++)
        cin >> arr[i];

    //
    for(int i = 0; i < K; i++)
    {
        while(stk.size() > 0 && arr[stk.top()] % arr[i] == 0)
            stk.pop();

        if(stk.size() == 0)
            lftW[i] = 0;
        else lftW[i] = stk.top() + 1;

        // push in the stack the current position
        stk.push(i);
    }

    // clear the stack
    while(stk.size() > 0)
        stk.pop();

    for(int i = K - 1; i >= 0; i--)
    {
        while(stk.size() > 0 && arr[stk.top()] % arr[i] == 0)
            stk.pop();

        if(stk.size() == 0)
            rghW[i] = K - 1;
        else rghW[i] = stk.top() - 1;

        // push in the stack the current position
        stk.push(i);
    }

    // finding the interval
    set<pii> rbTree;

    int mxL = 0;
    for(int i = 0; i < K; i++)
    {
        int len = rghW[i] - lftW[i] + 1;
        if(len > mxL)
        {
            rbTree.clear();
            rbTree.insert(make_pair(lftW[i], rghW[i]));
            mxL = len;
        }
        else if(len == mxL)
            rbTree.insert(make_pair(lftW[i], rghW[i]));
    }

    // print the size and the number of intervals
    cout << mxL << " " << rbTree.size() << "\n";

    for(set<pii>:: iterator i = rbTree.begin(); i != rbTree.end(); i++)
        cout << i->first + 1 << " " << i->second + 1 << "\n";


/*
    cout << "DEBUGG\n" << endl;
    for(int i = 0; i < K; i++)
        cout << lftW[i] << " " << rghW[i] << endl;
*/
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
