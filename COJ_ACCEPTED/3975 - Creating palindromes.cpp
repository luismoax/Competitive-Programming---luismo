/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3975 - Creating palindromes
	Online Judge: COJ
	Idea: DP.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e3 + 7;

string str;

// Palin[i][j], says whether the substring starting in i with length j is palindrome
bool palin[lim][lim];

void preProcess()
{
    for(int i = 0; i < lim; i++)
        palin[i][1] = palin[i][0] = 1;
    // for each possible size
    for(int j = 2; j < lim; j++)
    {
        for(int i = 0; i + j - 1 < lim; i++)
            if(str[i] == str[i + j - 1] && palin[i + 1][j - 2])
                palin[i][j] = true;
    }
}


// dp[i][j] - stores the minimmum amount of steps tu turn substring from i to j into a palindrome
int dp[lim][lim];

int DP(int beg, int fin)
{
    // base if is a palindrome
    if(palin[beg][fin - beg + 1])
    {
		// number of stepes to turn into a palindrome -> ZERO
        dp[beg][fin] = 0;
        return 0;
    }
    // if dp[beg][fin] already calculated -> RETURN IT
    if(dp[beg][fin] >= 0)
        return dp[beg][fin];
	// if both endpoints of the substring are equal, return the solution for the string not
	// containing the endpoints (because after "adding them back" it will be palindrome as well)
    if(str[beg] == str[fin])
        return DP(beg + 1, fin - 1);

	// solve when taken away the left endpoint
    int s1 = DP(beg + 1, fin);
	// solve when taken away the right endpoint
    int s2 = DP(beg, fin - 1);


    int answ = 1 + min(s1, s2);

    dp[beg][fin] = answ;
	// return answer
    return answ;
}


void solve()
{
    cin >> str;

	// initialize dp matrix
    for(int i = 0; i < lim; i++)
        for(int j = 0; j < lim; j++)
            dp[i][j] = -1;

    preProcess();

    int answ = DP(0, str.size() - 1);

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
