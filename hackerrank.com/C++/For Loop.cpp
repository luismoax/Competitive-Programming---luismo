#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    // Complete the code.
    vector<string> answ;
    answ.push_back("zero");
    answ.push_back("one");
    answ.push_back("two");
    answ.push_back("three");
    answ.push_back("four");
    answ.push_back("five");
    answ.push_back("six");
    answ.push_back("seven");
    answ.push_back("eight");
    answ.push_back("nine");
    int a, b;
    cin >> a >> b;
    for(int i = a; i <= b; i++)
    {
        if(i <= 9)
            cout << answ[i];
        else if(i % 2) cout << "odd";
        else cout <<"even";
        cout << endl;
    }

    return 0;
}