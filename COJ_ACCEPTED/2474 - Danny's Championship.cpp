#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>

#define pf printf
#define sf scanf
#define ll long long

#define INF 1000000
#define LEN 50000
#define MAXN 300000

    /*
        Author: Luismo
        Problem: 2474 - Danny's Championship
        Online Judge: COJ
        Algorithm: Sorting. Find for each car the points it can earn achieving the first place,
		then if this value is greater or equal than the greatest value achieved by the other
		cars (in ascending order so the ones with better initial points can earn less) it can win
    */

using namespace std;

int N;
int cars[MAXN];

int main()
{
    freopen("d:\\lmo.in", "r", stdin);

    sf("%d",&N);
    // reading data
    for(int i = 0 ; i < N; i++)
        sf("%d",&cars[i]);

    // sorting by points
    sort(cars,cars + N);

    int cnt = 1; //

    bool marks[N]; // marks
    // setting marks to zero
    fill(marks,marks + N, false);


    // the i-th value stores the maximun points
    // that can be achived by car i, that is the previos earned points
    // plus N - i
    int max[N];
    max[N - 1] = cars[N - 1] + 1;

    // processing max values
    for(int i = N - 2; i >= 0; i--)
    {
        if(cars[i] + N - i > max[i + 1])
            max[i] = cars[i] + N - i;
        else max[i] = max[i + 1];
    }

    for(int i = 0 ; i < N - 1; i++)
    {
        bool flag = true; // true if the ith car can win

        // if ith car have the same points of i-1 th car
        // then they can swap so both have equal chances to win
        if(i > 0 && cars[i] == cars[i-1] && marks[i - 1])
            flag = true;
        // if there is a car that can achieve more points
        // the the ith car in the first place
        else if(max[i + 1] > cars[i] + N)
            flag = false;

        if(flag)
        {
            cnt++;
            marks[i] = true;
        }
    }

    pf("%d\n",cnt);

    return 0;
}
