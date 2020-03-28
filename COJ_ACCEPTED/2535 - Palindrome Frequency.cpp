/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 2535 - Palindrome Frequency
    Online Judge: COJ
    Idea: Manacher + Maps
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e3 + 5;

int K;
string str;
char aux[lim << 1];

// >> MANACHER

int manacher[lim << 1]; // DS

void printManacher(int len)
{
	// print manacher ALL
	for(int i = 0; i < len; i++)
		cout << aux[i];
	cout << endl;
	for(int i = 0; i < len; i++)
		cout << manacher[i];
	cout << endl;
}

int pos(int idx)
{
	return ((idx+1) << 1);
}

void buildManacher()
{
	int len = str.length() * 2 + 2;
	// build the auxiliar chain
	aux[0] = '$';
	aux[1] = '#';
	// build the auxiliar string
	for(int i = 0; i < str.length(); i++)
	{
		int p = pos(i);
		aux[p] = str[i];
		aux[p + 1] = '#';
	}
	aux[len] = '#';

	// manacher process
	int idxBest = 1;
	int wingLenght = 0; // wing fartest right

	for(int i = 1; i < len; i++)
	{
		//
		if(idxBest + wingLenght >= i)
		{
			int mirror = (idxBest << 1) - i;
			int tmp = min(manacher[mirror], idxBest + wingLenght - i);
			manacher[i] = tmp;
		}

		while(aux[i + (manacher[i] + 1)] == aux[i - (manacher[i] + 1)])
			manacher[i]++;

		if(i + manacher[i] > idxBest + wingLenght)
		{
			idxBest = i;
			wingLenght = manacher[i];
		}
	}

	// printManacher(len);

}


bool query(int i, int j)
{
	if(j < i)
		swap(i, j);

	int pi = pos(i);
	int pj = pos(j);

	int mid = (pi + pj) >> 1;

	return mid + manacher[mid] >= pj;
}

// map to store frequencies per string
map<string, int> m;

void solve()
{
	cin >> K >> str;
	buildManacher();

	// process
	for(int len = K; len <= str.length(); len++)
	{
		for(int i = 0; i <= str.length() - len; i++)
		{
			string aux = "";
			bool flag = false;
			// if is palindrome
			if(query(i, i + len - 1))
			{
				// check whether is composed by two palindromes
				for(int j = i; j < i + len - 1; j++)
				{
					aux+= str[j];

					if(query(i, j) && query(j + 1, i + len - 1))
						flag = true;
				}
			}
			aux+= str[i + len - 1];

			if(flag)
				m[aux]++;
		}

	}

	string answ = "";
	int freq = 0;
	for(map<string, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		// cout << it->first << "\n";
		if(it-> second > freq)
		{
			freq = it-> second;
			answ = it-> first;
		}
		else if(it-> second == freq && it-> first > answ)
			answ = it-> first;
	}

	if(freq == 0)
	{
		cout << '-';
		return;
	}

	// else print answer
	cout << answ << " " << freq;
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
		freopen("d:\\lmo.in","r",stdin);
	// freopen("d:\\lmo.out","w",stdout);

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
