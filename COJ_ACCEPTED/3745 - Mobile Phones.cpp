/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3745 - Mobile Phones
	Online Judge: COJ
	Idea: Basic use of a Fenwick Tree 2D
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1200 + 3;

int type, X, Y, A, L, B, R, T;


// >> BIT 2D
inline int lowBit(int i){return i & -i;}

ll bit2D[lim][lim];

void update(int row, int col, ll upd)
{
    for(int r = row; r < lim; r+= lowBit(r))
    {
        for(int c = col; c < lim; c+= lowBit(c))
            bit2D[r][c]+= upd;
    }
}

ll retrieve(int row, int col)
{
    ll sum = 0;
    for(int r = row; r > 0; r-= lowBit(r))
    {
        for(int c = col; c > 0; c-= lowBit(c))
            sum += bit2D[r][c];
    }
    return sum;
}

ll retriveQuad(int row1, int col1, int row2, int col2)
{
    ll c1 = retrieve(row2, col2);

    ll c2 = retrieve(row1 - 1, col2);
    ll c3 = retrieve(row2, col1 - 1);

    ll c4 = retrieve(row1 - 1, col1 - 1);

    return c1 - (c2 + c3) + c4;
}
// << BIT 2D


void solve()
{
    cin >> type >> type;
    // reading instructions
    type = -1;
    while(type != 3)
    {
        cin >> type;
        //
        if(type == 1)
        {
            cin >> X >> Y >> A;
            X++; Y++;
            update(X, Y, A);
        }
        else if(type == 2)
        {
            cin >> L >> B >> R >> T;
            L++; B++; R++; T++;
            ll answ = retriveQuad(L, B, R, T);

            cout << answ << "\n";
        }
        else break;
    }
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
