/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3119 - Anders And The Matrix
	Online Judge: COJ
	Idea: Permutate
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int infinite = 1e9 + 7;
const int lim = 1e6 + 7;

int N;
int arr[16];
int auxArr[16];

int rowSums[4];
int colSums[4];

int D1, D2; // d1 main diag

bool checkCurrentPermutation()
{
    // checking the permutation
    int rw[16];
    int cl[16];
    int d1 = 0, d2 = 0;
    // reseting
    for(int i = 0; i < 16; i++)
        rw[i] = cl[i] = 0;


    // for each row
    for(int r = 0; r < N; r++)
    {
        // for each element of the row
        for(int c = 0; c < N; c++)
        {
            rw[r] += auxArr[r * N + c];
            cl[c] += auxArr[r * N + c];

            if(r == c)
                d1+= auxArr[r * N + c];
            if(c + r == N - 1)
                d2+= auxArr[r * N + c];
        }
    }

    // check
    for(int i = 0; i < N; i++)
        if(rw[i] != rowSums[i] || cl[i] != colSums[i])
            return false;

    return D1 == d1 && D2 == d2;
}



bool taken[lim];
bool flag = false;
void permutateAll(int idx)
{
    if(idx == N * N)
    {
        if(checkCurrentPermutation())
            flag = true;
        return;
    }
    // for each possible
    for(int i = 0; i < N * N; i++)
    {
        if(!taken[i])
        {
            taken[i] = true;
            auxArr[idx] = arr[i];

            permutateAll(idx + 1);

            taken[i] = false;
        }
    }
}

void solve()
{
    cin >> N;
    // reading integers
    for(int i = 0; i < N * N; i++)
        cin >> arr[i];
    // reading sums
    for(int i = 0; i < N; i++)
        cin >> rowSums[i];
    // reading sums in columms
    for(int i = 0; i < N; i++)
        cin >> colSums[i];

    cin >> D1 >> D2;

    permutateAll(0);

    if(flag) cout << "Yes";
    else cout << "No";
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
