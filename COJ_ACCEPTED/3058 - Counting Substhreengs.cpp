/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3058 - Counting Substhreengs
	Online Judge: COJ
	Idea: Easy DP.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define x first
#define y second
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 1e6 + 2;


string str;

// final answer
ll answ = 0;
// to keep track of the number of solutions per index
ll dp[lim];
// to keep the amount of remainders
int rm[3];

void DynamicProgramming(int le, int ri)
{
    rm[0] = 1;
    rm[1] = 0;
    rm[2] = 0;

    int sum = 0;
    for(int i = le; i <= ri; i++)
    {
        sum += str[i] -'0';
        sum%=3;

        dp[i] += rm[sum];
        rm[sum]++;
    }
}

bool isDig(char c)
{
    return c - '0' <= 9 && c - '0' >= 0;
}

void solve()
{
    cin >> str;

    int be = 0;
    int en = 0;

    for(int i = 0; i < str.size(); i++)
    {
        if(isDig(str[i]))
        {
            be = i;
            en = i;

            while(en < str.size() && isDig(str[en]))
                en++;

            DynamicProgramming(be, en - 1);

            i = en - 1;
        }
    }

    for(int i = 0; i < str.size(); i++)    
        answ += dp[i];    
	// print the answer
    cout << answ << endl;
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
