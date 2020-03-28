/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3123 - Srednji
    Online Judge: COJ
    Idea: Uff, tricky, but I got to solve it by myself
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


const int lim = 100000 + 5;
int N, B;
int arr[lim];

bool cmp(int a, int b)
{
	return a > b;
}

int cumul[lim];

int query(int i, int j)
{
	if(i <= 0)
		return cumul[j];
	return cumul[j] - cumul[i - 1];
}

void put(int i, int X)
{
	if(i == 0) cumul[i] = X;
	else cumul[i] = X + cumul[i - 1];
}



// TO THE RIGHT
// blocks of even length
int evenLenghtPositive[lim];
int evenLenghtNegative[lim];
// blocks of odd length
int oddLenghtPositive[lim];
int oddLenghtNegative[lim];



void solve()
{
	cin >> N >> B;

	int idx = -1;
	// reading numbers
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];

		if(arr[i] == B)
		{
			idx = i;
			put(i, 0);
		}
		else if(arr[i] > B)
			put(i, 1);
		else put(i, -1);
	}

	// if B wasn't at the collection
	if(idx == -1)
	{
		cout << 0;
		return;
	}

	int cnt = 0;

	// TO THE RIGHT
	for(int i = idx; i < N; i++)
	{
		int len = i - idx + 1;
		int q = query(idx, i); // cumulative sum

		if(q == 0)
		{
			oddLenghtPositive[0]++;
			cnt++;
		}
		if(q > 0)
		{
			if(len % 2 == 0)
				evenLenghtPositive[q]++;
			else oddLenghtPositive[q]++;
		}
		else if(q < 0)
		{
			q*= -1;
			if(len % 2 == 0)
				evenLenghtNegative[q]++;
			else oddLenghtNegative[q]++;
		}
	}
/*
	// printing cumul
	for(int i = 0; i < N; i++)
		cout << cumul[i] <<" ";
	cout << "\n";
*/


	// TO THE LEFT

	for(int j = idx - 1; j >= 0; j--)
	{
		int len = idx - j;
		int q = query(j, idx - 1); // cumulative sum

		// if positive sum
		if(q == 0 && len % 2 == 0)
		{
			cnt+= oddLenghtPositive[0];
		}
		else if(q > 0)
		{
			// if length is even find an odd-lenghted interval with sum = -q
			if(len % 2 == 0)
			{
				cnt+= oddLenghtNegative[q];
			}
			// else if length is ODD find an EVEN-lenghted interval with sum = -q
			else cnt+= evenLenghtNegative[q];
		}
		else if(q < 0)
		{
			q*=-1;
			// if length is even find an odd-lenghted interval with sum = q
			if(len % 2 == 0)
			{
				cnt+= oddLenghtPositive[q];
			}
			// if length is ODD find an EVEN-lenghted interval with sum = q
			else cnt+= evenLenghtPositive[q];
		}

	}
	cout << cnt;

}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("e:\\lmo.in","r",stdin);
}

int main()
{
    open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
