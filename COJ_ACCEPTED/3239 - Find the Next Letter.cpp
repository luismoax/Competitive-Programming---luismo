// Author: LUISMO
// Problem: 3239 - Find the Next Letter
// Linear Scan, using a stack

#include<bits/stdc++.h>

using namespace std;

int tc, N;
string str;

struct p
{
    int pos;
    char c;
    p(){}
    p(char cc, int pp){c = cc; pos = pp;}
};

stack<p> stk;

int answ[100007];

int main()
{
    // freopen("d:\\tst.txt", "r", stdin);

    cin >> tc;
    while(tc-->0)
    {
        cin >> N >> str;
        // clear the stack
        while(stk.size() > 0) stk.pop();
        // reseting the solution array
        fill(answ, answ + N, -1);

        stk.push(p(str[0], 0));

        for(int i = 1; i < N; i++)
        {
            char ax = str[i];

            while(stk.size() > 0 && ax > stk.top().c)
            {
                p tmp = stk.top();

                answ[tmp.pos] = i + 1;

                stk.pop(); // pop it out
            }

            stk.push(p(str[i], i));
        }

        for(int i = 0; i < N; i++)
        {
            if(i > 0)
                cout << " ";
            cout << answ[i];
        }

        cout << "\n";
    }

    return 0;
}
