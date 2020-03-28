/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: 4086 - Find Palindrome Spread
	Online Judge: COJ
	Idea: Manacher + Linear Scan
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

typedef pair<int, int> pii;
const ll inf = 1e18 + 3;
const int mod = 1e9 + 7;
const int lim = 1e6 + 7;

// for the problem
int N, K;
int intervalMarks[lim];


string str;
struct manacher
{
    string s;
    int lenMan;
    char * man;
    int * table;

    // Const
    manacher(string ss)
    {
        s = ss;
        lenMan = s.size() * 2 + 2;
        man = new char[lenMan];
        table = new int[lenMan];
        // fill the manacher
        preProcess();
    }

    // mirror for index "idx" at center "center"
    int mirror(int idx, int center)
    { return (center - (idx - center)); }

    void manFill()
    {
        man[0] = '$';
        man[1] = '#';
        for(int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            man[2*i+2] = c;
            man[2*i+3] = '#';
        }
    }

    void preProcess()
    {
        // fill the manacher string
        manFill();
        // set intial values for the table
        table[0] = table[1] = 0;
        table[2] = 1;
        // set the center and its wing
        int center = 2;

        // for each character
        for(int i = 3; i < lenMan; i++)
        {
            int currWing = 0;
            // if can be calculated from its mirror
            if(i <= center + table[center])
            {
                int mirr = mirror(i, center);
                currWing = min(table[mirr], center + table[center] - i);
            }
            // update the value of the table
            table[i] = currWing;
            // while being possible to increase the lengt
            while(i + table[i] < lenMan && man[i+table[i]+1] == man[i-(table[i]+1)])
                table[i]++;

            // >> FOR THE CURRENT PROBLEM
            if(table[i] >= K)
            {
                int beg = ((i - table[i] + 1) - 2) / 2;
                int fin = ((i + table[i]) - 2) / 2;

                intervalMarks[beg]++;
                intervalMarks[fin + 1]--;
            }
            // << FOR THE CURRENT PROBLEM

            // update the center
            if(i + (table[i]) > center + table[center])
                center = i;
        }
    }
};

void solve()
{
    cin >> N >> K;
    cin >> str;

    manacher m = manacher(str);

    int answ = 0;
    int cnt = 0;
    for(int i = 0; i < str.size(); i++)
    {
        cnt+= intervalMarks[i];
        // if not in a palindrome of length >= K
        if(cnt == 0)
            answ++;
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
