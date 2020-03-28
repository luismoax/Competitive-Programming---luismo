/*
    Author: Luis Manuel Díaz Barón
    Problem: 2877 - Adriana the Tigress
    Online Judge: COJ
    Idea: Greedy, sort words by lenght and whenever a word fits a hole, set it and process the next word

*/
#include <iostream>
#include <cstdio>
// Containers
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
// Algorithm
#include <algorithm>
#include <cstring>
#include <cmath>
// Constants
#define MAXN 1000001
#define MOD 1000000007
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define nint(i) sf("%d",&i);
#define nlong(i) sf("%lld",&i);

using namespace std;


void open_file()
{
    // freopen("d:\\lmo.in","r",stdin);
}

const int MAXL = 1e4 + 1;
const int MAXW = 1e4 + 2;


char str[MAXL]; // text
char L;
int V,W;

// char words[MAXW][MAXW]; // store word
char word[MAXW];

//>>>>>>>>>
int holes[10001], h_idx = 0;
int taken[10001]; // taken holes
int words[10001], w_idx = 0;
//>>>>>>>>>

void solve()
{
    h_idx = w_idx = 0;
    memset(holes, 0, sizeof holes);
    memset(taken, 0, sizeof taken);
    memset(words, 0, sizeof words);

    sf("%s",&str); // reading TEXT
    sf("%c",&L); // reading endl

    sf("%c%d",&L, &V);
    sf("%d",&W);

    // reading words
    for(int i =0; i < W; i++)
    {
        sf("%s",word);
        words[w_idx++] = strlen(word);
    }

    // processing the holes
    int len = strlen(str);
    int w_len = 0;
    int anger = 0;
    // finding holes and its lenght
    for(int i = 0; i < len + 1; i++)
    {
        if(i < len && str[i] == L)
            w_len++;
        else if(w_len > 0)
        {
            holes[h_idx++] = w_len;

            anger += w_len * V;
            w_len = 0;
        }
    }

    // sorting the words by length
    sort(words, words + w_idx);

    int nw_anger = anger;

    // taking the words in increadising order
    for(int i = w_idx - 1; i >= 0; i--)
    {
        for(int j =0; j < h_idx; j++)
        {
            if(!taken[j] && holes[j] >= words[i])
            {
                taken[j] = true;
                nw_anger -= words[i] * V;
                break;
            }
        }
    }

    pf("%d\n",nw_anger);
}

int main()
{
    // open_file();

    solve();
}
